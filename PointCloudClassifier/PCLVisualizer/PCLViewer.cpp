///##############################################################
///
///		Author: Neverland_LY     Date:2018-7-9 22:56
///
///		这是本软件的主界面部分，也是程序总入口，总共设有如下功能：
///		
///		【文件】点云文件的打开操作，以及程序的关闭等
///
///		【工具】对点云的一些基本数据操作，如点云压缩，聚类等
///
///		【滤波】对点云进行一些降噪处理，提取处理等
///
///     【视图】对点云的展示进行一些操作等，比如同一窗口显示多个点云等
///
///		【数据转换】点云格式的转换，如 *.txt、*.pcd、*.las、*.lyz 等
///
///		【雷达数据处理】对雷达数据的一些简单操作
///		
///		【帮助】关于软件说明等
///
///		此外，界面还设置了点云列表窗口、属性窗口、控制台窗口、试图窗口等
///		
///##############################################################

/// C++11
#include "pclviewer.h"
#include "ui_pclviewer.h"

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>

///OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/legacy/legacy.hpp>

///自定义的对话框
#include "dlgPassThroughFilter.h"
#include "dlgIntensityFix.h"
#include "dlgTxt2PCD.h"
#include "dlgPCD2TXT.h"
#include "dlgLAS2TXT.h"
#include "dlgPCDBinary2PCDAscii.h"
#include "dlgKdTreeCluster.h"
#include "dlgAddPointCloud.h"
#include "dlgBinarySignal.h"
#include "dlgTestDialog.h"
#include "dlgMultiViewer.h"
#include "dlgCopyFile.h"

#include "ThreadRGBResampling.h"
#include "ThreadLoadingCloudPoints.h"
#include "ThreadCalcPointCloudMsg.h"
#include "ThreadSaveAs.h"

PCLViewer::PCLViewer(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::PCLViewer)
{
	ui->setupUi(this);

	this->setWindowTitle("PointCloudClassifier@Neverland_LY");
	this->setWindowIcon(QIcon("images/logo.png"));
	this->grabKeyboard(); //具有捕获键盘事件能力

	//初始化
	initPara(); //初始化
	inintTableWidget();  //初始化 QTableWidget
	initConnector();

	qDebug() << ">>> UI-Thread :   " << QThread::currentThread();
}

PCLViewer::~PCLViewer(){
	delete threadDelegater;  ///这个没有指定父对象，所以在关闭主窗口的时候要将其销毁，否则会导致内存泄露
	delete rect;
	delete selectedCloud;
	delete itemModel;

	delete ui;

}

void PCLViewer::initPara(){

	/// UI 界面设置--------------------------------------------------------------------------------

	//初始化窗口，窗口最大化
	desktopRect = QApplication::desktop()->availableGeometry();
	iTitleBarHeight = style()->pixelMetric(QStyle::PM_TitleBarHeight);  // 获取标题栏高度
	setGeometry(0, iTitleBarHeight, desktopRect.width(), desktopRect.height() - iTitleBarHeight);
	resize(desktopRect.width(), desktopRect.height() - iTitleBarHeight);   // 固定窗体大小

	//初始化控制台，输出打印信息
	itemModel = new QStandardItemModel(this);
	ui->listView->setUpdatesEnabled(true);
	ui->listView->setEditTriggers(false);
	ui->listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	logExport(QString::fromLocal8Bit("欢迎使用本软件！"));

	//初始化进度条
	ui->proBar->setValue(0);

	//设置  dockwidget 
	ui->dockWidget1->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	ui->dockWidget2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	ui->dockWidget3->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);

	//初始化 QTreeWidget
	ui->treeWidget->setHeaderHidden(true);
	ui->treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	ui->treeWidget->setHorizontalScrollMode((QAbstractItemView::ScrollPerPixel));
	ui->treeWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui->treeWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	//初始化的默认窗口
	ui->tabWidget->setCurrentIndex(0);

	/// 全局变量设置----------------------------------------------------------------------------------

	//所有线程的初始化工作
	threadGUI = new QThread(this);
	threadDelegater = new ThreadDelegate;
	threadDelegater->moveToThread(threadGUI);
	threadGUI->start();

	//初始化点云大小
	pointSize = 1;

	//初始化默认选择的点云
	selectedCloud = nullptr;

	//初始化 viewer
	viewer1.reset(new pcl::visualization::PCLVisualizer("3D Viewer1", false)); //false 不显示窗口
	viewer2.reset(new pcl::visualization::PCLVisualizer("3D Viewer2", false));
	viewer3.reset(new pcl::visualization::PCLVisualizer("3D Viewer3", false));

	//设置背景色
	viewer1->setBackgroundColor(0, 0, 0);
	viewer2->setBackgroundColor(0, 0, 0);
	viewer3->setBackgroundColor(0, 0, 0);

	//vuewer 和 VTK 的关联
	ui->qvtkWidget1->SetRenderWindow(viewer1->getRenderWindow());
	ui->qvtkWidget2->SetRenderWindow(viewer2->getRenderWindow());
	ui->qvtkWidget3->SetRenderWindow(viewer3->getRenderWindow());

	//注册鼠标键盘事件
	//viewer1->registerKeyboardCallback(keyboardEventOccurred);
	//viewer1->registerMouseCallback(mouseEventOccurred);

	//设置VTK窗口接口
	viewer1->setupInteractor(ui->qvtkWidget1->GetInteractor(), ui->qvtkWidget1->GetRenderWindow());
	viewer2->setupInteractor(ui->qvtkWidget2->GetInteractor(), ui->qvtkWidget2->GetRenderWindow());
	viewer3->setupInteractor(ui->qvtkWidget3->GetInteractor(), ui->qvtkWidget3->GetRenderWindow());

	//给点云添加柱状坐标参考
	viewer1->addCoordinateSystem(0.5);
	viewer2->addCoordinateSystem(0.5);
	viewer3->addCoordinateSystem(0.5);

	//预加载点云文件
	pclLogo.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
	if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("../init/PCL.pcd", *pclLogo) == -1){
		std::cout << ">>> The PCL-logo point cloud is loading failed ...\n";
	}
	else{
		viewer1->addPointCloud<pcl::PointXYZRGB >(pclLogo, "PCL-LOGO");
	}

	//重置相机参数
	viewer1->resetCamera(); viewer2->resetCamera(); viewer3->resetCamera();

	//隐藏FPS
	viewer1->setShowFPS(false); viewer2->setShowFPS(false); viewer3->setShowFPS(false);

	//刷新窗口
	ui->qvtkWidget1->update(); ui->qvtkWidget2->update(); ui->qvtkWidget3->update();

}

void PCLViewer::inintTableWidget(){

	//初试列表项
	vecTable.push_back(QString::fromLocal8Bit("点云属性"));  // 0
	vecTable.push_back(QString::fromLocal8Bit("名称"));
	vecTable.push_back(QString::fromLocal8Bit("点大小"));
	vecTable.push_back(QString::fromLocal8Bit("数量"));
	vecTable.push_back(QString::fromLocal8Bit("最小点"));
	vecTable.push_back(QString::fromLocal8Bit("最大点"));
	vecTable.push_back(QString::fromLocal8Bit("X 范围"));
	vecTable.push_back(QString::fromLocal8Bit("Y 范围"));
	vecTable.push_back(QString::fromLocal8Bit("Z 范围"));
	vecTable.push_back(QString::fromLocal8Bit("重心"));
	vecTable.push_back(QString::fromLocal8Bit("中心"));
	vecTable.push_back(QString::fromLocal8Bit("其他"));  //11

	vecTable.push_back(QString::fromLocal8Bit("其他相关属性")); // 12
	vecTable.push_back(QString::fromLocal8Bit("路径"));
	vecTable.push_back(QString::fromLocal8Bit("颜色"));

	//设置列表相关属性
	ui->tableWidget->setRowCount(vecTable.size()); //行数  15
	ui->tableWidget->setColumnCount(2); //列数
	ui->tableWidget->verticalHeader()->setDefaultSectionSize(25); //行高
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑
	ui->tableWidget->horizontalHeader()->setVisible(false); //设置表头不可点击（默认点击后进行排序）
	ui->tableWidget->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
	ui->tableWidget->setShowGrid(false); //设置不显示格子线
	ui->tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见
	ui->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:20px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");
	ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 20px;}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:gray;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");

	ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	//ui->tableWidget->setHorizontalScrollMode((QAbstractItemView::ScrollPerPixel));

	ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu); //右键菜单的实现

	//填充QTableWidget
	for (int i = 0; i < vecTable.size(); i++){
		if (i == 0 || i == 12){
			QTableWidgetItem * item1 = new QTableWidgetItem(vecTable[i]);
			QTableWidgetItem * item2 = new QTableWidgetItem("");
			item1->setBackgroundColor(QColor(54, 54, 54)); item1->setTextColor(QColor(255, 255, 255));
			item2->setBackgroundColor(QColor(54, 54, 54)); item2->setTextColor(QColor(255, 255, 255));

			ui->tableWidget->setItem(i, 0, item1);
			ui->tableWidget->setItem(i, 1, item2);
		}
		else{
			if (i % 2 == 0){
				QTableWidgetItem * item1 = new QTableWidgetItem(vecTable[i]);
				QTableWidgetItem * item2 = new QTableWidgetItem("");
				item1->setBackgroundColor(QColor(238, 233, 233));
				item2->setBackgroundColor(QColor(238, 233, 233));
				ui->tableWidget->setItem(i, 0, item1);
				ui->tableWidget->setItem(i, 1, item2);
			}
			else{
				ui->tableWidget->setItem(i, 0, new QTableWidgetItem(vecTable[i]));
				ui->tableWidget->setItem(i, 1, new QTableWidgetItem(""));
			}
		}
	}

	ui->tableWidget->resizeColumnToContents(0);
	ui->tableWidget->resizeColumnToContents(1);
}

void PCLViewer::initConnector(){

	///代理线程关联
	connect(this, &PCLViewer::delegaterStartRunTask, threadDelegater, &ThreadDelegate::runManageThread);
	connect(threadDelegater, &ThreadDelegate::signalBarValue, this, &PCLViewer::setBarValue);

	///关联 Qtreewidget 的单击和双击响应事件
	connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(treeItemSelected(QTreeWidgetItem*, int)));
	connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(showSelectedItemCloud(QTreeWidgetItem*, int)));

	///设置tablewidget的右键菜单
	connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showMenu(QPoint)));

	///关联【文件】的操作事件
	connect(ui->action_open, SIGNAL(triggered()), this, SLOT(actionOpenFile()));
	connect(ui->action_saveas, SIGNAL(triggered()), this, SLOT(actionSaveAs()));
	connect(ui->action_exit, SIGNAL(triggered()), this, SLOT(actionExit()));

	//关联【工具】的操作事件
	connect(ui->action_zoomin, SIGNAL(triggered()), this, SLOT(actionZoomIn()));
	connect(ui->action_zoomout, SIGNAL(triggered()), this, SLOT(actionZoomOut()));
	connect(ui->action_zoom, SIGNAL(triggered()), this, SLOT(actionZoom()));
	connect(ui->action_compress, SIGNAL(triggered()), this, SLOT(actionCompressCloud()));
	connect(ui->action_cluster, SIGNAL(triggered()), this, SLOT(actionClusteCloud()));
	connect(ui->action_KNN, SIGNAL(triggered()), this, SLOT(actionKdtreeKNN()));
	connect(ui->action_Radius, SIGNAL(triggered()), this, SLOT(actionKdtreeRadius()));
	connect(ui->action_voxel, SIGNAL(triggered()), this, SLOT(actionVoxelization()));
	connect(ui->action_trim, SIGNAL(triggered()), this, SLOT(actionTrimCloud()));
	connect(ui->action_screenshot, SIGNAL(triggered()), this, SLOT(actionScreenShot()));
	connect(ui->action_copy, &QAction::triggered, [=](){
		dlgCopyFile * t = new dlgCopyFile(this);
		t->setAttribute(Qt::WA_DeleteOnClose);
		t->exec();
	});

	//关联【滤波】的操作事件
	connect(ui->action_pass, SIGNAL(triggered()), this, SLOT(actionPassThroughFilter()));
	connect(ui->action_voxelgrid, SIGNAL(triggered()), this, SLOT(actionVoxelCloud()));
	connect(ui->action_outliner, SIGNAL(triggered()), this, SLOT(actionOutlinerRemove()));
	connect(ui->action_project, SIGNAL(triggered()), this, SLOT(actionProjection()));
	connect(ui->action_cloud2grayimage, SIGNAL(triggered()), this, SLOT(actionGrayImage()));
	connect(ui->action_vegetation, &QAction::triggered, [=](){
		/*if (selectedRgbCloud == NULL)
			return;*/
		logExport(QString::fromLocal8Bit("开始进行植被分离..."));
		//emit delegaterStartRunTask(LY::FilterVegetation, *selectedRgbCloud, vecPara);
	});

	//关联【视图】的操作事件
	connect(ui->action_viewer1, SIGNAL(triggered()), this, SLOT(actionViewer1()));
	connect(ui->action_viewer2, SIGNAL(triggered()), this, SLOT(actionViewer2()));
	connect(ui->action_viewer4, SIGNAL(triggered()), this, SLOT(actionViewer4()));
	connect(ui->action_fullscreen, &QAction::triggered,
		[=](){
		/*if (ui->tabWidget->currentIndex() == 0)
			viewer1->setFullScreen(true);
			if (ui->tabWidget->currentIndex() == 1)
			viewer2->setFullScreen(true);
			if (ui->tabWidget->currentIndex() == 2)
			viewer3->setFullScreen(true);*/
	}
	);
	connect(ui->action_coordinate, &QAction::triggered,
		[=](){
		pcl::ModelCoefficients coeffs;
		coeffs.values.push_back(0.0);
		coeffs.values.push_back(0.0);
		coeffs.values.push_back(1.0);
		coeffs.values.push_back(0.0);
		viewer1->addPlane(coeffs, "PLANE-Z-0");
		viewer1->resetCamera();
		ui->qvtkWidget1->update();
	}
	);

	//关联【数据转换】的操作事件
	connect(ui->action_las2txt, SIGNAL(triggered()), this, SLOT(actionLAS2TXT()));
	connect(ui->action_txt2pcd, SIGNAL(triggered()), this, SLOT(actionTXT2PCDASCII()));
	connect(ui->action_pcdb2pcda, SIGNAL(triggered()), this, SLOT(actionPCDBINARY2PCDASCII()));
	connect(ui->action_pcd2txt, SIGNAL(triggered()), this, SLOT(actionPCDASCII2TXT()));

	//关联【雷达数据处理】的操作事件
	connect(ui->action_fixintensity_2, SIGNAL(triggered()), this, SLOT(actionIntensityFix()));
	connect(ui->action_kdtree_2, SIGNAL(triggered()), this, SLOT(actionKdTreeCluster()));
	connect(ui->action_binarysignal_2, SIGNAL(triggered()), this, SLOT(actionBinarySignal()));
	connect(ui->action_image2cloud, SIGNAL(triggered()), this, SLOT(actionImage2Cloud()));
	connect(ui->action_rgbresampling, &QAction::triggered, [=](){
		ThreadRGBResampling * tResampling = new ThreadRGBResampling;
		connect(tResampling, &ThreadRGBResampling::finished, tResampling, &QObject::deleteLater);
		tResampling->start();
	});

	

	//关联【关于】的操作事件
	connect(ui->action_setting, SIGNAL(triggered()), this, SLOT(actionSetting()));
	connect(ui->action_about, SIGNAL(triggered()), this, SLOT(actionAbout()));
	connect(ui->action_help, SIGNAL(triggered()), this, SLOT(actionHelp()));
	connect(ui->action_beta, &QAction::triggered, [=](){

		///测试区域------------------------------------------





		///测试结束----------------------------------------------
	});

}

///【文件】操作函数 ----------------------------------------------------------------------------------

void PCLViewer::actionOpenFile(){
	///启动线程
	ThreadLoadingCloudPoints * tLoading = new ThreadLoadingCloudPoints; ///默认就是空指针
	connect(tLoading, &ThreadLoadingCloudPoints::submitCloud, this, &PCLViewer::addNewPointCloud);
	connect(tLoading, &ThreadLoadingCloudPoints::finished, tLoading, &QObject::deleteLater);
	///启动窗口
	dlgAddPointCloud *t = new dlgAddPointCloud(this, tLoading); ///线程的引用传递
	connect(tLoading, &ThreadLoadingCloudPoints::msgBarValue, t, &dlgAddPointCloud::setValue);
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

void PCLViewer::addNewPointCloud(LY::XYZRGBCloud cloud){
	///判断是否已经存在该点云
	if (mapXYZRGB.contains(cloud.name) == true){ ///如果添加的点云已经存在
		QMessageBox::information(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("您添加的点云已经存在，请修改文件名后重新添加。"));
		return;
	}

	///更新点云列表
	QTreeWidgetItem *item = new QTreeWidgetItem;
	item->setText(0, cloud.name);
	ui->treeWidget->addTopLevelItem(item);
	QTreeWidgetItem *itemChild = new QTreeWidgetItem;
	itemChild->setText(0, cloud.name);
	ui->treeWidget->topLevelItem(mapXYZRGB.size())->addChild(itemChild);
	ui->treeWidget->topLevelItem(mapXYZRGB.size())->setExpanded(true);
	itemChild->setCheckState(0, Qt::Checked);

	///更新选项
	vecCloud.push_back(cloud);
	mapXYZRGB.insert(cloud.name, cloud.path); ///更新 mapXYZRGB
	selectedCloud = &vecCloud[vecCloud.size() - 1];
	treeItemSelected(ui->treeWidget->topLevelItem(mapXYZRGB.size() - 1)->child(0), 0);

	///显示点云数据 
	viewer1->removePointCloud("PCL-LOGO");  ///首先移除 pcllogo 点云
	viewer1->addPointCloud<pcl::PointXYZRGB>(cloud.cloud, cloud.name.toStdString());
	cloudNumOfViewer1++;  ///更新显示的点云数量
	viewer1->resetCamera();
	ui->qvtkWidget1->update();

	///打印日志
	logExport(QString::fromLocal8Bit("成功添加点云 %1 ( %2 ) ").arg(cloud.name).arg(cloud.path));

}

void PCLViewer::showSelectedItemCloud(QTreeWidgetItem* item, int column){

	if (item->parent() == NULL)  ///点击顶层窗口无效
		return;

	if (item->checkState(0) == Qt::Checked){
		item->setCheckState(0, Qt::Unchecked);
		viewer1->removePointCloud(item->text(0).toStdString());
		viewer1->resetCamera();
		ui->qvtkWidget1->update();
		cloudNumOfViewer1--;
	}
	else{
		item->setCheckState(0, Qt::Checked);
		std::vector<LY::XYZRGBCloud>::iterator it;
		for (it = vecCloud.begin(); it != vecCloud.end(); it++){
			if (it->name == item->text(0)){
				viewer1->addPointCloud(it->cloud, it->name.toStdString());
				///添加包围矩形
				//pcl::PointXYZRGB minPt, maxPt;
				//pcl::getMinMax3D(*(it->cloud), minPt, maxPt);
				viewer1->resetCamera();
				ui->qvtkWidget1->update();
				cloudNumOfViewer1++;
				break;
			}
		}
	}

	if (cloudNumOfViewer1 == 0){
		viewer1->addPointCloud<pcl::PointXYZRGB >(pclLogo, "PCL-LOGO");
		viewer1->resetCamera();
		ui->qvtkWidget1->update();
	}
	else{
		viewer1->removePointCloud("PCL-LOGO");
	}
}

void PCLViewer::treeItemSelected(QTreeWidgetItem* item, int column){

	///点击顶层列表项无效
	if (item->parent() == nullptr)
		return;

	///返回选中了哪个点云数据，直接操作点云
	int count = 0;
	for (std::vector<LY::XYZRGBCloud>::iterator i = vecCloud.begin(); i != vecCloud.end(); i++){
		if (i->name == item->text(0)){
			selectedCloud = &vecCloud[count];
			break;
		}
		count++;
	}

	///创建线程计算点云相关信息
	/*ThreadCalcPointCloudMsg * tCalc = new ThreadCalcPointCloudMsg(NULL);
	tCalc->cloud = selectedCloud;
	connect(tCalc, &ThreadCalcPointCloudMsg::submitMsg, this, &PCLViewer::updateAttributes);
	connect(tCalc, &ThreadCalcPointCloudMsg::submitMsg, tCalc, &QObject::deleteLater);
	tCalc->start();*/

	///更改选中的颜色
	QTreeWidgetItemIterator it(ui->treeWidget);
	while (*it){
		(*it)->setBackgroundColor(0, QColor(255, 255, 255));
		for (int i = 0; i < (*it)->childCount(); i++){
			(*it)->child(i)->setBackgroundColor(0, QColor(255, 255, 255));
		}
		++it;
	}

	item->setBackgroundColor(0, QColor(255, 248, 220)); /// 調試顏色

	///打印消息
	logExport(QString::fromLocal8Bit("您将要对点云 %1 进行操作").arg(item->text(0)));
}

void PCLViewer::updateAttributes(std::vector<QString> vec){

	logExport(QString::fromLocal8Bit("我被拦截了..."));

	return;

	///开始填充
	for (int i = 0; i < vec.size(); i++){
		if (i == 0 || i == vec.size() - 3)
			continue;
		ui->tableWidget->item(i, 1)->setText(vec[i]);
	}

	///重新布置局面
	ui->tableWidget->resizeColumnToContents(0);
	ui->tableWidget->resizeColumnToContents(1);

	///打印消息
	logExport(QString::fromLocal8Bit("点云信息已更新"));
}

void PCLViewer::actionSaveAs(){

	return;

	if (selectedCloud == nullptr)
		return;

	///选择文件
	QString path= QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("点云保存路径"), QString("C:/"), "TXT(.txt) ;; PCD(*.pcd)");

	if (path.isEmpty())
		return;

	///创建保存点云线程
	ThreadSaveAs * tSave = new ThreadSaveAs(NULL);
	connect(tSave, &ThreadSaveAs::submitMsg, [=](){
		logExport(QString::fromLocal8Bit("保存成功保存到本地"));
	});
	connect(tSave, &ThreadSaveAs::submitMsg, tSave, &QObject::deleteLater);

	///赋值
	tSave->cc = selectedCloud; ///直接传递指针好像有问题
	tSave->path = path;

	///开始保存点云
	tSave->start();
}

void PCLViewer::actionExit(){
	QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(1);
	animation->setEndValue(0.5);
	animation->start();
	this->close();
}

///【工具】操作函数-----------------------------------------------------------------------------------

void PCLViewer::actionZoomIn(){}

void PCLViewer::actionZoomOut(){}

void PCLViewer::actionZoom(){}

void PCLViewer::actionCompressCloud(){}

void PCLViewer::actionClusteCloud(){}

void PCLViewer::actionKdtreeKNN(){}

void PCLViewer::actionKdtreeRadius(){}

void PCLViewer::actionVoxelization(){}

void PCLViewer::actionTrimCloud(){}

void PCLViewer::actionScreenShot(){
	QString path;
	while (1){
		path = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("截屏保存路径"), QString("C:/"), "PNG(*.png)");
		if (path == NULL)
			continue;
		break;
	}

	if (ui->tabWidget->currentIndex() == 0)
		viewer1->saveScreenshot(path.toStdString());
	if (ui->tabWidget->currentIndex() == 1)
		viewer2->saveScreenshot(path.toStdString());
	if (ui->tabWidget->currentIndex() == 2)
		viewer3->saveScreenshot(path.toStdString());
};

///【滤波】操作函数-----------------------------------------------------------------------------------

void PCLViewer::actionPassThroughFilter(){


	dlgPassThroughFilter * psfilter = new dlgPassThroughFilter(*selectedCloud, this);
	psfilter->setAttribute(Qt::WA_DeleteOnClose);
	psfilter->exec();
}

void PCLViewer::actionVoxelCloud(){}

void PCLViewer::actionOutlinerRemove(){}

void PCLViewer::actionProjection(){}

void PCLViewer::actionGrayImage(){
	dlgTestDialog * t = new dlgTestDialog;
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

///【视图】响应函数----------------------------------------------------------------------------------

void PCLViewer::actionViewer1(){
	dlgMultiViewer * tp = new dlgMultiViewer(0, mapXYZRGB, this);
	connect(tp, &dlgMultiViewer::signalMap, this, &PCLViewer::showMultiCloud);
	tp->setAttribute(Qt::WA_DeleteOnClose);
	tp->exec();
}

void PCLViewer::actionViewer2(){
	dlgMultiViewer * tp = new dlgMultiViewer(1, mapXYZRGB, this);
	connect(tp, &dlgMultiViewer::signalMap, this, &PCLViewer::showMultiCloud);
	tp->setAttribute(Qt::WA_DeleteOnClose);
	tp->exec();
}

void PCLViewer::actionViewer4(){
	dlgMultiViewer * tp = new dlgMultiViewer(2, mapXYZRGB, this);
	connect(tp, &dlgMultiViewer::signalMap, this, &PCLViewer::showMultiCloud);
	tp->setAttribute(Qt::WA_DeleteOnClose);
	tp->exec();
}

///【数据转换】响应函数----------------------------------------------------------------------------

void PCLViewer::actionLAS2TXT(){
	dlgLAS2TXT *t = new dlgLAS2TXT(this);
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

void PCLViewer::actionTXT2PCDASCII(){
	dlgTxt2PCD * tp = new dlgTxt2PCD(this);
	tp->setAttribute(Qt::WA_DeleteOnClose);
	tp->exec();
}

void PCLViewer::actionPCDBINARY2PCDASCII(){
	//QMessageBox::information(this, "Information", "This function is temporarily not open to the outside world, thanks !");
	dlgPCDBinary2PCDAscii * t = new dlgPCDBinary2PCDAscii(this);
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

void PCLViewer::actionPCDASCII2TXT(){
	dlgPCD2TXT * tp = new dlgPCD2TXT(this);
	tp->setAttribute(Qt::WA_DeleteOnClose);
	tp->exec();
}

///【雷达数据处理】响应函数---------------------------------------------------------------------------

void PCLViewer::actionIntensityFix(){
	dlgIntensityFix *fix = new dlgIntensityFix(this);
	fix->setAttribute(Qt::WA_DeleteOnClose);
	fix->exec();
}

void PCLViewer::actionKdTreeCluster(){
	dlgKdTreeCluster * t = new dlgKdTreeCluster(this);
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

void PCLViewer::actionBinarySignal(){
	dlgBinarySignal *t = new dlgBinarySignal;
	t->setAttribute(Qt::WA_DeleteOnClose);
	t->exec();
}

void PCLViewer::actionImage2Cloud(){}

///【帮助】响应函数--------------------------------------------------------------------------------

void PCLViewer::actionSetting(){}

void PCLViewer::actionAbout(){}

void PCLViewer::actionHelp(){}

///共有函数----------------------------------------------------------------------------------------

void PCLViewer::setBarValue(LY::THREAD_TYPE type, int value){
	ui->proBar->setValue(value);
	switch (type)
	{
	case LY::ToolPression:
		break;
	case LY::ToolCluster:
		break;
	case LY::ToolKdTreeK:
		break;
	case LY::ToolKdTreeRadius:
		break;
	case LY::FilterPassThrough:
		break;
	case LY::FilterVoxelGrid:
		break;
	case LY::FilterStaticalOutlinerRemoval:
		break;
	case LY::FilterProjection:
		break;
	case LY::FilterGray2Image:
		break;
	case LY::FilterVegetation:
		logExport("Vegetation successful");
		break;
	case LY::ConvertLas2Txt:
		break;
	case LY::ConvertTxt2Pcd:
		break;
	case LY::ConvertPcd2Pcd:
		break;
	case LY::ConvertPcd2Txt:
		break;
	case LY::LasFix:
		break;
	case LY::LasKdTree:
		break;
	case LY::LasBinarySignal:
		break;
	case LY::LasImage2Cloud:
		break;
	default:
		break;
	}

}

void PCLViewer::showMultiCloud(std::vector<QString> vec){

	if (vec.size() == 1){
		ui->tabWidget->setCurrentIndex(0);
		std::vector<LY::XYZRGBCloud>::iterator it;
		for (it = vecCloud.begin(); it != vecCloud.end(); it++){
			if (it->name == vec[0]){
				viewer1->addPointCloud<pcl::PointXYZRGB>(it->cloud, it->name.toStdString());
				break;
			}
		}
		viewer1->resetCamera();
		ui->qvtkWidget1->update();
	}
	else if (vec.size() == 2){
		ui->tabWidget->setCurrentIndex(1);
		std::vector<LY::XYZRGBCloud>::iterator it;
		for (it = vecCloud.begin(); it != vecCloud.end(); it++){
			static int count;
			if (it->name == vec[0]){
				int v1(0);
				viewer2->createViewPort(0.0, 0.0, 0.5, 1.0, v1);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer2->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v1);
				count++;
			}
			if (it->name == vec[1]){
				int v2(0);
				viewer2->createViewPort(0.5, 0.0, 1.0, 1.0, v2);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer2->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v2);
				count++;
			}
			if (count == 2)
				break;
		}
		viewer2->resetCamera();
		ui->qvtkWidget2->update();
	}
	else if (vec.size() == 4){
		ui->tabWidget->setCurrentIndex(2);
		std::vector<LY::XYZRGBCloud>::iterator it;
		for (it = vecCloud.begin(); it != vecCloud.end(); it++){
			static int count;
			if (it->name == vec[0]){
				int v1(0);
				viewer3->createViewPort(0.0, 0.0, 0.5, 0.5, v1);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer3->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v1);
				count++;
			}
			if (it->name == vec[1]){
				int v2(0);
				viewer3->createViewPort(0.5, 0.0, 1.0, 0.5, v2);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer3->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v2);
				count++;
			}
			if (it->name == vec[2]){
				int v3(0);
				viewer3->createViewPort(0.0, 0.5, 0.5, 1.0, v3);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer3->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v3);
				count++;
			}
			if (it->name == vec[3]){
				int v4(0);
				viewer3->createViewPort(0.5, 0.5, 1.0, 1.0, v4);
				pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(it->cloud);
				viewer3->addPointCloud<pcl::PointXYZRGB>(it->cloud, rgb, it->name.toStdString(), v4);
				count++;
			}
			if (count == 4)
				break;
		}
		viewer3->resetCamera();
		ui->qvtkWidget3->update();
	}
}

bool PCLViewer::event(QEvent *event){

	if (event->type() == QEvent::NonClientAreaMouseButtonDblClick){  ///放大
		if (this->width() < desktopRect.width() || this->height() < desktopRect.height() - iTitleBarHeight){
			resize(desktopRect.width(), desktopRect.height() - iTitleBarHeight);   // 固定窗体大小;
			this->move(0, 0);
		}
		else{ ///缩小
			resize(desktopRect.width() / 3 * 2, (desktopRect.height() - iTitleBarHeight) / 3 * 2);
			this->move((desktopRect.width() - this->width()) / 2, (desktopRect.height() - iTitleBarHeight - this->height()) / 2);
		}
	}

	return QWidget::event(event);
}

void PCLViewer::closeEvent(QCloseEvent *event){
	QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(1);
	animation->setEndValue(0.5);
	animation->start();
	auto temp = QMessageBox::warning(this, QString::fromLocal8Bit("退出"),
		QString::fromLocal8Bit("你确定要退出软件吗？"), QMessageBox::Yes | QMessageBox::No);
	if (temp == QMessageBox::Yes){
		event->accept();
	}
	else{
		event->ignore();
		QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
		animation->setDuration(500);
		animation->setStartValue(0.5);
		animation->setEndValue(1);
		animation->start();
	}
}

void PCLViewer::mouseMoveEvent(QMouseEvent *event){
	/*if (event->buttons() == Qt::LeftButton){
		resize(desktopRect.width() / 3 * 2, (desktopRect.height() - iTitleBarHeight) / 3 * 2);
		}*/
}

void PCLViewer::keyPressEvent(QKeyEvent *event){
	if (event->key() == Qt::Key_Escape){

		viewer1->setFullScreen(false);
		/*viewer2->setFullScreen(false);
		viewer3->setFullScreen(false);*/
	}
	QWidget::keyPressEvent(event);
}

void PCLViewer::logExport(QString qstr){
	QDateTime dt = QDateTime::currentDateTime();
	QString time = dt.toString("[ yyyy-MM-dd  hh:mm:ss ]   ");
	qstr = time + qstr;
	QStandardItem *item = new QStandardItem(qstr);
	if (consoleList.size() % 2 == 1){
		QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
		linearGrad.setColorAt(0, QColor(255, 248, 220));
		QBrush brush(linearGrad);
		item->setBackground(brush);
	}
	itemModel->appendRow(item);
	ui->listView->setModel(itemModel);
	ui->listView->scrollToBottom();
	consoleList.append(qstr);
}

void PCLViewer::showMenu(QPoint pos)
{
	logExport(QString::fromLocal8Bit("请选择 增加 / 减小 点云大小或打开点云文件路径"));

	//设置菜单选项 
	QMenu *menu = new QMenu(ui->tableWidget);
	QAction * action1 = new QAction(QString::fromLocal8Bit("点云大小增加"), ui->tableWidget);
	QAction * action2 = new QAction(QString::fromLocal8Bit("点云大小减小"), ui->tableWidget);
	QAction * action3 = new QAction(QString::fromLocal8Bit("打开点云文件路径"), ui->tableWidget);

	connect(action1, &QAction::triggered,
		[=](){
		pointSize++;
		viewer1->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, selectedCloud->name.toStdString());
		ui->qvtkWidget1->update();
	});

	connect(action2, &QAction::triggered,
		[=](){
		if (pointSize == 1)
			return;
		pointSize--;
		viewer1->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, selectedCloud->name.toStdString());
		ui->qvtkWidget1->update();
	});

	connect(action3, &QAction::triggered,
		[=](){
		std::string str = selectedCloud->path.toStdString();
		std::string delstr = selectedCloud->name.toStdString();
		str = str.substr(0, str.length() - delstr.length());
		QDesktopServices::openUrl(QString::fromStdString(str));
	});

	menu->addAction(action1);
	menu->addAction(action2);
	menu->addSeparator();
	menu->addAction(action3);

	menu->move(cursor().pos());
	menu->show();

	//获得鼠标点击的x，y坐标点 
	int x = pos.x();
	int y = pos.y();
	QModelIndex index = ui->tableWidget->indexAt(QPoint(x, y));
	int row = index.row();//获得QTableWidget列表点击的行数 
}

void PCLViewer::keyboardEventOccurred(const pcl::visualization::KeyboardEvent &event, void* viewer_void)
{
	if (event.getKeySym() == "r" && event.keyDown())
	{
		logExport("r is presed");
	}
}

void PCLViewer::mouseEventOccurred(const pcl::visualization::MouseEvent &event, void* viewer_void){
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer = *static_cast<boost::shared_ptr<pcl::visualization::PCLVisualizer> *> (viewer_void);
	if (event.getButton() == pcl::visualization::MouseEvent::LeftButton && event.getType() == pcl::visualization::MouseEvent::MouseButtonRelease)
		return;

}


#if 0
QMessageBox::critical(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("路径不能为空！！！"), QMessageBox::Yes, QMessageBox::Yes);
#endif
