#pragma once

#include <QThread>


/*！
* @class  ThreadRGBResampling  三维点云颜色重采样
*
* @brief  在二维平面上选刺控制点，生成三维点云（其中  Z == 0）
*
*	（1）二维点云数据作为模版，其数据格式为  X Y Z R G B
*	（2）导入三维点云数据，其数据格式为 X Y Z Intensity returnsNum
*	（3）遍历三维点云，在二维平面内找到距离其最近的恩典，然后将该店的 R G B
*	（4）输出txt的点云文件    X Y Z Intensity returnsNum height R G B bin
*/	

class ThreadRGBResampling : public QThread
{
	Q_OBJECT

public:
	ThreadRGBResampling(QObject *parent = nullptr);
	~ThreadRGBResampling();

	void run();
	void split(std::string &str, std::vector<std::string> & result, std::string pattern);
	int getTxtLineCount(std::string file_name);

signals:

	void finished();
};
