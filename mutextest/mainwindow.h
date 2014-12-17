#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_close_clicked();

	void on_pushButton_hello_clicked();

	void on_pushButton_world_clicked();

	void on_pushButton_clicked();

	void on_pushButton_calc_clicked();


	void slot_sdMounted(QString mountPath);
	void slot_sdUnmounted();

	void slot_sdMounted2();
	void slot_sdUnmounted2();

	void slot_sdMounted3();
	void slot_sdUnmounted3();


private:
	Ui::MainWindow *ui;

	QPolygonF m_circleData;
};

#endif // MAINWINDOW_H
