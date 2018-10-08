#pragma once

#include <QDialog>
#include <QMap>
#include <QKeyEvent>

namespace Ui { class dlgMultiViewer; };

class dlgMultiViewer : public QDialog
{
	Q_OBJECT

public:
	dlgMultiViewer(int viewType, QMap<QString, QString> &qmap, QWidget *parent = Q_NULLPTR);
	~dlgMultiViewer();

	void keyPressEvent(QKeyEvent *);

public slots:
	void btnClicked();

signals:
	void signalMap(std::vector<QString>);

private:
	Ui::dlgMultiViewer *ui;

	int type;
	QMap<QString,QString> map;
	std::vector<QString> vec;
};
