#include "dlgPCDBinary2PCDAscii.h"
#include "ui_dlgPCDBinary2PCDAscii.h"

#include <QString>
#include <QFileDialog>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QProgressBar>

dlgPCDBinary2PCDAscii::dlgPCDBinary2PCDAscii(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgPCDBinary2PCDAscii();
	ui->setupUi(this);

	this->setFixedSize(550, 200);

	ui->progressBar->setValue(0);

	thread = new QThread(this);
	convertThread = new ThreadPCD2PCD;
	convertThread->moveToThread(thread);

	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(toolClicked1()));
	connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(toolClicked2()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));
	connect(this, &dlgPCDBinary2PCDAscii::startConvert, convertThread, &ThreadPCD2PCD::runTask);
	connect(convertThread, &ThreadPCD2PCD::finishConvert, this, &dlgPCDBinary2PCDAscii::dealSignalFinished);

}

dlgPCDBinary2PCDAscii::~dlgPCDBinary2PCDAscii()
{
	delete ui;
}

void dlgPCDBinary2PCDAscii::toolClicked1(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "PCD(*.pcd)");
	ui->lineEdit->setText(path);
	convertThread->SRC_PATH = path.toStdString();
}

void dlgPCDBinary2PCDAscii::toolClicked2(){
	QString path = QFileDialog::getSaveFileName(this, QString(), QString("C:/"), "PCD(*.pcd)");
	ui->lineEdit_2->setText(path);
	convertThread->DEST_PATH = path.toStdString();
}

void dlgPCDBinary2PCDAscii::convertButton(){
	if (ui->lineEdit->text() == "" ||
		ui->lineEdit_2->text() == "")
		return;

	thread->start();
	emit startConvert();
	ui->pushButton->setEnabled(false);
	ui->progressBar->setFormat(QString::fromLocal8Bit("转换中..."));
}

void dlgPCDBinary2PCDAscii::dealSignalFinished(){
	thread->quit();
	thread->wait();
	ui->progressBar->setValue(100);
	ui->progressBar->setFormat(QString::fromLocal8Bit("转换完成"));
}

void dlgPCDBinary2PCDAscii::setBarValue(int value){
	ui->progressBar->setValue(value);
	ui->progressBar->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(value, 'd', 0)));
}

void dlgPCDBinary2PCDAscii::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}

