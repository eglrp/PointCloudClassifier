#pragma once

#include <QDialog>
#include <QThread>
#include <QKeyEvent>

#include "ThreadBinarySignal.h"

namespace Ui { class dlgBinarySignal; };

class dlgBinarySignal : public QDialog
{
	Q_OBJECT

public:
	dlgBinarySignal(QWidget *parent = Q_NULLPTR);
	~dlgBinarySignal();

public slots:
	void toolClicked1();
	void toolClicked2();

	void convertButton();
	void finishTask();

	void keyPressEvent(QKeyEvent *);

signals:
	void startThread();

private:
	Ui::dlgBinarySignal *ui;

	QThread * thread;
	ThreadBinarySignal * convertThread;

	
};
