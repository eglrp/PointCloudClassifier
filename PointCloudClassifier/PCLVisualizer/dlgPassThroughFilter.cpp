///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-9 22:56
///
///		这部分代码是直通滤波的窗口
///		
///##############################################################

#include "dlgPassThroughFilter.h"
#include "ui_dlgPassThroughFilter.h"
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QMessageBox>

dlgPassThroughFilter::dlgPassThroughFilter(LY::XYZRGBCloud & selectedRgbCloud, QWidget *parent)
: cloud(selectedRgbCloud), QDialog(parent)
{
	ui = new Ui::dlgPassThroughFilter();
	ui->setupUi(this);

	this->setFixedSize(600, 300);
	ui->progressBar->setValue(0);

	thread = new QThread(this);
	convertThread = new ThreadPassThrough;
	convertThread->moveToThread(thread);

	//设置默认选项
	ui->rbFiledX->setChecked(true);
	ui->rbSaveFiled->setChecked(true);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));
	connect(this, &dlgPassThroughFilter::startPass, convertThread, &ThreadPassThrough::runTask);
}

dlgPassThroughFilter::~dlgPassThroughFilter()
{
	delete ui;
}

void dlgPassThroughFilter::convertButton(){
	//判断
	if (ui->lineEditMin->text() == QString("") ||
		ui->lineEditMax->text() == QString("") ||
		ui->lineEditMin->text().toFloat() >= ui->lineEditMax->text().toFloat()){
		QMessageBox::warning(this, "ERROR", "Your input is error!");

		return;
	}
	
	std::string fild, oType;
	float dMin, dMax;

	if (ui->rbFiledX->isChecked())
		fild = "x";  //注意是小写
	else if (ui->rbFiledY->isChecked())
		fild = "y";
	else
		fild = "z";

	//保留 / 删除 范围内点云
	if (ui->rbSaveFiled->isChecked())
		oType = "SAVE";
	else
		oType = "DELETE";

	//获取区间
	QString qStr;
	qStr = ui->lineEditMin->text(); dMin = qStr.toFloat();
	qStr = ui->lineEditMax->text(); dMax = qStr.toFloat();

	//给线程传递值
	convertThread->filed = fild;
	convertThread->passType = oType;
	convertThread->dMin = dMin;
	convertThread->dMax = dMax;
	convertThread->cloud = &cloud;

	//发射信号
	emit startPass();

	//this->close();
}

void dlgPassThroughFilter::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}