#include "dlgTestDialog.h"
#include "ui_dlgTestDialog.h"

#include <QPushbutton>
#include <QProgressBar>

dlgTestDialog::dlgTestDialog(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::dlgTestDialog();
	ui->setupUi(this);

	BASED_NUM = 27;

	this->setFixedSize(700, 450);
	ui->progressBar1->setValue(0);
	ui->progressBar2->setValue(0);
	ui->progressBar3->setValue(0);
	ui->progressBar4->setValue(0);
	ui->progressBar5->setValue(0);
	ui->progressBar6->setValue(0);
	ui->progressBar7->setValue(0);
	ui->progressBar8->setValue(0);
	ui->progressBar9->setValue(0);
	ui->progressBar10->setValue(0);

	for (int i = 0; i < 10; i++){
		thread[i] = new QThread(this);
		convertThread[i] = new ThreadBuildSingulation;
		convertThread[i]->moveToThread(thread[i]);
	}
	
	connect(ui->pushButtonGray, SIGNAL(clicked()), this, SLOT(clickButton()));
	for (int i = 0; i < 10; i++){
		connect(this, &dlgTestDialog::startTask, convertThread[i], &ThreadBuildSingulation::runTask);
		connect(convertThread[i], &ThreadBuildSingulation::changeValue, this, &dlgTestDialog::setValue);
	}
}

dlgTestDialog::~dlgTestDialog()
{
	delete ui;
}

void dlgTestDialog::clickButton(){
	for (int i = 0; i < 9; i++){
		convertThread[i]->INDEX = i;
		convertThread[i]->RUN_BEGIN = i * BASED_NUM;
		convertThread[i]->RUN_END = (i + 1)* BASED_NUM;
		thread[i]->start();
	}

	convertThread[9]->INDEX = 9;
	convertThread[9]->RUN_BEGIN = 9 * BASED_NUM;
	convertThread[9]->RUN_END = 263;
	thread[9]->start();

	emit startTask();
	ui->pushButtonGray->setEnabled(false);
}

void dlgTestDialog::setValue(int index, int value){
	switch (index){
	case 0:
		ui->progressBar1->setValue(value); break;
	case 1:
		ui->progressBar2->setValue(value); break;
	case 2:
		ui->progressBar3->setValue(value); break;
	case 3:
		ui->progressBar4->setValue(value); break;
	case 4:
		ui->progressBar5->setValue(value); break;
	case 5:
		ui->progressBar6->setValue(value); break;
	case 6:
		ui->progressBar7->setValue(value); break;
	case 7:
		ui->progressBar8->setValue(value); break;
	case 8:
		ui->progressBar9->setValue(value); break;
	case 9:
		ui->progressBar10->setValue(value); break;
	default:
		break;
	}
}

void dlgTestDialog::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}
