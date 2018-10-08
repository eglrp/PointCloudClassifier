#pragma once

#include <QObject>

class ThreadBuildSingulation : public QObject
{
	Q_OBJECT

public:
	ThreadBuildSingulation(QObject *parent = 0);
	~ThreadBuildSingulation();

	void runTask();

	int RUN_BEGIN;
	int RUN_END;
	int INDEX;

signals:
	void changeValue(int , int );

private:
	std::string SRC_PATH;
	float Xmax, Xmin, Ymax, Ymin, Zmax, Zmin;
	int width, height;
	float alpha, beta;
	float GSD;
	float Hmax, Hmin;
	int treeK;

    float radius;

	std::vector<int> pointIdxRadiusSearch;
	std::vector<float> pointRadiusSquaredDistance;

	std::vector<float> vecPij;
		 
};
