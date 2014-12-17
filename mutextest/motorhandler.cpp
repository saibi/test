#include "motorhandler.h"
#include "notification.h"
#include "dataconverter.h"
#include <QApplication>

MotorHandler::MotorHandler(QObject *parent) :
	QObject(parent),
	m_mutex(QMutex::Recursive)
{
}

MotorHandler::~MotorHandler()
{
}


void MotorHandler::test()
{
	QMutexLocker locker(&m_mutex);

	qDebug("[MotorHandler::test] start");

	Notification::instance().notify("start");

	for (int i = 0 ; i < 10; i++)
	{
		qDebug("#%d prime = %d", i, DataConverter::countPrimes(100000));
		QApplication::processEvents();
	}

	QApplication::processEvents();
	Notification::instance().notify("end");
}
