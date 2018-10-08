#define PCL_NO_PRECOMPILE
#pragma once


#include <QObject>

#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

struct XYZ_IRHRGBBinary
{
	PCL_ADD_POINT4D;
	float intensity;
	float returnsNum;
	float height;
	float r;
	float g;
	float b;
	float bin;
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
}EIGEN_ALIGN16;


POINT_CLOUD_REGISTER_POINT_STRUCT(XYZ_IRHRGBBinary,// ◊¢≤·µ„¿‡–Õ∫Í
	(float, x, x)
	(float, y, y)
	(float, z, z)
	(float, intensity, intensity)
	(float, returnsNum, returnsNum)
	(float, height, height)
	(float, r, r)
	(float, g, g)
	(float, b, b)
	(float, bin, bin)
	)


class ThreadUnionFind : public QObject
{
	Q_OBJECT

public:
	ThreadUnionFind(QObject *parent = 0);
	~ThreadUnionFind();

	void runTask();

	std::string SRC_PATH;
	std::string DEST_PATH;

	int clusterType;
	float K, radius;
	bool isPrimary, isSecdonry;
	float primaryH, primaryI, secondaryH, secondaryI;

signals:
	void finishUF(int &,int &);
	void changeBar(int value);
};
