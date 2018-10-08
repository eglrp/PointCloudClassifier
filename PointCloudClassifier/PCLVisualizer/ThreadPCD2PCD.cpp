#include "ThreadPCD2PCD.h"

#include <cstring>
#include <QString>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

ThreadPCD2PCD::ThreadPCD2PCD(QObject *parent)
: QObject(parent)
{
}

ThreadPCD2PCD::~ThreadPCD2PCD()
{
}

void ThreadPCD2PCD::runTask(){

	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
	if (pcl::io::loadPCDFile<pcl::PointXYZI>(SRC_PATH, *cloud) == -1)
		return;

	pcl::PCDWriter writer;
	std::stringstream ss;
	ss << DEST_PATH;
	writer.write<pcl::PointXYZI>(ss.str(), *cloud, false);

	emit finishConvert();

}
