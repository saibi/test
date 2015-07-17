#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLocalServer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

protected:
	virtual void showEvent(QShowEvent *);

private slots:
	void on_pushButton_clicked();
	void handleConnection();
	void slotReadCommand();

private:
	Ui::Widget *ui;

	QLocalServer *server;
	QLocalSocket *socket;

	int m_count;
};

#endif // WIDGET_H
