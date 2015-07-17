#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLocalSocket>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();

private slots:
	void on_pushButton_exit_clicked();

	void displayError(QLocalSocket::LocalSocketError socketError);

	void on_pushButton_send_clicked();

	void slotConnected();

	void on_pushButton_enable_clicked();

	void on_pushButton_disable_clicked();

private:
	Ui::Dialog *ui;

	QLocalSocket *socket;
};

#endif // DIALOG_H
