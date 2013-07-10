#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	QString verStr = ui->lineEdit_motorVer->text().section("_", 0, 0);

	int major = verStr.section(".", 0, 0).toInt();
	int minor = verStr.section(".", 1, 1).toInt();
	QString patchStr = verStr.section(".", 2, 2);

	int patch = patchStr.section(QRegExp("\\D"), 0, 0).toInt();

	QMessageBox::information(this, "test", QString("major %1\nminor %2\npatch %3").arg(major).arg(minor).arg(patch), QMessageBox::Ok);


}
