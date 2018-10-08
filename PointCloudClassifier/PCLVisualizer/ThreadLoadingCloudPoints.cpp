#include "ThreadLoadingCloudPoints.h"
#include "DiyXYZRGBPoint.h"
#include <QDebug>
#include <fstream>
#include <sys/stat.h>

ThreadLoadingCloudPoints::ThreadLoadingCloudPoints(QObject *parent)
: QThread(parent)
{
	pointCloudPath = "";
	fileName = "";
	qDebug() << ">>> ThreadLoadingCloudPoints construct ...";
}

ThreadLoadingCloudPoints::~ThreadLoadingCloudPoints()
{
	qDebug() << ">>> ThreadLoadingCloudPoints destruct ...";
}

void ThreadLoadingCloudPoints::run(){

	///判断点云类型文件，分类添加点云
	LY::XYZRGBCloud cloud;
	cloud.path = pointCloudPath; 
	cloud.name = fileName; 

	std::string str = fileName.toStdString();
	if (str.substr(str.length() - 3, str.length() - 1) == "txt"){

		///获取文件行数
		std::string file_name = pointCloudPath.toStdString();
		struct stat s;
		stat(file_name.c_str(), &s);
		///获取指定文本的行数
		std::string file_buf(s.st_size + 1, '\0');
		///将文件中的数据一次性读出来
		FILE* fp = fopen(file_name.c_str(), "rb");
		fread(&file_buf[0], sizeof(char), file_buf.size(), fp);
		int line_count = 0; ///记录文件中行的数量
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

		float x, y, z, r, g, b;
		cloud.cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
		cloud.cloud->width = line_count;
		cloud.cloud->height = 1;
		cloud.cloud->points.resize(cloud.cloud->width * cloud.cloud->height);

		std::ifstream ifs(file_name);
		if (!ifs){
			std::cout << ">> Loading " << fileName.toStdString() << " failed ...\n";
			return;
		}

		int num = 1;
		while (!ifs.eof()){

			ifs >> x >> y >> z >> r >> g >> b;

			cloud.cloud->points[num - 1].x = x;
			cloud.cloud->points[num - 1].y = y;
			cloud.cloud->points[num - 1].z = z;

			cloud.cloud->points[num - 1].r = r;
			cloud.cloud->points[num - 1].g = g;
			cloud.cloud->points[num - 1].b = b;

			num++;
			if (num > line_count){
				emit msgBarValue(100);
				break;
			}

			if (num % 1000 == 0)
				emit msgBarValue((int)(float(num) / line_count * 100));
		}
		ifs.close();
	}
	else if (str.substr(str.length() - 3, str.length() - 1) == "pcd"){
		cloud.cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
		emit msgBarValue(30);
		if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(pointCloudPath.toStdString(), *(cloud.cloud)) == -1){
			std::cout << ">> Loading " << fileName.toStdString() << " failed ...\n";
		}
		emit msgBarValue(100);
	}
	else{
		/// 在这里拓展其他类型点云
		std::cout << ">>> Unknon subfix of " << fileName.toStdString() << "\n";
		return;
	}

	emit submitCloud(cloud);
}


