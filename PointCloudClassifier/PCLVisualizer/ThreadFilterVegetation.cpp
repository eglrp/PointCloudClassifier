#include "ThreadFilterVegetation.h"
#include <QDebug>
#include <windows.h>


#include <QDebug>
#include <QThread>
#include <fstream>
#include <math.h>

using namespace std;

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/visualization/cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/console/parse.h>

#include <pcl/common/centroid.h>  //计算重心

ThreadFilterVegetation::ThreadFilterVegetation(QObject *parent = 0)
	: QObject(parent)
{
}

ThreadFilterVegetation::~ThreadFilterVegetation()
{
	qDebug() << "~ThreadFilterVegetation";
}

void ThreadFilterVegetation::runTask(LY::XYZRGBCloud & cloud, std::vector<QString> vecPara){

	qDebug() << ">>> ThreadFilterVegetation :   " << QThread::currentThread();

	return;


	///打开点云文件
	qDebug() << QString("Start classfying vegetation and other object...");
	ifstream ifs("E:/LXT.txt");
	if (!ifs)
		return;

	///设置变量
	float x, y, z, r, g, b, other;
	float perR, perG, perB;
	float VI;
	vector<float> temp;
	vector<vector<float>> vecVege;
	vector<vector<float>> vecElse;

	///读取点云
	qDebug() << QString("Classfying...");
	while (!ifs.eof()){  ///删除掉txt末尾的空格
		ifs >> x >> y >> z >> r >> g >> b;
		perR = r / (r + g + b);
		perG = g / (r + g + b);
		perB = b / (r + g + b);
		VI = abs(2 * perG - perR - perB - 1.4 * perR + perG);
		temp.push_back(x); temp.push_back(y); temp.push_back(z);
		temp.push_back(r); temp.push_back(g); temp.push_back(b);
		if (VI > 0.4) ///说明是植被点
			vecVege.push_back(temp);
		else ///这是其他类型的点
			vecElse.push_back(temp);
		temp.clear();
	}
	ifs.close();

	///输出植被点
	qDebug() << QString("Producing the vegetation point cloud...");
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudVege(new pcl::PointCloud<pcl::PointXYZRGB>);
	cloudVege->width = vecVege.size();
	cloudVege->height = 1;
	cloudVege->resize(cloudVege->width * cloudVege->height);

	ofstream ofsVege("E:/VegeCloud.txt");
	for (int i = 0; i < vecVege.size(); i++){
		cloudVege->points[i].x = vecVege[i][0];
		cloudVege->points[i].y = vecVege[i][1];
		cloudVege->points[i].z = vecVege[i][2];
		cloudVege->points[i].r = vecVege[i][3];
		cloudVege->points[i].g = vecVege[i][4];
		cloudVege->points[i].b = vecVege[i][5];

		ofsVege << vecVege[i][0] << " " << vecVege[i][1]
			<< " " << vecVege[i][2] << " " << vecVege[i][3]
			<< " " << vecVege[i][4] << " " << vecVege[i][5] << "\n";

	}

	ofsVege.close();

	pcl::io::savePCDFileASCII("E:/VegeCloud.pcd", *cloudVege);

	///输出非植被点
	qDebug() << QString("Producing the othe object point cloud...");
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudElse(new pcl::PointCloud<pcl::PointXYZRGB>);
	cloudElse->width = vecElse.size();
	cloudElse->height = 1;
	cloudElse->resize(cloudElse->width * cloudElse->height);

	ofstream ofsElse("E:/ElseCloud.txt");
	for (int i = 0; i < vecElse.size(); i++){
		cloudElse->points[i].x = vecElse[i][0];
		cloudElse->points[i].y = vecElse[i][1];
		cloudElse->points[i].z = vecElse[i][2];
		cloudElse->points[i].r = vecElse[i][3];
		cloudElse->points[i].g = vecElse[i][4];
		cloudElse->points[i].b = vecElse[i][5];

		ofsElse << vecElse[i][0] << " " << vecElse[i][1]
			<< " " << vecElse[i][2] << " " << vecElse[i][3]
			<< " " << vecElse[i][4] << " " << vecElse[i][5] << "\n";
	}
	ofsElse.close();

	pcl::io::savePCDFileASCII("E:/ElseCloud.pcd", *cloudElse);

	qDebug() << QString("Classfying finished...");

	

}


