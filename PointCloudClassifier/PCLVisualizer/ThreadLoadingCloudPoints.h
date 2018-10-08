#pragma once

#include <QThread>
#include <QString>
#include "DiyXYZRGBPoint.h"

class ThreadLoadingCloudPoints : public QThread
{
	Q_OBJECT

public:
	ThreadLoadingCloudPoints(QObject *parent = nullptr);
	~ThreadLoadingCloudPoints();

	void run();

	QString pointCloudPath;
	QString fileName;

signals:
	void msgBarValue(int);
	void finished(LY::THREAD_TYPE, int);
	void submitCloud(LY::XYZRGBCloud);

private:

};
	
