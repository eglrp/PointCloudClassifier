#include "ThreadDelegate.h"
#include <QDebug>

ThreadDelegate::ThreadDelegate(QObject *parent)
: QObject(parent)
{

}

ThreadDelegate::~ThreadDelegate()
{
	qDebug() << "~ThreadDelegate";
}

void ThreadDelegate::runManageThread(LY::THREAD_TYPE type, LY::XYZRGBCloud & cloud, std::vector<QString> vecPara){

	qDebug() << ">>> ThreadDelegate :   " << QThread::currentThread();

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
		qDebug() << "~Create filter";

		ThreadFilterVegetation *filterVege;
		filterVege = new ThreadFilterVegetation(this);
		connect(this, &ThreadDelegate::signalRunTask, filterVege, &ThreadFilterVegetation::runTask);
		connect(filterVege, &ThreadFilterVegetation::signalBarValue, this, &ThreadDelegate::signalBarValue);

		emit signalRunTask(cloud, vecPara);

		return;

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


