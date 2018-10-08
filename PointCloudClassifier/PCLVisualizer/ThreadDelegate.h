/*

代理类模块的设计





*/
#pragma once

#include <QObject>
#include "DiyXYZRGBPoint.h"

#include "ThreadFilterVegetation.h"
#include "DiyXYZRGBPoint.h"

class ThreadDelegate : public QObject
{
	Q_OBJECT

public:
	ThreadDelegate(QObject *parent = 0);
	~ThreadDelegate();

	void runManageThread(LY::THREAD_TYPE type, LY::XYZRGBCloud & cloud, std::vector<QString> vecPara);

signals:
	void signalRunTask(LY::XYZRGBCloud & cloud, std::vector<QString> vecPara);

	void signalBarValue(LY::THREAD_TYPE, int);
	void signalResultCloud(LY::THREAD_TYPE, LY::XYZRGBCloud * cloud);
};
