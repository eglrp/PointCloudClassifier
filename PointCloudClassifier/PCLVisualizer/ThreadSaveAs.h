#pragma once

#include <QThread>
#include <QString>
#include "DiyXYZRGBPoint.h"

class ThreadSaveAs : public QThread
{
	Q_OBJECT

public:
	ThreadSaveAs(QObject *parent = nullptr);
	~ThreadSaveAs();

	void run();

	QString path;
	LY::XYZRGBCloud *cc;

signals:
	void submitMsg();
};
