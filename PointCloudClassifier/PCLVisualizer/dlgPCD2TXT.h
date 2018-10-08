#pragma once

#include <QWidget>
#include <QDialog>
#include <QThread>
#include <QKeyEvent>

#include "ThreadPCD2TXT.h"

namespace Ui { class dlgPCD2TXT; };

class dlgPCD2TXT : public QDialog
{
	Q_OBJECT

public:
	dlgPCD2TXT(QWidget *parent = Q_NULLPTR);
	~dlgPCD2TXT();

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
	Ui::dlgPCD2TXT *ui;

	QThread *thread;
	ThreadPCD2TXT * convertThread;
};
