#pragma once

#include <QDialog>
#include <QThread>
#include "ThreadBuildSingulation.h"
#include <QKeyEvent>

namespace Ui { class dlgTestDialog; };

class dlgTestDialog : public QDialog
{
	Q_OBJECT

public:
	dlgTestDialog(QWidget *parent = Q_NULLPTR);
	~dlgTestDialog();

	void setValue(int,int );

	void keyPressEvent(QKeyEvent *);


public slots:
	void clickButton();

signals:
	void startTask();

private:
	Ui::dlgTestDialog *ui;

	int BASED_NUM;

	QThread * thread[10];
	ThreadBuildSingulation * convertThread[10];
};
