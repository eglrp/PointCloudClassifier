#pragma once

#include <QObject>
#include <QThread>

#include "DiyXYZRGBPoint.h"

class ThreadFilterVegetation : public QObject
{
	Q_OBJECT

public:
	ThreadFilterVegetation(QObject *parent);
	~ThreadFilterVegetation();

	void runTask(LY::XYZRGBCloud & cloud, std::vector<QString> vecPara);

signals:
	void signalBarValue(LY::THREAD_TYPE, int);

private:
	//QThread thread;

};
