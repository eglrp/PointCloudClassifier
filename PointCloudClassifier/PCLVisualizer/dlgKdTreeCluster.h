#pragma once

#include <QDialog>
#include <QThread>
#include <QKeyEvent>

#include "ThreadUnionFind.h"

namespace Ui { class dlgKdTreeCluster; };

class dlgKdTreeCluster : public QDialog
{
	Q_OBJECT

public:
	dlgKdTreeCluster(QWidget *parent = Q_NULLPTR);
	~dlgKdTreeCluster();

	void setBarValue(int value);
	void dealSignalFinished(int &v1, int &v2);

	void keyPressEvent(QKeyEvent *);

public slots:
	void toolClicked1();
	void toolClicked2();

	void rbClicked1();
	void rbClicked2();

	void checkClicked1();
	void checkClicked2();

	void convertButton();

signals:
	void startConvert();


private:
	Ui::dlgKdTreeCluster *ui;

	QThread * thread;
	ThreadUnionFind * convertThread;
};
