#include "sdobserver.h"

#include <QMutexLocker>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QProcess>

#define SD_CHECK_MSEC 1000

SdObserver::SdObserver(QObject *parent) :
    QThread(parent),
    _mutex(QMutex::Recursive)
{
    _stopFlag = false;
}

bool SdObserver::startObserver(const QString &sdMountPath)
{
    qDebug("[SdObserver::startObserver] Start.");

    if (this->isRunning())
    {
        stopObserver();
    }

    //
    QFileInfo mountPathFileInfo(sdMountPath);

    if (mountPathFileInfo.exists())
    {
        // exist
        if (!mountPathFileInfo.isDir())
        {
			qDebug("[SdObserver::startObserver] Path: [%s] exists, but is not directory.",
                      sdMountPath.toLocal8Bit().constData());
            return false;
        }
    }
    else
    {
        // not exist - mkpath
        QDir mountDir;
        if (!mountDir.mkpath(sdMountPath))
        {
			qDebug("[SdObserver::startObserver] Path: [%s] not exists, and can not make path.",
                      sdMountPath.toLocal8Bit().constData());
            return false;
        }
    }

    _sdMountPath = sdMountPath;

	//
	QMutexLocker locker(&_mutex);

	_stopFlag = false;

    start();

    qDebug("[SdObserver::startObserver] Done.");

    return true;
}

void SdObserver::stopObserver()
{
    QMutexLocker locker(&_mutex);

    _stopFlag = true;

    locker.unlock();

    wait();
}

bool SdObserver::isMounted()
{
    QMutexLocker locker(&_mutex);

    if (!this->isRunning())
        return false;

//#ifndef __arm__
//	return true;
//#else
	return _mountFlag | _usb_mount_flag;
//#endif
}

QString SdObserver::getMountPath()
{
	QMutexLocker locker(&_mutex);

	return _sdMountPath;
}

void SdObserver::run()
{
    qDebug("[SdObserver::run] Start.");

    // check already mounted sd card & umount
    // TODO

    //
    bool sdFlag;

    // reset flag
    _sdFlag = false;
    _mountFlag = false;
    _errorCount = 0;

	bool usb_sd_flag;
	_usb_sd_flag = false;
	_usb_mount_flag = false;

    while (1)
    {
        if (_stopFlag)
            break;

        sdFlag = sdExists();

        if (sdFlag != _sdFlag)
        {
            if (sdFlag)
            {
                qDebug("[SdObserver::run] SD inserted. - [%s]", _mmcblkFileName.toLocal8Bit().constData());

				// 기존 SD 카드 리더를 통해 mount 수행 시, usb 측을 반드시 umount
				if(_usb_mount_flag)
				{
					usbAutoUnmount();

					qDebug("[SdObserver::run] usb sd unmounted.");
					emit signalSdUnmounted();
					_usb_mount_flag = false;
					_usb_sd_flag = false;

					this->msleep(SD_CHECK_MSEC);
					continue;
				}

                // inserted
                if (!autoMount())
                {
                    _errorCount++;
					qDebug("[SdObserver::run] Failed to autoMount - Error Count: [%d]", _errorCount);

					if ( _errorCount == 10 || _errorCount == 20 || _errorCount == 30 )
						emit signalSdMountError();

                    if (_errorCount > 3)
                        this->msleep(SD_CHECK_MSEC);

                    continue;
                }

                _errorCount = 0;

                emit signalSdMounted(_sdMountPath);

                _mountFlag = true;
            }
            else
            {
                qDebug("[SdObserver::run] SD removed.");

                // removed
                if (!autoUnmount())
                {
                    _errorCount++;
					qDebug("[SdObserver::run] Failed to autoUnmount - Error Count: [%d]", _errorCount);

                    if (_errorCount > 3)
                        this->msleep(SD_CHECK_MSEC);

                    continue;
                }

                _errorCount = 0;

                emit signalSdUnmounted();

                _mountFlag = false;
            }

            _sdFlag = sdFlag;
        }
		else if(sdFlag == false) // 기존 SD 카드 리더기 상태 변화가 없음 + 기존 SD 카드 리더기에 SD 카드가 없음
		{
			if(usbReaderConnected())
			{
				usb_sd_flag = usbSdExists();
				if(usb_sd_flag != _usb_sd_flag)
				{
					if(usb_sd_flag)
					{
						qDebug("[SdObserver::run] USB SD inserted. - [%s]", qPrintable(_usbsd_dev_name));

						// inserted
						if (!usbAutoMount())
						{
							qDebug("[SdObserver::run] Failed to usbAutoMount");
							_errorCount++;

							if ( _errorCount == 10 || _errorCount == 20 || _errorCount == 30 )
								emit signalSdMountError();

							this->msleep(SD_CHECK_MSEC);
							continue;
						}

						_errorCount = 0;

						emit signalSdMounted(_sdMountPath);
						_usb_mount_flag = true;
					}
					else
					{
						qDebug("[SdObserver::run] USB SD removed.");

						// removed
						if (!usbAutoUnmount())
						{
							qDebug("[SdObserver::run] Failed to autoUnmount");
							this->msleep(SD_CHECK_MSEC);
							continue;
						}

						emit signalSdUnmounted();
						_usb_mount_flag = false;
						_errorCount = 0;
					}

					_usb_sd_flag = usb_sd_flag;
				}
			}
		}

        this->msleep(SD_CHECK_MSEC);
    }

    qDebug("[SdObserver::run] Stop.");
}

#include <QTime>

bool SdObserver::sdExists()
{
    //qDebug("[SdObserver::sdExists] Start.");

	if ( QTime::currentTime().second() < 10 )
		return true;
	else if ( QTime::currentTime().second() < 20 )
		return false;
	else if ( QTime::currentTime().second() < 30 )
		return true;
	else if ( QTime::currentTime().second() < 40 )
		return false;
	else if ( QTime::currentTime().second() < 50 )
		return true;

	return false;
}

bool SdObserver::autoMount()
{
    qDebug("[SdObserver::autoMount] Start.");

    if (!autoUnmount())
    {
		qDebug("[SdObserver::autoMount] Failed to autoUnmount");
        return false;
    }

	qDebug("[SdObserver::autoMount] Done. - OK");
	return true;
}

bool SdObserver::autoUnmount()
{
    qDebug("[SdObserver::autoUnmount] Start.");

    qDebug("[SdObserver::autoUnmount] Done. - OK");

    return true;
}

bool SdObserver::usbReaderConnected()
{
	return false;
}

bool SdObserver::usbSdExists()
{
	return false;
}

bool SdObserver::checkFdiskResultContains(QString contains)
{
	Q_UNUSED(contains);

	return false;
}

QString SdObserver::getPartitionName(QString start_str, QString end_str)
{
	QString partition_name = "";

	Q_UNUSED(start_str);
	Q_UNUSED(end_str);

	return partition_name;
}

bool SdObserver::usbAutoMount()
{
	qDebug("[SdObserver::usbAutoMount] Start.");

	if (!usbAutoUnmount())
	{
		qDebug("[SdObserver::usbAutoMount] Failed to usbAutoUnmount");
		return false;
	}

	qDebug("[SdObserver::usbAutoMount] Failed to mount - Check Failed");

	return false;
}

bool SdObserver::usbAutoUnmount()
{
	qDebug("[SdObserver::usbAutoUnmount] Start.");

	qDebug("[SdObserver::usbAutoUnmount] Done. - OK");
	return true;
}
