#pragma once

#include <QObject>
#include <QString>
#include <pcl/point_cloud.h>
#include <pcl/octree/octree.h>
#include <iostream>
#include <vector>
#include <pcl/io/pcd_io.h>


class ThreadFixIntensity : public QObject
{
	Q_OBJECT

public:
	ThreadFixIntensity(QObject *parent = 0);
	~ThreadFixIntensity();

	void runTask();
	void dealSignal(QString &, float &, int &, float &, float &);

signals:
	void finishTask(int value);

private:
	QString path;
	float resolution;
	int K;
	float deltaH;
	float deltaIntensity;
};
