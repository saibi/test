#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QByteArray test;

	test.append(49);
	test.append(46);
	test.append(49);
	test.append(56);
	test.append(48);
	test.append(48);
	test.append('\n');
	test.append((char)0);
	test.append(char(0));
	test.append(char(0));
	test.append(char(0));
	test.append(char(0));


	qDebug("org [%s], size %d", test.constData(), test.size());

	QByteArray test3 = test.simplified();

	qDebug("simplified [%s] size %d", test3.constData(), test3.size());


	QByteArray test4 = test.trimmed();

	qDebug("trimmed [%s] size %d", test4.constData(), test4.size());

	float val = test3.toFloat();

	qDebug("value = %f", val);

	if ( test.contains('\n'))

	{
		QByteArray test2 = test.left( test.indexOf('\n'));



		qDebug("%d test2 [%s]", test.indexOf(char(0)), test2.constData());
	}

}

MainWindow::~MainWindow()
{
	delete ui;
}
