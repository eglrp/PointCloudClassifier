#include "ThreadUnionFind.h"



#include <QDebug>

#include <iostream>
#include <vector>
#include "math.h"
#include "UnionFind.h"
#include <fstream>
#include <sys/stat.h>

//#include "MyPointType.h"


ThreadUnionFind::ThreadUnionFind(QObject *parent)
: QObject(parent)
{
}

ThreadUnionFind::~ThreadUnionFind()
{
}

void ThreadUnionFind::runTask(){

	qDebug() << "UF Thread is starting ...";

	/************************************************************************/
	///  三维点云重采样颜色后的字段  X Y Z Intensity R G B  
	///  最后处理生成的点云结果为    X Y Z Intensity ReturnsNum Height R G B binary
	/************************************************************************/

	///第一步：定义一个自定义类型（XYZ_IRHRGBBinary）的点云
	pcl::PointCloud<XYZ_IRHRGBBinary>::Ptr cloud(new pcl::PointCloud<XYZ_IRHRGBBinary>);

	///第二步：读取点云文件
	if (SRC_PATH.substr(SRC_PATH.length() - 3, SRC_PATH.length() - 1) == "txt"){

		///获取文件行数
		std::string file_name = SRC_PATH;
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

		///初始化点云大小
		cloud->width = line_count;
		cloud->height = 1;
		cloud->points.resize(cloud->width * cloud->height);
		
		float x, y, z, intensity, r, g, b;
		std::ifstream ifs(SRC_PATH);
		if (!ifs){
			std::cout << ">> Loading failed ...\n";
			return;
		}

		int num = 1;
		while (!ifs.eof()){

			ifs >> x >> y >> z >> intensity >> r >> g >> b;

			cloud->points[num - 1].x = x;
			cloud->points[num - 1].y = y;
			cloud->points[num - 1].z = z;

			cloud->points[num - 1].intensity = intensity;
			cloud->points[num - 1].returnsNum = 0.0f;
			cloud->points[num - 1].height = 0.0f;

			cloud->points[num - 1].r = r;
			cloud->points[num - 1].g = g;
			cloud->points[num - 1].b = b;

			cloud->points[num - 1].bin = 0.0f;

			num++;
		}
		ifs.close();
	}
	else if (SRC_PATH.substr(SRC_PATH.length() - 3, SRC_PATH.length() - 1) == "pcd"){
		if (pcl::io::loadPCDFile<XYZ_IRHRGBBinary>(SRC_PATH, *cloud) == -1){
			std::cout << ">> Loading failed ...\n";
		}
	}
	else{
		/// 在这里拓展其他类型点云
		std::cout << ">>> Unknon subfix of \n";
		return;
	}

	///第三步：定义一个并查集
	UnionFind uf(cloud->points.size());

	///第四步：构建KDTree
	pcl::KdTreeFLANN<XYZ_IRHRGBBinary> kdtree;
	kdtree.setInputCloud(cloud);
	XYZ_IRHRGBBinary searchPoint;

	///第五步：分情况执行 kdTree

	/*
	*  随机选取一个点开始作为起始搜索点
	*  把距离该搜索点最近的 K 个点或者一定 Radius 范围内的点合并为一类，并且将其标记位已找到根节点
	*  将下一个点作为搜索点：
	*		（1）如果这个搜索点及其周围的点组合成的新类和之前的类有重合的点，俺么这两类将合并为一类
	*		（2）如果这个搜索点及其周围的点组合成的新类和之前的类没有公共点，那么将视为新类别
	*  继续网下查找
	*/
	
	emit changeBar(222);
	if (clusterType == 1){ /// K 聚类
		std::vector<int> pointIdxNKNSearch(K);
		std::vector<float> pointNKNSquaredDistance(K);
		for (size_t i = 0; i < cloud->points.size(); i++){
			searchPoint = cloud->points[i];
			if (kdtree.nearestKSearch(searchPoint, K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0){
				for (size_t j = 0; j < pointIdxNKNSearch.size(); j++){
					if (isPrimary == true && isSecdonry == true){
						if ((abs(cloud->points[pointIdxNKNSearch[j]].z - searchPoint.z) < primaryH &&
							abs(cloud->points[pointIdxNKNSearch[j]].intensity - cloud->points[i].intensity) < primaryI) ||
							(abs(cloud->points[pointIdxNKNSearch[j]].z - searchPoint.z) < secondaryH &&
							abs(cloud->points[pointIdxNKNSearch[j]].intensity - cloud->points[i].intensity) < secondaryI)){
							if (uf.find(i) != uf.find(pointIdxNKNSearch[j]))
								uf.unionElements(i, pointIdxNKNSearch[j]);
						}
					}
					else if (isPrimary == true && isSecdonry == false){
						if ((abs(cloud->points[pointIdxNKNSearch[j]].z - searchPoint.z) < primaryH &&
							abs(cloud->points[pointIdxNKNSearch[j]].intensity - cloud->points[i].intensity) < primaryI)){
							if (uf.find(i) != uf.find(pointIdxNKNSearch[j]))
								uf.unionElements(i, pointIdxNKNSearch[j]);
						}
					}
					else{
						if ((abs(cloud->points[pointIdxNKNSearch[j]].z - searchPoint.z) < secondaryH &&
							abs(cloud->points[pointIdxNKNSearch[j]].intensity - cloud->points[i].intensity) < secondaryI)){
							if (uf.find(i) != uf.find(pointIdxNKNSearch[j]))
								uf.unionElements(i, pointIdxNKNSearch[j]);
						}
					}
				}
			}
		}
	}
	else{ /// Radius 聚类
		std::vector<int> pointIdxRadiusSearch;
		std::vector<float> pointRadiusSquaredDistance;
		for (size_t i = 0; i < cloud->points.size(); i++){
			searchPoint = cloud->points[i];
			if (kdtree.radiusSearch(searchPoint, radius, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0){
				for (size_t j = 0; j < pointIdxRadiusSearch.size(); j++){
					if (isPrimary == true && isSecdonry == true){
						if ((abs(cloud->points[pointIdxRadiusSearch[j]].z - searchPoint.z) < primaryH &&
							abs(cloud->points[pointIdxRadiusSearch[j]].intensity - cloud->points[i].intensity) < primaryI) ||
							(abs(cloud->points[pointIdxRadiusSearch[j]].z - searchPoint.z) < secondaryH &&
							abs(cloud->points[pointIdxRadiusSearch[j]].intensity - cloud->points[i].intensity) < secondaryI)){
							if (uf.find(i) != uf.find(pointIdxRadiusSearch[j]))
								uf.unionElements(i, pointIdxRadiusSearch[j]);
						}
					}
					else if (isPrimary == true && isSecdonry == false){
						if ((abs(cloud->points[pointIdxRadiusSearch[j]].z - searchPoint.z) < primaryH &&
							abs(cloud->points[pointIdxRadiusSearch[j]].intensity - cloud->points[i].intensity) < primaryI)){
							if (uf.find(i) != uf.find(pointIdxRadiusSearch[j]))
								uf.unionElements(i, pointIdxRadiusSearch[j]);
						}
					}
					else{
						if ((abs(cloud->points[pointIdxRadiusSearch[j]].z - searchPoint.z) < secondaryH &&
							abs(cloud->points[pointIdxRadiusSearch[j]].intensity - cloud->points[i].intensity) < secondaryI)){
							if (uf.find(i) != uf.find(pointIdxRadiusSearch[j]))
								uf.unionElements(i, pointIdxRadiusSearch[j]);
						}
					}
				}
			}
		}
	}

	///第六步：统计根节点数量及根节点对应的索引
	emit changeBar(333);
	std::vector<int> root;
	static int numRoot = 0;  /// 最后聚合成多少类
	for (size_t i = 0; i < cloud->points.size(); i++){
		if (uf.isRoot(i) == true){
			root.push_back(i);  ///i 代表根索引，这步就是统计一共聚类成多少类
			numRoot++;
		}
	}

	///第七步：统计聚类点
	emit changeBar(444);
	std::vector<std::vector<int>> cluster;  ///定义一个二维数组，统计根节点和子节点
	cluster.clear();
	cluster.resize(numRoot);
	for (int i = 0; i < numRoot; i++)
		cluster[i].push_back(root[i]);

	int pointsNum;
	std::vector<int>::iterator it;
	for (size_t i = 0; i < cloud->points.size(); i++){
		if (uf.isRoot(i) == false){
			it = find(root.begin(), root.end(), uf.find(i));
			if (it != root.end()){ ///找到根节点了
				auto index = std::distance(std::begin(root), it);
				cluster[(int)(index)].push_back(i);
			}
		}
		pointsNum++;
	}

	///第八步：进行反射强度修复，更新点云
	emit changeBar(555);
	float sum_z, sum_intensity;
	for (size_t i = 0; i < root.size(); i++){
		for (size_t j = 0; j < cluster[i].size(); j++){
			//sum_z += cloud->points[cluster[i][j]].z;
			sum_intensity += cloud->points[cluster[i][j]].intensity;
		}

		//sum_z = sum_z / cluster[i].size();
		sum_intensity = sum_intensity / cluster[i].size();

		for (size_t t = 0; t < cluster[i].size(); t++){
			//cloud->points[cluster[i][t]].z = sum_z;
			cloud->points[cluster[i][t]].intensity = sum_intensity;
		}

		sum_z = sum_intensity = 0.0;

		int value = (int)((float)i / cloud->points.size() * 100);
		if (i % 10 == 0 && value <= 99)
			emit changeBar(value);
	}

	///第九步：输出结果到 .txt / .pcd
	emit changeBar(666);
	if (SRC_PATH.substr(SRC_PATH.length() - 3, SRC_PATH.length() - 1) == "txt"){
		std::ofstream ofs(DEST_PATH);
		for (size_t i = 0; i < cloud->points.size(); i++){
			ofs << cloud->points[i].x << " "
				<< cloud->points[i].y << " "
				<< cloud->points[i].z << " "
				<< cloud->points[i].intensity << " "
				<< cloud->points[i].returnsNum << " "
				<< cloud->points[i].height << " "
				<< cloud->points[i].r << " "
				<< cloud->points[i].g << " "
				<< cloud->points[i].b << " "
				<< cloud->points[i].bin << "\n";
		}
		ofs.close();
	}
	else if (SRC_PATH.substr(SRC_PATH.length() - 3, SRC_PATH.length() - 1) == "pcd"){
		///输出结果到 .pcd
		pcl::io::savePCDFileASCII(DEST_PATH, *cloud);
	}

	///最后，发出处理完毕的信号
	emit finishUF(pointsNum, numRoot);  ///处理结束

}
