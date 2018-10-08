#include "pclviewer.h"
#include <QApplication>
#include <QMainWindow>
#include <qsplashscreen.h>
#include <qpixmap.h>
#include <qelapsedtimer.h>
#include <qtextcodec.h>
#include <QMap>

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//注册数据类型
	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGBA>>("pcl::PointCloud<pcl::PointXYZRGBA>");  
	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGBA>>("pcl::PointCloud<pcl::PointXYZRGBA>&");  

	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZI>>("pcl::PointCloud<pcl::PointXYZI>");
	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZI>>("pcl::PointCloud<pcl::PointXYZI>&");

	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr");
	qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr&");

	qRegisterMetaType<LY::XYZRGBCloud>("LY::XYZRGBCloud");
	qRegisterMetaType<LY::XYZRGBCloud>("LY::XYZRGBCloud&");

	qRegisterMetaType<LY::THREAD_TYPE>("LY::THREAD_TYPE");
	qRegisterMetaType<LY::THREAD_TYPE>("LY::THREAD_TYPE&");

	qRegisterMetaType<QString>("QString");
	qRegisterMetaType<QString>("QString&");

	qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>");
	qRegisterMetaType<QMap<QString, QString>>("QMap<QString, QString>&");

	qRegisterMetaType<std::vector<QString>>("std::vector<QString>");
	qRegisterMetaType<std::vector<QString>>("std::vector<QString>&");

	qRegisterMetaType<float>("float");
	qRegisterMetaType<float>("float&");

	qRegisterMetaType<int>("int");
	qRegisterMetaType<int>("int&");

	//设置程序的默认字符编码
	///QTextCodec *tc = QTextCodec::codeForName("utf*8");
	///QTextCodec::setCodecForTr(tc);

	QSplashScreen splash(QPixmap("images/trademark1.png"));
	splash.setDisabled(true);
	splash.show();

	//WinExec("\"F:\\Project_CPlus\\PCLCLustering\\x64\\Release\\BGMSound.exe\"", 1);
	WinExec("\"../BGMSound.exe\"", 1);


	QElapsedTimer t;
	t.start();
	while (t.elapsed() < 4000){
		QCoreApplication::processEvents();
	}

	
	PCLViewer w;
	//w.showMaximized();
	w.show();

	splash.finish(&w);

	return a.exec(); 
}