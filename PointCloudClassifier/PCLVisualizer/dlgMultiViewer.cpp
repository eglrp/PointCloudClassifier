#include "dlgMultiViewer.h"
#include "ui_dlgMultiViewer.h"
#include <QComboBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QPixmap>

dlgMultiViewer::dlgMultiViewer(int viewType, QMap<QString, QString> &qmap, QWidget *parent)
: type(viewType), map(qmap),  QDialog(parent)
{
	ui = new Ui::dlgMultiViewer();
	ui->setupUi(this);
	this->resize(500, 500);

	//填充combobox
	QMap<QString, QString>::iterator i;
	for (i = map.begin(); i != map.end(); ++i){
		ui->comboBox->addItem(QString(i.key()));
		ui->comboBox_2->addItem(QString(i.key()));
		ui->comboBox_3->addItem(QString(i.key()));
		ui->comboBox_4->addItem(QString(i.key()));
	}

	//设置默认选项
	if (type == 0){
		ui->radioButton->setChecked(true);
		ui->label->setPixmap(QPixmap("images/view-on.png"));
		ui->label_2->setPixmap(QPixmap("images/view-off.png"));
		ui->label_3->setPixmap(QPixmap("images/view-off.png"));
		ui->label_4->setPixmap(QPixmap("images/view-off.png"));
		ui->comboBox_2->setEnabled(false);
		ui->comboBox_3->setEnabled(false);
		ui->comboBox_4->setEnabled(false);
	}
	else if (type == 1){
		ui->radioButton_2->setChecked(true);
		ui->label->setPixmap(QPixmap("images/view-on.png"));
		ui->label_2->setPixmap(QPixmap("images/view-on.png"));
		ui->label_3->setPixmap(QPixmap("images/view-off.png"));
		ui->label_4->setPixmap(QPixmap("images/view-off.png"));
		ui->comboBox_3->setEnabled(false);
		ui->comboBox_4->setEnabled(false);
	}
	else if (type == 2){
		ui->radioButton_3->setChecked(true);
		ui->label->setPixmap(QPixmap("images/view-on.png"));
		ui->label_2->setPixmap(QPixmap("images/view-on.png"));
		ui->label_3->setPixmap(QPixmap("images/view-on.png"));
		ui->label_4->setPixmap(QPixmap("images/view-on.png"));
	}

	ui->radioButton->setEnabled(false);
	ui->radioButton_2->setEnabled(false);
	ui->radioButton_3->setEnabled(false);

	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(btnClicked()));

}

dlgMultiViewer::~dlgMultiViewer()
{
	delete ui;
}

void dlgMultiViewer::btnClicked(){
	if (ui->radioButton->isChecked() == true){
		vec.push_back(ui->comboBox->currentText());
	}

	if (ui->radioButton_2->isChecked() == true){
		vec.push_back(ui->comboBox->currentText());
		vec.push_back(ui->comboBox_2->currentText());
	}

	if (ui->radioButton_3->isChecked() == true){
		vec.push_back(ui->comboBox->currentText());
		vec.push_back(ui->comboBox_2->currentText());
		vec.push_back(ui->comboBox_3->currentText());
		vec.push_back(ui->comboBox_4->currentText());
	}

	emit signalMap(vec);
	this->close();

}

void dlgMultiViewer::keyPressEvent(QKeyEvent *event){
	switch (event->key()){
	case Qt::Key_Escape:
		break;
	default:
		QDialog::keyPressEvent(event);
		break;
	}
}