#include "ThreadBinarySignal.h"

ThreadBinarySignal::ThreadBinarySignal(QObject *parent)
	: QObject(parent)
{
}

ThreadBinarySignal::~ThreadBinarySignal()
{
}
void ThreadBinarySignal::runTask(){
	///核心处理函数

	emit finishConvert();
}
