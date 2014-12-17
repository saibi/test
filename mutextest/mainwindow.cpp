#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "notification.h"
#include "sdobserver.h"
#include "sdobserver2.h"
#include "sdobserver3.h"

#include <qmath.h>

#include "dataconverter.h"

#include "motorhandler.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	for (int i = 0; i < 1440; i++)
	{
		m_circleData.append( QPointF( 25.0 * qSin( 2 *3.14 * i / 1440.0), 25.0 * qCos( 2 * 3.14 * i / 1440.0 )) );
	}

	connect(&SdObserver::instance(), SIGNAL(signalSdMounted(QString)), this, SLOT( slot_sdMounted(QString)));
	connect(&SdObserver::instance(), SIGNAL(signalSdUnmounted()), this, SLOT( slot_sdUnmounted()));

	connect(&SdObserver2::instance(), SIGNAL(signalSdMounted()), this, SLOT( slot_sdMounted2()));
	connect(&SdObserver2::instance(), SIGNAL(signalSdUnmounted()), this, SLOT( slot_sdUnmounted2()));

	connect(&SdObserver3::instance(), SIGNAL(signalSdMounted()), this, SLOT( slot_sdMounted3()));
	connect(&SdObserver3::instance(), SIGNAL(signalSdUnmounted()), this, SLOT( slot_sdUnmounted3()));

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_close_clicked()
{
	qDebug("[UI] [MainWindow::on_pushButton_close_clicked]");
	QApplication::quit();
}

void MainWindow::on_pushButton_hello_clicked()
{
	qDebug("[UI] [MainWindow::on_pushButton_hello_clicked]");

	Notification::instance().notify(tr("Hello"));
}

void MainWindow::on_pushButton_world_clicked()
{
	qDebug("[UI] [MainWindow::on_pushButton_world_clicked]");
	Notification::instance().notify(tr("World"), 10);
}

void MainWindow::on_pushButton_clicked()
{
	static bool flag = false;
	qDebug("[UI] [MainWindow::on_pushButton_clicked]");

	Notification::instance().notify(flag ? tr("TRUE") : tr("FALSE"));

	flag = !flag;
}

void MainWindow::on_pushButton_calc_clicked()
{
	qDebug("[UI] [MainWindow::on_pushButton_calc_clicked]");


	Notification::instance().notify("calc start");

	QPolygonF list = m_circleData;

	qDebug("org");
	DataConverter::dumpPolygon(list);

	DataConverter::digitalPattern_Scale(list, 52.0, 52.0);

	qDebug("scale 2.0");
	DataConverter::dumpPolygon(list);


	DataConverter::digitalPattern_Scale(list, 50.0, 50.0);

	qDebug("scale -2.0");
	DataConverter::dumpPolygon(list);


	Notification::instance().notify("calc end");
}




void MainWindow::slot_sdMounted(QString mountPath)
{
	qDebug("[UI] [MainWindow::slot_sdMounted] %s", qPrintable(mountPath));

	QPolygonF list = m_circleData;
	DataConverter::digitalPattern_ScaleOneSide(list, 10.0 , DataConverter::DP_ONE_SIDE_SCALE_DOWN);

	Notification::instance().notify(tr("SD Mounted"), 3);
	MotorHandler::instance().test();
}

void MainWindow::slot_sdUnmounted()
{
	qDebug("[UI] [MainWindow::slot_sdUnMounted]");
	Notification::instance().notify(tr("SD Unmounted"));

	QPolygonF list = m_circleData;
	DataConverter::digitalPattern_ScaleOneSide(list, -1.0 , DataConverter::DP_ONE_SIDE_SCALE_LEFT);
	MotorHandler::instance().test();
}


void MainWindow::slot_sdMounted2()
{
	qDebug("[UI] [MainWindow::slot_sdMounted2");

	QPolygonF list = m_circleData;
	DataConverter::digitalPattern_ScaleOneSide(list, 1.0 , DataConverter::DP_ONE_SIDE_SCALE_UP);
	MotorHandler::instance().test();
	Notification::instance().notify(tr("SD Mounted2"), 10);

	DataConverter::digitalPattern_ScaleOneSide(list, 1.0 , DataConverter::DP_ONE_SIDE_SCALE_DOWN);

}

void MainWindow::slot_sdUnmounted2()
{
	qDebug("[UI] [MainWindow::slot_sdUnMounted2]");
	Notification::instance().notify(tr("SD Unmounted2"), 10);

	MotorHandler::instance().test();
	QPolygonF list = m_circleData;
	DataConverter::digitalPattern_ScaleOneSide(list, 1.0 , DataConverter::DP_ONE_SIDE_SCALE_UP);

}

void MainWindow::slot_sdMounted3()
{
	qDebug("[UI] [MainWindow::slot_sdMounted3");
	Notification::instance().notify(tr("SD Mounted3 - start"), 1);
	MotorHandler::instance().test();
	Notification::instance().notify(tr("SD Mounted3 - mid"), 1);
	QApplication::processEvents();
	Notification::instance().notify(tr("SD Mounted3 - end"), 1);

}

void MainWindow::slot_sdUnmounted3()
{
	qDebug("[UI] [MainWindow::slot_sdUnMounted3]");
	MotorHandler::instance().test();

	Notification::instance().notify(tr("SD Unmounted3"), 1);

	QPolygonF list = m_circleData;
	DataConverter::digitalPattern_Rotate(list, 30);

}

