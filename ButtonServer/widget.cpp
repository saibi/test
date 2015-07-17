#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <qlocalsocket.h>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	m_count = 0;

	socket = 0;
	server = new QLocalServer(this);
	if (!server->listen("ButtonServer")) {
		QMessageBox::critical(this, tr("Button Server"),
							  tr("Unable to start the server: %1.")
							  .arg(server->errorString()));
		close();
		return;
	}

	connect(server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
}

Widget::~Widget()
{
	delete server;
	delete ui;
}

void Widget::showEvent(QShowEvent *)
{
	move(100, 100);
}

void Widget::on_pushButton_clicked()
{
	++m_count;

	qDebug("[Widget::on_pushButton_clicked()] %d", m_count);

	if ( m_count > 10 )
		close();
}

void Widget::slotReadCommand()
{
	qDebug("[Widget::slotReadCommand()]");

	if ( socket )
	{
		connect(socket, SIGNAL(disconnected()),
				socket, SLOT(deleteLater()));

		QDataStream in(socket);
		in.setVersion(QDataStream::Qt_4_7);

		qDebug("[Widget::slotReadCommand()] bytesAvailable = %d", socket->bytesAvailable());

		QString cmd;

		in >> cmd;

		qDebug("[Widget::slotReadCommand()] cmd = [%s]", qPrintable(cmd));
		socket = 0;
	}
}

void Widget::handleConnection()
{
	qDebug("[Widget::handleConnection()]");

	socket = server->nextPendingConnection();

	if ( socket )
		connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadCommand()));
}
