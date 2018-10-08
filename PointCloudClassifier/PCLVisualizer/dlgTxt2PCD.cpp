#include "dlgTxt2PCD.h"
#include "ui_dlgTxt2PCD.h"

#include <QFileDialog>
#include <QString>
#include <QLineEdit>
#include <QToolButton>
#include <QPushButton>
#include <QProgressBar>


dlgTxt2PCD::dlgTxt2PCD(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgTxt2PCD();
	ui->setupUi(this);
	this->setFixedSize(550, 200);

	ui->progressBar->setValue(0);

	thread = new QThread(this);
	convertThread = new ThreadTXT2PCD;
	convertThread->moveToThread(thread);

	connect(ui->toolBtn1, SIGNAL(clicked()), this, SLOT(toolClicked1()));
	connect(ui->toolBtn2, SIGNAL(clicked()), this, SLOT(toolClicked2()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));
	connect(convertThread, &ThreadTXT2PCD::changeBar, this, &dlgTxt2PCD::setBar);
	connect(convertThread, &ThreadTXT2PCD::finishConvert, this, &dlgTxt2PCD::dealSignalFinished);
	connect(this, &dlgTxt2PCD::startConvert, convertThread, &ThreadTXT2PCD::runTask);
}

dlgTxt2PCD::~dlgTxt2PCD()
{
	delete ui;
}

void dlgTxt2PCD::toolClicked1(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "TXT(*.txt)");
	ui->lineEdit->setText(path);
	convertThread->SRC_PATH = path.toStdString();
}

void dlgTxt2PCD::toolClicked2(){
	QString path = QFileDialog::getSaveFileName(this, QString(), QString("C:/"), "PCD(*.pcd)");
	ui->lineEdit_2->setText(path);
	convertThread->DEST_PATH = path.toStdString();
}

void dlgTxt2PCD::convertButton(){
	if (ui->lineEdit->text() == "" ||
		ui->lineEdit_2->text() == "")
		return;

	ui->progressBar->setFormat(QString::fromLocal8Bit("正在扫描文件..."));

	thread->start();
	emit startConvert();
	ui->pushButton->setEnabled(false);
}

void dlgTxt2PCD::dealSignalFinished(){
	thread->quit();
	thread->wait();
	ui->progressBar->setValue(100);
	ui->progressBar->setFormat(QString::fromLocal8Bit("转换完成"));
}

void dlgTxt2PCD::setBar(int value){
	if (value == 999 ){
		ui->progressBar->setFormat(QString::fromLocal8Bit("合并中..."));
		return;
	}

	ui->progressBar->setValue(value);
	ui->progressBar->setFormat(QString::fromLocal8Bit("当前进度为：%1%").arg(QString::number(value, 'd', 0)));

}

void dlgTxt2PCD::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}