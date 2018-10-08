#include "dlgPCD2TXT.h"
#include "ui_dlgPCD2TXT.h"

#include <QFileDialog>
#include <QString>
#include <QLineEdit>
#include <QToolButton>
#include <QPushButton>
#include <QProgressBar>

dlgPCD2TXT::dlgPCD2TXT(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgPCD2TXT();
	ui->setupUi(this);
	this->setFixedSize(550, 200);


	ui->progressBar->setValue(0);

	thread = new QThread(this);
	convertThread = new ThreadPCD2TXT;
	convertThread->moveToThread(thread);

	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(toolClicked1()));
	connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(toolClicked2()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));
	connect(convertThread, &ThreadPCD2TXT::finishConvert, this, &dlgPCD2TXT::dealSignalFinished);
	connect(convertThread, &ThreadPCD2TXT::changeBar, this, &dlgPCD2TXT::setBarValue);
	connect(this, &dlgPCD2TXT::startConvert, convertThread, &ThreadPCD2TXT::runTask);

}

dlgPCD2TXT::~dlgPCD2TXT()
{
	delete ui;
}

void dlgPCD2TXT::toolClicked1(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "PCD(*.pcd)");
	ui->lineEdit->setText(path);
	convertThread->SRC_PATH = path.toStdString();
}

void dlgPCD2TXT::toolClicked2(){
	QString path = QFileDialog::getSaveFileName(this, QString(), QString("C:/"), "TXT(*.txt)");
	ui->lineEdit_2->setText(path);
	convertThread->DEST_PATH = path.toStdString();
}

void dlgPCD2TXT::convertButton(){
	if (ui->lineEdit->text() == "" ||
		ui->lineEdit_2->text() == "")
		return;

	thread->start();
	emit startConvert();
	ui->pushButton->setEnabled(false);
}

void dlgPCD2TXT::dealSignalFinished(){
	thread->quit();
	thread->wait();
	ui->progressBar->setValue(100);
	ui->progressBar->setFormat(QString::fromLocal8Bit("转换完成"));
}

void dlgPCD2TXT::setBarValue(int value){
	if (value == 999){
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在扫描文件..."));
		return;
	}
	ui->progressBar->setValue(value);
	ui->progressBar->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(value, 'd', 0)));
}

void dlgPCD2TXT::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}