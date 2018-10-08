#include "dlgIntensityFix.h"
#include "ui_dlgIntensityFix.h"

#include <QFileDialog>
#include <QString>
#include <QLineEdit>
#include <QToolButton>
#include <QPushButton>

dlgIntensityFix::dlgIntensityFix(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgIntensityFix();
	ui->setupUi(this);

	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(openFile()));
	connect(ui->btnYes, SIGNAL(clicked()), this, SLOT(on_btnYes_clicked()));
	connect(ui->btnNo, SIGNAL(clicked()), this, SLOT(on_btnNo_clicked()));


	this->setFixedSize(550, 300);
}

dlgIntensityFix::~dlgIntensityFix()
{
	delete ui;
}

void dlgIntensityFix::on_btnYes_clicked(){
	path = ui->lineEditFile->text();
	resolution = (ui->lineEditResolution->text()).toFloat();
	K = (int)(ui->lineEditK->text()).toFloat();
	deltaH = (ui->lineEditDeltaH->text()).toFloat();
	deltaIntensity = (ui->lineEditDeltaIntensity->text()).toFloat();

	emit startFix(path, resolution, K, deltaH, deltaIntensity);

	this->close();
}

void dlgIntensityFix::openFile(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString(), "(*.pcd)");
	ui->lineEditFile->setText(path);
}

void dlgIntensityFix::on_btnNo_clicked(){
	this->close();
}

void dlgIntensityFix::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}