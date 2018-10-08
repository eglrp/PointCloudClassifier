#pragma once

#include <QObject>

class ThreadBinarySignal : public QObject
{
	Q_OBJECT

public:
	ThreadBinarySignal(QObject *parent = 0);
	~ThreadBinarySignal();

	void runTask();

	std::string SRC_PATH;
	std::string  DEST_PATH;
	float threshold1, threshold2, threshold3, threshold4;

signals:

	void finishConvert();

};
