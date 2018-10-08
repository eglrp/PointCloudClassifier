#pragma once


#include <QDialog>
#include <QWidget>
#include <QKeyEvent>

namespace Ui { class dlgIntensityFix; };

class dlgIntensityFix : public QDialog
{
	Q_OBJECT

public:
	dlgIntensityFix(QWidget *parent = Q_NULLPTR);
	~dlgIntensityFix();

	void keyPressEvent(QKeyEvent *);

public slots:
	void openFile();
	void on_btnYes_clicked();
	void on_btnNo_clicked();

signals:
	void startFix(QString & ,float &, int & ,float &, float &);

private:
	Ui::dlgIntensityFix *ui;

	QString path;
	float resolution;
	int K;
	float deltaH;
	float deltaIntensity;
};
