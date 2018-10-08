#pragma once

#include <QThread>
#include <QString>
#include "DiyXYZRGBPoint.h"

class ThreadCalcPointCloudMsg : public QThread
{
	Q_OBJECT

public:
	ThreadCalcPointCloudMsg(QObject *parent = nullptr);
	~ThreadCalcPointCloudMsg();

	void run();
	LY::XYZRGBCloud * cloud;

signals:
	void submitMsg(std::vector<QString>);
};
