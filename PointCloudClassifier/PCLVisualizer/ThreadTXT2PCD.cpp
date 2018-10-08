#include "ThreadTXT2PCD.h"

#include <iostream>
#include <cstring>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <string>
#include <vector>

#include <QFile>
#include <QString>
#include <QTextStream>

ThreadTXT2PCD::ThreadTXT2PCD(QObject *parent)
: QObject(parent)
{
}

ThreadTXT2PCD::~ThreadTXT2PCD()
{
}

void ThreadTXT2PCD::runTask(){

	QFile file(QString::fromStdString(SRC_PATH));
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QTextStream in(&file);
	int num = 0;
	while (!in.atEnd()){
		QString line = in.readLine();
		num++;
	}
	file.close();

	std::vector<std::vector<float>> m_Points;
	std::vector<float> temp;
	std::ifstream ifs(SRC_PATH.data());
	float x, y, z, /*intensity, */r, g, b; ///***********
	if (!ifs)
		return;

	/*for (int i = 0; !ifs.eof(); i++){
		ifs >> x >> y >> z >> intensity;
		temp.push_back(x); temp.push_back(y); temp.push_back(z);
		temp.push_back(intensity);
		m_Points.push_back(temp);
		temp.clear();
		}*/

	///************************************
	for (int i = 0; !ifs.eof(); i++){
		ifs >> x >> y >> z >> r >> g >> b;
		temp.push_back(x); temp.push_back(y); temp.push_back(z);
		temp.push_back(r); temp.push_back(g); temp.push_back(b);
		m_Points.push_back(temp);
		temp.clear();
	}
	///**********************************

	int number = m_Points.size();

	//pcl::PointCloud<pcl::PointXYZI> cloud;
	///**********************************
	pcl::PointCloud<pcl::PointXYZRGB> cloud;
	///***********************************

	cloud.width = number;
	cloud.height = 1;
	cloud.is_dense = false;
	cloud.points.resize(cloud.width * cloud.height);

	int value;
	for (size_t i = 0; i < cloud.points.size(); ++i)
	{
		cloud.points[i].x = m_Points[i][0];
		cloud.points[i].y = m_Points[i][1];
		cloud.points[i].z = m_Points[i][2];
		//cloud.points[i].intensity = m_Points[i][3];

		///**********************************
		cloud.points[i].r = m_Points[i][3];
		cloud.points[i].g = m_Points[i][4];
		cloud.points[i].b = m_Points[i][5];
		///***********************************

		value = (int)((float)i / num * 100);
		if (i % 10 == 0 && value <= 99)
			emit changeBar(value);
	}

	emit changeBar(999);

	pcl::io::savePCDFileASCII(DEST_PATH, cloud);
	m_Points.clear();

	emit finishConvert();
}
