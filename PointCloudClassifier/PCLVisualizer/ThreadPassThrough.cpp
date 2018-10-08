///##############################################################
///		Author: Neverland_LY     Date:2018-7-9 22:56
///
///		这部分代码实现了点云直通滤波功能
///		直通滤波即为筛选出某一字段一定范围内的点云
///		最后对筛选出的点云进行保留或者剔除操作
///
///##############################################################


#include "ThreadPassThrough.h"

ThreadPassThrough::ThreadPassThrough(QObject *parent)
	: QObject(parent)
{
}

ThreadPassThrough::~ThreadPassThrough()
{
}

void ThreadPassThrough::runTask(){

	///核心功能的实现跑出来
	pcl::PassThrough<pcl::PointXYZRGB> pass;
	pass.setInputCloud(cloud->cloud);
	pass.setFilterFieldName(filed);
	pass.setFilterLimits(dMin, dMax);
	if (passType == "DELETE")
		pass.setNegative(false);
	else
		pass.setFilterLimitsNegative(true);

	LY::XYZRGBCloud * cloud_result;
	pass.filter(*(cloud_result->cloud));

	//emit finishTask(cloud_result);;
}
