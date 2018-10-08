#pragma once

#include <QWidget>
#include <QDialog>
#include <QThread>
#include <QKeyEvent>


#include "ThreadTXT2PCD.h"

namespace Ui { class dlgTxt2PCD; };

class dlgTxt2PCD : public QDialog
{
	Q_OBJECT

public:
	dlgTxt2PCD(QWidget *parent = Q_NULLPTR);
	~dlgTxt2PCD();

	void dealSignalFinished();
	void setBar(int value);

	void keyPressEvent(QKeyEvent *);


public slots:
	void toolClicked1();
	void toolClicked2();

	void convertButton();

signals:
	void startConvert();

private:
	Ui::dlgTxt2PCD *ui;

	QThread *thread;
	ThreadTXT2PCD * convertThread;
};
