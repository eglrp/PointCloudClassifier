/*****************************************************************************
*  OpenST Basic tool library                                                 *
*  Copyright (C) 2014 Henry.Wen  renhuabest@163.com.                         *
*                                                                            *
*  This file is part of OST.                                                 *
*                                                                            *
*  This program is free software; you can redistribute it and/or modify      *
*  it under the terms of the GNU General Public License version 3 as         *
*  published by the Free Software Foundation.                                *
*                                                                            *
*  You should have received a copy of the GNU General Public License         *
*  along with OST. If not, see <http://www.gnu.org/licenses/>.               *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  @file     Example.h                                                       *
*  @brief    对文件的简述                                                    *
*  Details.                                                                  *
*                                                                            *
*  @author   Henry.Wen                                                       *
*  @email    renhuabest@163.com                                              *
*  @version  1.0.0.1(版本号)                                                 *
*  @date     renhuabest@163.com                                              *
*  @license  GNU General Public License (GPL)                                *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description                                              *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2014/01/24 | 1.0.0.1   | Henry.Wen      | Create file                     *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/


#pragma once

// Qt
#include <QMainWindow>
#include <QThread>
#include <QMouseEvent>
#include <QMap>
#include <QTreeWidgetItem>
#include <QRect>
#include <QEvent>
#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QStringList>
#include <QCloseEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTableWidgetItem>
#include <QContextMenuEvent>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QDesktopWidget>
#include <QProgressDialog>
#include <QProgressBar>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QCheckBox>
#include <QMenu>
#include <QFile>
#include <QString>
#include <QDockWidget>
#include <QTreeWidgetItemIterator>
#include <QCursor>
#include <QStyle>
#include <QIcon>
#include <QLinearGradient>
#include <QDateTime>
#include <QHeaderView>
#include <QScrollBar>
#include <QFont>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QFrame>
#include <QMenu>
#include <QAction>
#include <QPoint>
#include <QCursor>
#include <QModelIndex>
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QFileDialog>
#include <QPropertyAnimation>

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
//#include <pcl/ModelCoefficients.h>

// Visualization Toolkit (VTK) 
#include <vtkRenderWindow.h>
#include <vtk3DWidget.h>


#include "DiyXYZRGBPoint.h"
#include "ThreadDelegate.h"

Q_DECLARE_METATYPE(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr)
Q_DECLARE_METATYPE(LY::XYZRGBCloud)
Q_DECLARE_METATYPE(LY::THREAD_TYPE)

namespace Ui
{
	class PCLViewer;
}

class PCLViewer : public QMainWindow
{
	Q_OBJECT

public:
	explicit PCLViewer(QWidget *parent = 0);
	~PCLViewer();

	/**
	* @brief 函数简要说明-测试函数
	* @param index    参数1
	* @param t        参数2 @see CTest
	*
	* @return 返回说明
	*     -<em>false</em> fail
	*     -<em>true</em> succeed
	*/

	//初始化操作
	void initPara();
	void inintTableWidget();
	void initConnector();

	//共有操作
	void setBarValue(LY::THREAD_TYPE, int);  //设置进度条进度
	void addNewPointCloud(LY::XYZRGBCloud);
	void showMultiCloud(std::vector<QString>);
	void updateAttributes(std::vector<QString>);
	virtual bool event(QEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	void closeEvent(QCloseEvent *event);
    void logExport(QString );

	void keyboardEventOccurred(const pcl::visualization::KeyboardEvent &event, void* viewer_void);
	void mouseEventOccurred(const pcl::visualization::MouseEvent &event, void* viewer_void);

protected:
	virtual void keyPressEvent(QKeyEvent *event);

public slots:
	
	///【文件】响应函数-----------------------
	void actionOpenFile();
	void actionSaveAs();
	void actionExit();

	///【工具】响应函数-----------------------
	void actionZoomIn();
	void actionZoomOut();
	void actionZoom();
	void actionCompressCloud();
	void actionClusteCloud();
	void actionKdtreeKNN();
	void actionKdtreeRadius();
	void actionVoxelization();
	void actionTrimCloud();
	void actionScreenShot();

	///【滤波】响应函数----------------------
	void actionPassThroughFilter();
	void actionVoxelCloud();
	void actionOutlinerRemove();
	void actionProjection();
	void actionGrayImage();

	///【视图】响应函数----------------------
	void actionViewer1();
	void actionViewer2();
	void actionViewer4();

	///【数据转换】响应函数------------------
	void actionLAS2TXT();
	void actionTXT2PCDASCII();
	void actionPCDBINARY2PCDASCII();
	void actionPCDASCII2TXT();

	///【雷达数据处理】响应函数--------------
	void actionIntensityFix();
	void actionKdTreeCluster();
	void actionBinarySignal();
	void actionImage2Cloud();
	
	///【帮助】响应函数---------------------
	void actionSetting();
	void actionAbout();
	void actionHelp();

	///【其他】响应函数-----------------------------------
	void treeItemSelected(QTreeWidgetItem*, int);
	void showSelectedItemCloud(QTreeWidgetItem*, int);
	void showMenu(QPoint pos);

signals:
	void delegaterStartRunTask(LY::THREAD_TYPE, LY::XYZRGBCloud &, std::vector<QString>);
	
private:
	Ui::PCLViewer *ui;

	//定义三个 viewer
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer1, viewer2,viewer3; ///三个视窗

	//定义于点云有关的变量
	std::vector<LY::XYZRGBCloud> vecCloud;   ///加载到内存中的所有点云
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclLogo;  ///预加载的PCL点云
	QMap<QString, QString> mapXYZRGB;  ///已加载的点云列表
	int cloudNumOfViewer1;  ///PCLviewer1 中的展示的点云数量
	int pointSize; ///点云的大小
	ThreadDelegate * threadDelegater; ///后台常驻线程
	QThread *threadGUI; ///QThread

	//加载tablewidget用到的
	std::vector<QString> vecTable; ///刷新 QTableWidget 用到的
		 
	//双击标题栏用到的
	QRect desktopRect, *rect; ///可用桌面大小
	int iTitleBarHeight; ///标题栏的高度

	//treeWidget 用到的
	LY::XYZRGBCloud * selectedCloud;  ///记录选中的点云

	//控制台输出用到的
	QStandardItemModel *itemModel;  ///控制台数据模型
	QStringList consoleList;///打印信息列表

};

