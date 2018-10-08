/********************************************************************************
** Form generated from reading UI file 'dlgPCDBinary2PCDAscii.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPCDBINARY2PCDASCII_H
#define UI_DLGPCDBINARY2PCDASCII_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgPCDBinary2PCDAscii
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_2;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *dlgPCDBinary2PCDAscii)
    {
        if (dlgPCDBinary2PCDAscii->objectName().isEmpty())
            dlgPCDBinary2PCDAscii->setObjectName(QStringLiteral("dlgPCDBinary2PCDAscii"));
        dlgPCDBinary2PCDAscii->resize(748, 244);
        gridLayout_4 = new QGridLayout(dlgPCDBinary2PCDAscii);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dlgPCDBinary2PCDAscii);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(dlgPCDBinary2PCDAscii);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton = new QToolButton(dlgPCDBinary2PCDAscii);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout->addWidget(toolButton, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(dlgPCDBinary2PCDAscii);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(dlgPCDBinary2PCDAscii);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);

        toolButton_2 = new QToolButton(dlgPCDBinary2PCDAscii);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        gridLayout_2->addWidget(toolButton_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(dlgPCDBinary2PCDAscii);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 2, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgPCDBinary2PCDAscii);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 1);


        retranslateUi(dlgPCDBinary2PCDAscii);

        QMetaObject::connectSlotsByName(dlgPCDBinary2PCDAscii);
    } // setupUi

    void retranslateUi(QWidget *dlgPCDBinary2PCDAscii)
    {
        dlgPCDBinary2PCDAscii->setWindowTitle(QApplication::translate("dlgPCDBinary2PCDAscii", "PCD(Binary)\350\275\254PCD(ASCII) ", 0));
        label->setText(QApplication::translate("dlgPCDBinary2PCDAscii", "\350\257\267\351\200\211\346\213\251Binary.pcd\346\226\207\344\273\266\350\267\257\345\276\204", 0));
        toolButton->setText(QApplication::translate("dlgPCDBinary2PCDAscii", "...", 0));
        label_2->setText(QApplication::translate("dlgPCDBinary2PCDAscii", "\350\257\267\351\200\211\346\213\251ASCII.pcd \346\226\207\344\273\266\350\267\257\345\276\204", 0));
        toolButton_2->setText(QApplication::translate("dlgPCDBinary2PCDAscii", "...", 0));
        pushButton->setText(QApplication::translate("dlgPCDBinary2PCDAscii", "\345\274\200\345\247\213\350\275\254\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgPCDBinary2PCDAscii: public Ui_dlgPCDBinary2PCDAscii {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPCDBINARY2PCDASCII_H
