#pragma once

#include <QObject>

class ThreadPCD2TXT : public QObject
{
	Q_OBJECT

public:
	ThreadPCD2TXT(QObject *parent = 0);
	~ThreadPCD2TXT();

	void runTask();

	std::string SRC_PATH;
	std::string DEST_PATH;

signals :
	void changeBar(int value);
	void finishConvert();
	

};
