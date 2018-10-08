#include "dlgBinarySignal.h"
#include "ui_dlgBinarySignal.h"

#include <QFileDialog>
#include <QString>
#include <QLineEdit>
#include <QToolButton>
#include <QPushButton>
#include <QProgressBar>

dlgBinarySignal::dlgBinarySignal(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgBinarySignal();
	ui->setupUi(this);
	
	thread = new QThread(this);
	convertThread = new ThreadBinarySignal;
	convertThread->moveToThread(thread);

	this->setFixedSize(600, 300);
	ui->progressBar->setValue(0);

	connect(ui->toolButton1, SIGNAL(clicked()), this, SLOT(toolClicked1()));
	connect(ui->toolButton2, SIGNAL(clicked()), this, SLOT(toolClicked2()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));
	connect(this, &dlgBinarySignal::startThread, convertThread, &ThreadBinarySignal::runTask);
	connect(convertThread, &ThreadBinarySignal::finishConvert, this, &dlgBinarySignal::finishTask);
}

dlgBinarySignal::~dlgBinarySignal()
{
	delete ui;
}

void dlgBinarySignal::toolClicked1(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "PCD(*.pcd)");
	ui->lineEdit1->setText(path);
	convertThread->SRC_PATH = path.toStdString();
}

void dlgBinarySignal::toolClicked2(){
	QString path = QFileDialog::getSaveFileName(this, QString(), QString("C:/"), "TXT(*.txt)");
	ui->lineEdit2->setText(path);
	convertThread->DEST_PATH = path.toStdString();
}

void dlgBinarySignal::finishTask(){

}

void dlgBinarySignal::convertButton(){
	//判断需要几个阈值


	thread->start();
	emit startThread();
}

void dlgBinarySignal::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}
