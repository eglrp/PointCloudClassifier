///##############################################################
///		Author: Neverland_LY     Date:2018-7-9 22:56
///
///		这部分代码实现了点云直通滤波功能
///		直通滤波即为筛选出某一字段一定范围内的点云
///		最后对筛选出的点云进行保留或者剔除操作
///
///##############################################################


#pragma once

#include <QObject>
#include "DiyXYZRGBPoint.h"

#include <pcl/filters/passthrough.h>  //直通滤波
#include <pcl/point_types.h>

class ThreadPassThrough : public QObject
{
	Q_OBJECT

public:
	ThreadPassThrough(QObject *parent = 0);
	~ThreadPassThrough();

	void runTask();

	std::string filed;
	std::string passType;
	float dMin;
	float dMax;
	LY::XYZRGBCloud * cloud;

signals:
	void finishTask(pcl::PointCloud<pcl::PointXYZRGB>::Ptr);

};
