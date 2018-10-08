#pragma once

#include <QDialog>
#include <QWidget>
#include <QDialog>
#include <QThread>
#include <QKeyEvent>

namespace Ui { class dlgCopyFile; };

class dlgCopyFile : public QDialog
{
	Q_OBJECT

public:
	dlgCopyFile(QWidget *parent = Q_NULLPTR);
	~dlgCopyFile();

	void keyPressEvent(QKeyEvent *);
	QString replaceSymbol(std::string &str);

	
	QString file_name;

public slots:
	void toolClicked1();
	void toolClicked2();

	void convertButton();

private:
	Ui::dlgCopyFile *ui;
};
