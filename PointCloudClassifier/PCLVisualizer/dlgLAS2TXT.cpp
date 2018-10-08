#include "dlgLAS2TXT.h"
#include "ui_dlgLAS2TXT.h"

#include <windows.h>

#include <QString>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QFileDialog>

dlgLAS2TXT::dlgLAS2TXT(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgLAS2TXT();
	ui->setupUi(this);

	this->setFixedSize(550, 100);

	connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(toolButtonClicked()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
}

dlgLAS2TXT::~dlgLAS2TXT()
{
	delete ui;
}

void dlgLAS2TXT::toolButtonClicked(){
	QString path = QFileDialog::getOpenFileName(this, QString(), QString("C:/"), "LAS(*.las)");
	ui->lineEdit->setText(path);
}

void dlgLAS2TXT::pushButtonClicked(){
	if (ui->lineEdit->text() == "")
		return;

	std::string path, str;
	//path = "F:/Project_CPlus/PCLCLustering/PCLVisualizer/exec/lastool.exe";
	//str = ui->lineEdit->text().toStdString();
	//path = path + " " + str;
	//int ret = system(path.data());
	///调用外部exe
	this->close();
}

void dlgLAS2TXT::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}

