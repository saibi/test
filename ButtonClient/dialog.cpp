#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	socket = new QLocalSocket(this);


//    connect(hostLineEdit, SIGNAL(textChanged(QString)),
//            this, SLOT(enableGetFortuneButton()));
//    connect(getFortuneButton, SIGNAL(clicked()),
//            this, SLOT(requestNewFortune()));
//    connect(socket, SIGNAL(readyRead()), this, SLOT(readFortune()));

	connect(socket, SIGNAL(error(QLocalSocket::LocalSocketError)),
			this, SLOT(displayError(QLocalSocket::LocalSocketError)));

	connect(socket, SIGNAL(connected()), this, SLOT(slotConnected()));

}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::on_pushButton_exit_clicked()
{
	this->accept();
}

void Dialog::displayError(QLocalSocket::LocalSocketError socketError)
{
	switch (socketError) {
	case QLocalSocket::ServerNotFoundError:
		QMessageBox::information(this, tr("Button Client"),
								 tr("The host was not found. Please check the "
									"host name and port settings."));
		break;

	case QLocalSocket::ConnectionRefusedError:
		QMessageBox::information(this, tr("Button Client"),
								 tr("The connection was refused by the peer. "
									"Make sure the fortune server is running, "
									"and check that the host name and port "
									"settings are correct."));
		break;

	case QLocalSocket::PeerClosedError:
		break;

	default:
		QMessageBox::information(this, tr("Button Client"),
								 tr("The following error occurred: %1.")
								 .arg(socket->errorString()));
	}

	ui->pushButton_send->setEnabled(true);
}

void Dialog::on_pushButton_send_clicked()
{
	qDebug("Dialog::on_pushButton_send_clicked()");

	ui->pushButton_send->setEnabled(false);

	socket->abort();
	socket->connectToServer("ButtonServer");

	qDebug("Dialog::on_pushButton_send_clicked() end");

}

void Dialog::slotConnected()
{
	qDebug("Dialog::slotConnected()");
	ui->pushButton_send->setEnabled(true);

	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);

	out.setVersion(QDataStream::Qt_4_7);
	out << ui->lineEdit_cmd->text();

	socket->write(block);
	socket->flush();
	socket->disconnectFromServer();

	qDebug("Dialog::slotConnected() end");
}

void Dialog::on_pushButton_enable_clicked()
{
	ui->pushButton_send->setEnabled(true);
}

void Dialog::on_pushButton_disable_clicked()
{
	ui->pushButton_send->setEnabled(false);
}
