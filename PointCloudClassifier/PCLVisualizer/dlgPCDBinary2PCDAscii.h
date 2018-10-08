#pragma once

#include <QWidget>
#include <QThread>
#include <QDialog>
#include <QKeyEvent>

#include "ThreadPCD2PCD.h"

namespace Ui { class dlgPCDBinary2PCDAscii; };

class dlgPCDBinary2PCDAscii : public QDialog
{
	Q_OBJECT

public:
	dlgPCDBinary2PCDAscii(QWidget *parent = Q_NULLPTR);
	~dlgPCDBinary2PCDAscii();

	void dealSignalFinished();
	void setBarValue(int value);

	void keyPressEvent(QKeyEvent *);


public slots:
	void toolClicked1();
	void toolClicked2();
	void convertButton();
	
signals:
	void startConvert();

private:
	Ui::dlgPCDBinary2PCDAscii *ui;

	QThread * thread;
	ThreadPCD2PCD * convertThread;
};
