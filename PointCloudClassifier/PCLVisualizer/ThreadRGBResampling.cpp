#include "ThreadRGBResampling.h"

#include <QDebug>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include "math.h"
#include <stdio.h>

#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

ThreadRGBResampling::ThreadRGBResampling(QObject *parent)
: QThread(parent)
{
}

ThreadRGBResampling::~ThreadRGBResampling()
{
	qDebug() << "destoryed";
}


void ThreadRGBResampling::split(std::string &str, std::vector<std::string> & result, std::string pattern)
{
	std::string::size_type pos;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
}

int ThreadRGBResampling::getTxtLineCount(std::string file_name){
	int line_count = 0; ///记录文件中行的数量
	struct stat s;
	stat(file_name.c_str(), &s);
	///获取指定文本的行数
	std::string file_buf(s.st_size + 1, '\0');
	///将文件中的数据一次性读出来
	FILE* fp = fopen(file_name.c_str(), "rb");
	fread(&file_buf[0], sizeof(char), file_buf.size(), fp);
	const char* file_buf_tmp = file_buf.c_str(); ///获取文件内容指针
	while (*file_buf_tmp != '\0')
	{
		///查找第一个换行
		const char* p = strchr(file_buf_tmp, '\n');
		if (p == NULL)
		{
			///最后一行没有'\n'
			++line_count;
			break;
		}
		///过滤空行
		line_count += p - file_buf_tmp > 0;
		///查找下一个'\n'
		file_buf_tmp += p - file_buf_tmp + 1;
	}
	return line_count;
}

void ThreadRGBResampling::run(){

	qDebug() << QThread::currentThread();

	std::string plane_path = "E:/plane-point.txt";
	std::string stereo_path = "E:/stereo-point.txt";
	std::string dest_path = "E:/dest-point.txt";

	///第一步：读取 plane-point 的行数
	int line_count = getTxtLineCount(plane_path);
	std::cout << "1 finished\n";

	///第二步：读取 plane-cloud 点云
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
	cloud->width = line_count;
	cloud->height = 1;
	cloud->points.resize(cloud->width * cloud->height);

	std::ifstream ifsPlane(plane_path);
	std::istreambuf_iterator<char> begin(ifsPlane);
	std::istreambuf_iterator<char> end;
	std::string strPlane(begin, end);
	ifsPlane.close();

	std::string::size_type pos = 0;
	std::vector<std::string> vec;
	std::string str;
	int num = 0;
	while ((pos = strPlane.find_first_of('\n')) != std::string::npos){
		str = strPlane.substr(0, pos);
		if (str != ""){
			split(str, vec, " ");   /// X  Y  Z  R  G  B
			cloud->points[num].x = atof(vec[0].c_str());  //最终获取到的数据
			cloud->points[num].y = atof(vec[1].c_str());
			cloud->points[num].z = atof(vec[2].c_str());
			cloud->points[num].r = atof(vec[3].c_str());
			cloud->points[num].g = atof(vec[4].c_str());
			cloud->points[num].b = atof(vec[5].c_str());
			num++;
		}
		strPlane = strPlane.substr(pos + 1, strPlane.length() - str.length());
		pos = 0;
		vec.clear();
	}

	std::cout << "2 finished\n";

	///第三步：构建KDtree
	pcl::KdTreeFLANN<pcl::PointXYZRGB> kdtree;
	kdtree.setInputCloud(cloud);
	pcl::PointXYZRGB searchPoint;
	std::vector<int> pointIdxNKNSearch(1);
	std::vector<float> pointNKNSquaredDistance(1);

	std::cout << "3 finished\n";

	///第四步：读取 stereo_point 点云
	std::ifstream ifsStereo(stereo_path);
	std::istreambuf_iterator<char> beginStereo(ifsStereo);
	std::istreambuf_iterator<char> endStereo;
	std::string strStereo(beginStereo, endStereo);
	ifsStereo.close();

	std::cout << "4 finished\n\n";

	pos = 0;
	vec.clear();
	int total = getTxtLineCount(stereo_path);
	int nowLine = 0;

	std::string outStr;
	while ((pos = strStereo.find_first_of('\n')) != std::string::npos){
		str = strStereo.substr(0, pos);
		if (str != ""){
			split(str, vec, " "); ///  X  Y  Z  intensity  returns
			searchPoint.x = atof(vec[0].c_str());
			searchPoint.y = atof(vec[1].c_str());
			searchPoint.z = 0.000f; //特别注意
			if (kdtree.nearestKSearch(searchPoint, 1, pointIdxNKNSearch, pointNKNSquaredDistance) > 0){
				outStr += vec[0] + " " + vec[1] + " " + vec[2] + " " + vec[3] + " " + vec[4] + " 0.00 " +
					std::to_string(cloud->points[pointIdxNKNSearch[0]].r) + " " +
					std::to_string(cloud->points[pointIdxNKNSearch[0]].g) + " " +
					std::to_string(cloud->points[pointIdxNKNSearch[0]].b) + " 00000000\n";
			}
			pointIdxNKNSearch.clear();
			pointNKNSquaredDistance.clear();
		}
		strStereo = strStereo.substr(pos + 1, strStereo.length() - str.length());
		pos = 0;
		nowLine++;
		printf("\r");
		printf("Schedule :  %d / %d", nowLine ,total);
		vec.clear();
	}

	std::ofstream ofs(dest_path);
	ofs << outStr;
	ofs.close();

	std::cout << "5 finished\n";

	//emit finished();
}