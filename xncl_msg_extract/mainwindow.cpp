#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>

#include "xnclmessageextractor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->setWindowTitle("Xncl Message Extractor v1.2 20141217");

	m_context = "XML_Menu";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_file_open_clicked()
{
	// open
	QString dirPath = "";
	QString selectedFilter("");
	static const QString filter ("xml (*.xml)");

	m_file_list.clear();
	m_file_list = QFileDialog::getOpenFileNames(this, tr("Open"), dirPath, filter, &selectedFilter);
	if (m_file_list.count() == 0)
		return;

	ui->list_files->clear();
	addFileList();
}

void MainWindow::on_btn_extract_clicked()
{
	if ( ui->radioButton_section->isChecked())
	{
		subExtract(TYPE_SECTION);
		return;
	}
	else if ( ui->radioButton_file->isChecked() )
	{
		subExtract(TYPE_FILENAME);
		return;
	}

	XnclMessageExtractor	xncl_extractor;
	QStringList				message_list;

	xncl_extractor.setCheckTr( ui->checkBox->isChecked());

	for(int i = 0 ; i < ui->list_files->count() ; i++)
	{
		QString file_path = ui->list_files->item(i)->text();

		if(xncl_extractor.loadXML(file_path))
		{
			QStringList new_list = xncl_extractor.getMessageList();
			for(int j = 0 ; j < new_list.count() ; j++)
			{
				if(message_list.contains(new_list.at(j)) == false)
					message_list.append(xncl_extractor.getMessageList());
			}

			ui->list_files->item(i)->setCheckState(Qt::Checked);
		}
		else
		{
			ui->list_files->item(i)->setCheckState(Qt::PartiallyChecked);
		}
	}

	if(message_list.count() != 0)
	{
		QString	file_name = "xml_menu_message.h";

		saveMessageTable(message_list, file_name);

		QMessageBox::information(this, "Extract", file_name + " created.");
	}
}

void MainWindow::addFileList(void)
{
	if(m_file_list.count() != 0)
	{
		ui->list_files->addItems(m_file_list);
	}
}

void MainWindow::saveMessageTable(QStringList &message_list, QString file_name)
{
	QString out_file_path = file_name;
	QFile out_file(out_file_path);

	if (!out_file.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug("[MainWindow::loadXML] Error: file open [%s]",
			   out_file_path.toLocal8Bit().constData());
		return;
	}

	QString data;

	data = "#ifndef _XML_MENU_MESSAGE_H_\n";
	out_file.write(data.toLocal8Bit());
	data = "#define _XML_MENU_MESSAGE_H_\n\n";
	out_file.write(data.toLocal8Bit());

	for(int i = 0 ; i < message_list.count() ; i++)
	{
		data.sprintf("#define A%04d\tQT_TRANSLATE_NOOP(\"", i);
		data += m_context + "\", \"";
		data += message_list.at(i) + "\")\n";
		out_file.write(data.toLocal8Bit());
	}

	data = "\n#endif";
	out_file.write(data.toLocal8Bit());

	out_file.close();
}

void MainWindow::on_btn_exit_clicked()
{
	close();
}

void MainWindow::on_btn_open_work_directory_clicked()
{
	system("explorer .");
}

#include <QInputDialog>

void MainWindow::on_btn_change_context_clicked()
{
	QString str = QInputDialog::getText(this, "Change Context", "Context", QLineEdit::Normal, m_context);

	if ( !str.isEmpty() )
		m_context = str;

	qDebug("Context = %s", qPrintable(m_context));
}

void MainWindow::subExtract(int type)
{
	XnclMessageExtractor	xncl_extractor;
	QMap < QString, QStringList > map;

	xncl_extractor.setCheckTr( ui->checkBox->isChecked());

	for(int i = 0 ; i < ui->list_files->count() ; i++)
	{
		QString file_path = ui->list_files->item(i)->text();

		if(xncl_extractor.loadXML(file_path))
		{
			map.insert( (type == TYPE_SECTION ) ? xncl_extractor.getSectionString() : QFileInfo(file_path).baseName(), xncl_extractor.getMessageList());
			ui->list_files->item(i)->setCheckState(Qt::Checked);
		}
		else
		{
			ui->list_files->item(i)->setCheckState(Qt::PartiallyChecked);
		}
	}

	if ( map.count() <= 0 )
	{
		qDebug("emptry");
		return;
	}


	QString out_file_path = "xml_menu_message.h";
	QFile out_file(out_file_path);

	if (!out_file.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug("[MainWindow::loadXML] Error: file open [%s]",
			   out_file_path.toLocal8Bit().constData());
		return;
	}

	QString data;

	data = "#ifndef _XML_MENU_MESSAGE_H_\n";
	out_file.write(data.toLocal8Bit());
	data = "#define _XML_MENU_MESSAGE_H_\n\n";
	out_file.write(data.toLocal8Bit());

	QList <QString> keyList = map.keys();

	int id = 0;
	for ( int k = 0 ; k < keyList.count(); k++)
	{
		const QStringList message_list = map.value(keyList.at(k));

		for(int i = 0 ; i < message_list.count() ; i++)
		{
			data.sprintf("#define A%04d\tQT_TRANSLATE_NOOP(\"", id++);
			data += "XML_" + keyList.at(k) + "\", \"";
			data += message_list.at(i) + "\")\n";
			out_file.write(data.toLocal8Bit());
		}
	}

	data = "\n#endif";
	out_file.write(data.toLocal8Bit());

	out_file.close();

	QMessageBox::information(this, "Extract", out_file_path + " created.");

}

void MainWindow::updateContextBtn()
{
	if ( ui->radioButton_fixed->isChecked() )
		ui->btn_change_context->setEnabled(true);
	else
		ui->btn_change_context->setEnabled(false);
}


void MainWindow::on_radioButton_fixed_clicked()
{
	updateContextBtn();
}

void MainWindow::on_radioButton_file_clicked()
{
	updateContextBtn();
}

void MainWindow::on_radioButton_section_clicked()
{
	updateContextBtn();
}
