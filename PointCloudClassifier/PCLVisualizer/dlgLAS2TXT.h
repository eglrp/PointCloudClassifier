#pragma once

#include <QDialog>
#include <QKeyEvent>


namespace Ui { class dlgLAS2TXT; };

class dlgLAS2TXT : public QDialog
{
	Q_OBJECT

public:
	dlgLAS2TXT(QWidget *parent = Q_NULLPTR);
	~dlgLAS2TXT();

	void keyPressEvent(QKeyEvent *);

public slots:
	void toolButtonClicked();
	void pushButtonClicked();

private:
	Ui::dlgLAS2TXT *ui;
};
