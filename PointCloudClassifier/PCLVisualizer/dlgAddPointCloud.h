///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-9 22:56
///		
///		这段代码实现了点云文件的打开操作
///		
///		目前只支持 XYZRGB.pcd  文件的读取操作，以后会兼容其他格式的数据类型
///
///##############################################################


#pragma once

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QKeyEvent>
#include <QCloseEvent>

#include "ThreadLoadingCloudPoints.h"

namespace Ui { class dlgAddPointCloud; };

class dlgAddPointCloud : public QDialog
{
	Q_OBJECT

public:
	dlgAddPointCloud(QWidget *parent, ThreadLoadingCloudPoints *);
	~dlgAddPointCloud();

	void keyPressEvent(QKeyEvent *);

	void setValue(int);

private:
	Ui::dlgAddPointCloud *ui;

	QString file_name;
	
};
