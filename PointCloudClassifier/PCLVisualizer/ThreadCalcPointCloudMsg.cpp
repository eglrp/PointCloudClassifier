#include "ThreadCalcPointCloudMsg.h"
#include <QThread>
#include <QDebug>

ThreadCalcPointCloudMsg::ThreadCalcPointCloudMsg(QObject *parent)
: QThread(parent)
{
	cloud = nullptr;
	std::cout << ">>> ThreadCalcPointCloudMsg construct ...\n";
}

ThreadCalcPointCloudMsg::~ThreadCalcPointCloudMsg()
{
	delete cloud;
	std::cout << ">>> ThreadCalcPointCloudMsg destruct ...\n";
}

void ThreadCalcPointCloudMsg::run(){

	///记录填充信息
	std::vector<QString> vec;

	///记录点云的头0、名称1、大小2、数量3
	vec.push_back("  ");  ///占位符
	vec.push_back(cloud->name);
	vec.push_back("1");
	vec.push_back(QString("%1").arg(cloud->cloud->points.size()));

	///记录最小点4、最大点5
	pcl::PointXYZRGB minPt, maxPt;
	pcl::getMinMax3D(*(cloud->cloud), minPt, maxPt);
	vec.push_back(QString("%1  %2  %3").arg(minPt.x).arg(minPt.y).arg(minPt.z));
	vec.push_back(QString("%1  %2  %3").arg(maxPt.x).arg(maxPt.y).arg(maxPt.z));

	///记录X的范围6、Y的范围7、Z的范围8
	vec.push_back(QString("%1 - %2").arg(minPt.x).arg(maxPt.x));
	vec.push_back(QString("%1 - %2").arg(minPt.y).arg(maxPt.y));
	vec.push_back(QString("%1 - %2").arg(minPt.z).arg(maxPt.z));

	///记录点云的重心9
	/*Eigen::Vector4f centroid;
	pcl::compute3DCentroid(*cloud, centroid);
	std::cout << "The XYZ coordinates of the centroid are: ("
	<< centroid[0] << ", "
	<< centroid[1] << ", "
	<< centroid[2] << ")." << std::endl;*/
	vec.push_back(QString("%1  %2  %3").arg(minPt.x).arg(minPt.y).arg(minPt.z));

	///记录点云的中心10 、其他11
	vec.push_back(QString("%1  %2  %3").arg((minPt.x + maxPt.x)/2).
		arg((minPt.y + maxPt.y) / 2).
		arg((minPt.z + maxPt.z) / 2));
	vec.push_back("  ");

	///记录点云其他属性12，路径13、颜色14
	vec.push_back("  ");
	vec.push_back(cloud->path);
	vec.push_back("Scalar-RGB");

	emit submitMsg(vec);
}