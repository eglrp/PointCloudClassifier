#include "ThreadPCD2TXT.h"
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <fstream>
#include <string>
#include <vector>

ThreadPCD2TXT::ThreadPCD2TXT(QObject *parent)
: QObject(parent)
{
}

ThreadPCD2TXT::~ThreadPCD2TXT()
{
}

void ThreadPCD2TXT::runTask(){

	emit changeBar(999);

	pcl::PointCloud<pcl::PointXYZI>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZI>);
	if (pcl::io::loadPCDFile<pcl::PointXYZI>(SRC_PATH, *cloud) == -1){
		return;
	}

	std::ofstream ofs(DEST_PATH.data());
	for (size_t i = 0; i < cloud->points.size(); i++){
		ofs << setiosflags(std::ios::fixed)/*ios::scientific*/ << std::setprecision(7)
			<< cloud->points[i].x << " "
			<< cloud->points[i].y << " "
			<< cloud->points[i].z << " "
			<< cloud->points[i].intensity << "\n";
		
		int value = (int)((float)i / cloud->points.size() * 100);
		if (i%10 ==0 && value <= 99)
			emit changeBar(value);
	}
		
	ofs.close();
	emit finishConvert();
}

