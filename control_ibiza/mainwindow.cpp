#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "buttoncontroller.h"

#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->groupBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
	delete ui;

	ButtonController::instance().disconnectFromServer();
}

void MainWindow::on_pushButton_connect_clicked()
{
	qDebug("[UI] [MainWindow::on_pushButton_connect_clicked]");

	if ( ui->pushButton_connect->isChecked() )
	{
		if ( ui->lineEdit_socketName->text().trimmed().isEmpty() )
		{
			qDebug("[MainWindow::on_pushButton_connect_clicked] empty socket name");

			ui->pushButton_connect->setChecked(false);
			return;
		}

		ButtonController::instance().connectToServer(ui->lineEdit_socketName->text().trimmed());

		// wait till connected
		QTime t;

		t.start();

		while( t.elapsed() < 1 * 1000 )
		{
			if ( ButtonController::instance().isConnected() )
			{
				qDebug("[MainWindow::on_pushButton_connect_clicked] connected");
				ui->groupBox->setEnabled(true);
				return;
			}
		}
		ui->pushButton_connect->setChecked(false);
		qDebug("[MainWindow::on_pushButton_connect_clicked] connection error");
	}
	else
	{
		ButtonController::instance().disconnectFromServer();
		ui->groupBox->setEnabled(false);
	}
}

void MainWindow::on_lineEdit_command_returnPressed()
{
	qDebug("[UI] [MainWindow::on_lineEdit_command_returnPressed] %s", qPrintable(ui->lineEdit_command->text().trimmed()));

	ButtonController::instance().sendCommand(ui->lineEdit_command->text().trimmed());
}
