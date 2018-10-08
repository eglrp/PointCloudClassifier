#include "ThreadSaveAs.h"
#include <fstream>
#include <QDebug>

ThreadSaveAs::ThreadSaveAs(QObject *parent)
	: QThread(parent)
{
	path = "";
	cc->cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>); ///一定要初始化，否则会出现崩溃
	std::cout << ">>> ThreadSaveAs construct ...\n";
}

ThreadSaveAs::~ThreadSaveAs()
{
	delete cc;
	std::cout << ">>> ThreadSaveAs desstruct ...\n";

}

void ThreadSaveAs::run(){

	qDebug() << QThread::currentThread();

	if (path == ""){
		emit submitMsg();
		return;
	}
	
	///赋制一份点云
	//pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	//pcl::copyPointCloud(*(cc->cloud), *cloud);

	///保存类型
	std::string str = path.toStdString();
	if (str.substr(str.length() - 3, str.length() - 1) == "txt"){
		///遍历点云
		std::ofstream ofs(path.toStdString());
		std::cout << "--------------\n";
		for (int i = 0; i < cc->cloud->points.size(); i++){
			ofs << cc->cloud->points[i].x << " "
				<< cc->cloud->points[i].y << " "
				<< cc->cloud->points[i].z << " "
				<< cc->cloud->points[i].r << " "
				<< cc->cloud->points[i].g << " "
				<< cc->cloud->points[i].b << "\n";
		}
		ofs.close();
	}
	else if(str.substr(str.length() - 3, str.length() - 1) == "pcd"){
		pcl::io::savePCDFileASCII(path.toStdString(), *(cc->cloud));
	}

	emit submitMsg();
}
