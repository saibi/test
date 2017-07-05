#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "packet.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	//ui->textEdit->setText(QString("16 test %1").arg(int(3), 2, 16, QChar('0')));

	connect(ui->pushButton_close, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_pushButton_check_clicked()
{
	Packet p(ui->textEdit->toPlainText());
	ui->textEdit_result->setText(p.getAsFormatString());

	ui->lineEdit->setText(QString("%1 (CRC=%2)").arg(p.m_crcVal).arg(p.m_crcStr));
}
