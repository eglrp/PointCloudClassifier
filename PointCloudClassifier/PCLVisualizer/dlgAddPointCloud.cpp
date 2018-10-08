///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-9 22:56
///		
///		这段代码实现了点云文件的打开操作
///		
///		目前只支持 XYZRGB.pcd  文件的读取操作，以后会兼容其他格式的数据类型
///
///##############################################################

#include "dlgAddPointCloud.h"
#include "ui_dlgAddPointCloud.h"

#include <QFileDialog>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QFileInfo>
#include <QProgressBar>

dlgAddPointCloud::dlgAddPointCloud(QWidget *parent, ThreadLoadingCloudPoints * thread)
: QDialog(parent)
{
	ui = new Ui::dlgAddPointCloud();
	ui->setupUi(this);

	this->setFixedSize(600, 150);
	ui->progressBar->setValue(0);
	ui->progressBar->setAlignment(Qt::AlignCenter);

	connect(ui->toolButton, &QAbstractButton::clicked, [=](){
		QString path;
		path = QFileDialog::getOpenFileName(this, QString(), QString(), "TXT(*.txt) ;; PCD(*.pcd)");
		ui->lineEdit->setText(path);
		thread->fileName = QFileInfo(path).fileName();
		thread->pointCloudPath = ui->lineEdit->text();
	});

	connect(ui->pushButton, &QAbstractButton::clicked, [=](){
		if (ui->lineEdit->text().isEmpty() == true)
			return;
		thread->start();
	});

	connect(this, &dlgAddPointCloud::destroyed, [=](){
		if (thread->isRunning())
			return;
		thread->deleteLater();
		this->close();
	});
}

dlgAddPointCloud::~dlgAddPointCloud()
{
	delete ui;
}

void dlgAddPointCloud::setValue(int value){
	ui->progressBar->setFormat(QString::fromLocal8Bit("加载进度 %1%").arg(value));
	ui->progressBar->setValue(value);
	if (value == 100)
		this->close();
}

void dlgAddPointCloud::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}