#pragma once

#include <QObject>

class ThreadPCD2PCD : public QObject
{
	Q_OBJECT

public:
	ThreadPCD2PCD(QObject *parent = 0);
	~ThreadPCD2PCD();

	void runTask();

	std::string SRC_PATH;
	std::string DEST_PATH;

signals:
	void finishConvert();
	void changeBar(int value);

};
