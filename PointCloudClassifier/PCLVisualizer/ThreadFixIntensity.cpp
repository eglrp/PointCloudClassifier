#include "ThreadFixIntensity.h"

#include <QThread>
#include <QDebug>
#include "math.h"

ThreadFixIntensity::ThreadFixIntensity(QObject *parent)
	: QObject(parent)
{
	qDebug() << "ThreadFixIntensity  init";
	path = "NULL";
}

ThreadFixIntensity::~ThreadFixIntensity()
{
}

void ThreadFixIntensity::dealSignal(QString & path, float & resolution, int & K, float & deltaH, float & deltaIntensity){
	qDebug() << "ThreadFixIntensity  dealSignal";
	qDebug() << path;
	this->path = path;
	this->resolution = resolution;
	this->K = K;
	this->deltaH = deltaH;
	this->deltaIntensity = deltaIntensity;
}


void ThreadFixIntensity::runTask(){
	qDebug() << "ThreadFixIntensity  before while";
	
	/*while (path == "NULL"){
		continue;
	}*/

	
	qDebug() << "ThreadFixIntensity  after  while";
	qDebug() << QThread::currentThread();

	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
	if (pcl::io::loadPCDFile<pcl::PointXYZI>("E:/xiaotian-ascii.pcd", *cloud) == -1)
		return;

	pcl::PointCloud<pcl::PointXYZI>::Ptr cloudresult(new pcl::PointCloud<pcl::PointXYZI>);
	cloudresult = cloud;
	
	float resolution = 128.0f;///----------------
	pcl::octree::OctreePointCloudSearch<pcl::PointXYZI> octree(resolution);
	octree.setInputCloud(cloud);
	octree.addPointsFromInputCloud();
	for (size_t i = 0; i < cloud->points.size(); ++i)
	{
		std::vector<int> pointIdxVec;
		pcl::PointXYZI searchPoint = cloud->points[i];
		octree.voxelSearch(searchPoint, pointIdxVec);
		int K = 10; ///----------------------
		std::vector<int> pointIdxNKNSearch;
		std::vector<float> pointNKNSquaredDistance;
		octree.nearestKSearch(searchPoint, K, pointIdxNKNSearch, pointNKNSquaredDistance);

		std::vector<int> index;
		float sum_z, sum_intensity;
		for (size_t j = 0; j < pointIdxNKNSearch.size(); j++){
			if (abs(cloud->points[pointIdxNKNSearch[j]].z - searchPoint.z) < 1.0 ||
				    abs(cloud->points[pointIdxNKNSearch[j]].intensity - cloud->points[i].intensity) < 5.0){
				sum_z += cloud->points[pointIdxNKNSearch[j]].z;
				sum_intensity += cloud->points[pointIdxNKNSearch[j]].intensity;
				index.push_back(j);
			}
		}

		sum_z = sum_z / index.size();
		sum_intensity = sum_intensity / index.size();

		for (size_t t = 0; t < index.size(); t++){
			cloudresult->points[index[t]].z = sum_z;
			cloudresult->points[index[t]].intensity = sum_intensity;
		}
			
		if (i % 1000 == 0 && i != 0)
			emit finishTask((int)((float)i / cloud->points.size() * 100));

	}

	pcl::io::savePCDFileASCII("E:/xiaotian-final.pcd", *cloudresult);

	std::cout << "FIBISHED";
}
