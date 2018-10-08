#include "dlgKdTreeCluster.h"
#include "ui_dlgKdTreeCluster.h"

#include <QFileDialog>
#include <QString>
#include <QLineEdit>
#include <QToolButton>
#include <QPushButton>
#include <QProgressBar>
#include <QRadioButton>
#include <QCheckBox>

#include "Windows.h"

dlgKdTreeCluster::dlgKdTreeCluster(QWidget *parent)
: QDialog(parent)
{
	ui = new Ui::dlgKdTreeCluster();
	ui->setupUi(this);

	this->setFixedSize(700, 430);

	ui->progressBar->setValue(0);
	ui->rbK->setChecked(true);
	ui->lineEditRadius->setEnabled(false);

	ui->lineEditPrimaryDeltaH->setEnabled(false);
	ui->lineEditPrimaryDeltaI->setEnabled(false);
	ui->lineEditSecondaryDeltaH->setEnabled(false);
	ui->lineEditSecondaryDeltaI->setEnabled(false);

	thread = new QThread(this);
	convertThread = new ThreadUnionFind;
	convertThread->moveToThread(thread);
	convertThread->clusterType = 1;
	convertThread->isPrimary = false;
	convertThread->isSecdonry = false;

	connect(ui->toolButtonInput, SIGNAL(clicked()), this, SLOT(toolClicked1()));
	connect(ui->toolButtonOutput, SIGNAL(clicked()), this, SLOT(toolClicked2()));

	connect(ui->rbK, SIGNAL(clicked()), this, SLOT(rbClicked1()));
	connect(ui->rbRadius, SIGNAL(clicked()), this, SLOT(rbClicked2()));

	connect(ui->checkBoxPrimary, SIGNAL(clicked()), this, SLOT(checkClicked1()));
	connect(ui->checkBoxSecondary, SIGNAL(clicked()), this, SLOT(checkClicked2()));

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(convertButton()));

	connect(this, &dlgKdTreeCluster::startConvert, convertThread, &ThreadUnionFind::runTask);
	connect(convertThread, &ThreadUnionFind::finishUF, this, &dlgKdTreeCluster::dealSignalFinished);
	connect(convertThread, &ThreadUnionFind::changeBar, this, &dlgKdTreeCluster::setBarValue);

}

dlgKdTreeCluster::~dlgKdTreeCluster()
{
	delete convertThread;
	delete ui;
}

void dlgKdTreeCluster::toolClicked1(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "TXT(*.txt)");
	ui->lineEditInput->setText(path);
	convertThread->SRC_PATH = path.toStdString();
}

void dlgKdTreeCluster::toolClicked2(){
	QString path = QFileDialog::getSaveFileName(this, QString(), QString("C:/"), "TXT(*.txt)");
	ui->lineEditOutput->setText(path);
	convertThread->DEST_PATH = path.toStdString();
}

void dlgKdTreeCluster::rbClicked1(){
	if (ui->rbK->isChecked() == true){
		ui->lineEditK->setEnabled(true);
		ui->lineEditRadius->setEnabled(false);
		convertThread->clusterType = 1;
	}
	else{
		ui->lineEditK->setEnabled(false);
		ui->lineEditRadius->setEnabled(true);
		convertThread->clusterType = 2;
	}
}

void dlgKdTreeCluster::rbClicked2(){
	if (ui->rbRadius->isChecked() == true){
		ui->lineEditK->setEnabled(false);
		ui->lineEditRadius->setEnabled(true);
		convertThread->clusterType = 2;
	}
	else{
		ui->lineEditK->setEnabled(true);
		ui->lineEditRadius->setEnabled(false);
		convertThread->clusterType = 1;
	}
}

void dlgKdTreeCluster::checkClicked1(){
	if (ui->checkBoxPrimary->isChecked() == true){
		ui->lineEditPrimaryDeltaH->setEnabled(true);
		ui->lineEditPrimaryDeltaI->setEnabled(true);
		convertThread->isPrimary = true;
	}
	else{
		ui->lineEditPrimaryDeltaH->setEnabled(false);
		ui->lineEditPrimaryDeltaI->setEnabled(false);
		convertThread->isPrimary = false;
		ui->lineEditPrimaryDeltaH->setEnabled(false);
	}
}

void dlgKdTreeCluster::checkClicked2(){
	if (ui->checkBoxSecondary->isChecked() == true){
		ui->lineEditSecondaryDeltaH->setEnabled(true);
		ui->lineEditSecondaryDeltaI->setEnabled(true);
		convertThread->isSecdonry = true;
	}
	else{
		ui->lineEditSecondaryDeltaH->setEnabled(false);
		ui->lineEditSecondaryDeltaI->setEnabled(false);
		convertThread->isSecdonry = false;
	}
}

void dlgKdTreeCluster::convertButton(){
	///判定一些条件
	if (ui->lineEditInput->text() == "" ||
		ui->lineEditOutput->text() == "")
		return;

	if (ui->rbK->isChecked() == true){
		if (ui->lineEditK->text() == "")
			return;
		convertThread->K = ui->lineEditK->text().toFloat();
	}
	else{
		if (ui->lineEditRadius->text() == "")
			return;
		convertThread->radius = ui->lineEditRadius->text().toFloat();
	}

	if (ui->checkBoxPrimary->isChecked() == true){
		if (ui->lineEditPrimaryDeltaH->text() == "" ||
			ui->lineEditPrimaryDeltaI->text() == "")
			return;
		convertThread->primaryH = ui->lineEditPrimaryDeltaH->text().toFloat();
		convertThread->primaryI = ui->lineEditPrimaryDeltaI->text().toFloat();
	}

	if (ui->checkBoxSecondary->isChecked() == true){
		if (ui->lineEditSecondaryDeltaH->text() == "" ||
			ui->lineEditSecondaryDeltaI->text() == "")
			return;
		convertThread->secondaryH = ui->lineEditSecondaryDeltaH->text().toFloat();
		convertThread->secondaryI = ui->lineEditSecondaryDeltaI->text().toFloat();

	}

	if (ui->checkBoxPrimary->isChecked() == false &&
		ui->checkBoxSecondary->isChecked() == false )
		return;

	Beep(1000,500);

	thread->start();
	emit startConvert();
	ui->pushButton->setEnabled(false);

}

void dlgKdTreeCluster::dealSignalFinished(int &v1, int &v2){
	thread->quit();
	thread->wait();
	ui->progressBar->setValue(100);
	ui->progressBar->setFormat(QString::fromLocal8Bit("超聚类完成"));
	//更新结果
	ui->lineEditResult1->setEnabled(true);
	ui->lineEditResult1->setText(QString("%1").arg(v1));
	ui->lineEditResult2->setEnabled(true);
	ui->lineEditResult2->setText(QString("%1").arg(v2));
	ui->lineEditResult3->setEnabled(true);
	ui->lineEditResult3->setText(QString("%1").arg((int)((float)v1/v2)));
	ui->lineEditResult4->setEnabled(true);
	ui->lineEditResult4->setText("89.9%");

}

void dlgKdTreeCluster::setBarValue(int value){
	if (value == 111){
		ui->progressBar->setValue(10);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在扫描文件..."));
		return;
	}

	if (value == 222){
		ui->progressBar->setValue(30);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在超聚类..."));
		return;
	}

	if (value == 333){
		ui->progressBar->setValue(50);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在统计聚类结果..."));
		return;
	}

	if (value == 444){
		ui->progressBar->setValue(70);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在分类..."));
		return;
	}

	if (value == 555){
		ui->progressBar->setValue(80);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在构建点云..."));
		return;
	}

	if (value == 666){
		ui->progressBar->setValue(90);
		ui->progressBar->setFormat(QString::fromLocal8Bit("正在输出点云到文件..."));
		return;
	}

	ui->progressBar->setValue(value);
	ui->progressBar->setFormat(QString::fromLocal8Bit("正在生成聚类点云，当前进度为：%1%").arg(QString::number(value)));
}

void dlgKdTreeCluster::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}

