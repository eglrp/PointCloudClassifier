#pragma once

#include <QObject>

class ThreadTXT2PCD : public QObject
{
	Q_OBJECT

public:
	ThreadTXT2PCD(QObject *parent = 0);
	~ThreadTXT2PCD();

	void runTask();

	std::string SRC_PATH;
	std::string DEST_PATH;

signals :
	void finishConvert();
	void changeBar(int value);

private:

};
