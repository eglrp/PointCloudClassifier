/********************************************************************************
** Form generated from reading UI file 'dlgTestDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTESTDIALOG_H
#define UI_DLGTESTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_dlgTestDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonGray;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar1;
    QProgressBar *progressBar2;
    QProgressBar *progressBar3;
    QProgressBar *progressBar4;
    QProgressBar *progressBar5;
    QProgressBar *progressBar6;
    QProgressBar *progressBar7;
    QProgressBar *progressBar8;
    QProgressBar *progressBar9;
    QProgressBar *progressBar10;

    void setupUi(QDialog *dlgTestDialog)
    {
        if (dlgTestDialog->objectName().isEmpty())
            dlgTestDialog->setObjectName(QStringLiteral("dlgTestDialog"));
        dlgTestDialog->resize(808, 303);
        gridLayout_2 = new QGridLayout(dlgTestDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonGray = new QPushButton(dlgTestDialog);
        pushButtonGray->setObjectName(QStringLiteral("pushButtonGray"));

        gridLayout->addWidget(pushButtonGray, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        progressBar1 = new QProgressBar(dlgTestDialog);
        progressBar1->setObjectName(QStringLiteral("progressBar1"));
        progressBar1->setValue(24);

        gridLayout_2->addWidget(progressBar1, 1, 0, 1, 1);

        progressBar2 = new QProgressBar(dlgTestDialog);
        progressBar2->setObjectName(QStringLiteral("progressBar2"));
        progressBar2->setValue(24);

        gridLayout_2->addWidget(progressBar2, 2, 0, 1, 1);

        progressBar3 = new QProgressBar(dlgTestDialog);
        progressBar3->setObjectName(QStringLiteral("progressBar3"));
        progressBar3->setValue(24);

        gridLayout_2->addWidget(progressBar3, 3, 0, 1, 1);

        progressBar4 = new QProgressBar(dlgTestDialog);
        progressBar4->setObjectName(QStringLiteral("progressBar4"));
        progressBar4->setValue(24);

        gridLayout_2->addWidget(progressBar4, 4, 0, 1, 1);

        progressBar5 = new QProgressBar(dlgTestDialog);
        progressBar5->setObjectName(QStringLiteral("progressBar5"));
        progressBar5->setValue(24);

        gridLayout_2->addWidget(progressBar5, 5, 0, 1, 1);

        progressBar6 = new QProgressBar(dlgTestDialog);
        progressBar6->setObjectName(QStringLiteral("progressBar6"));
        progressBar6->setValue(24);

        gridLayout_2->addWidget(progressBar6, 6, 0, 1, 1);

        progressBar7 = new QProgressBar(dlgTestDialog);
        progressBar7->setObjectName(QStringLiteral("progressBar7"));
        progressBar7->setValue(24);

        gridLayout_2->addWidget(progressBar7, 7, 0, 1, 1);

        progressBar8 = new QProgressBar(dlgTestDialog);
        progressBar8->setObjectName(QStringLiteral("progressBar8"));
        progressBar8->setValue(24);

        gridLayout_2->addWidget(progressBar8, 8, 0, 1, 1);

        progressBar9 = new QProgressBar(dlgTestDialog);
        progressBar9->setObjectName(QStringLiteral("progressBar9"));
        progressBar9->setValue(24);

        gridLayout_2->addWidget(progressBar9, 9, 0, 1, 1);

        progressBar10 = new QProgressBar(dlgTestDialog);
        progressBar10->setObjectName(QStringLiteral("progressBar10"));
        progressBar10->setValue(24);

        gridLayout_2->addWidget(progressBar10, 10, 0, 1, 1);


        retranslateUi(dlgTestDialog);

        QMetaObject::connectSlotsByName(dlgTestDialog);
    } // setupUi

    void retranslateUi(QDialog *dlgTestDialog)
    {
        dlgTestDialog->setWindowTitle(QApplication::translate("dlgTestDialog", "dlgTestDialog", 0));
        pushButtonGray->setText(QApplication::translate("dlgTestDialog", "\345\274\200\345\247\213\347\224\237\346\210\220\347\201\260\345\272\246\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgTestDialog: public Ui_dlgTestDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTESTDIALOG_H
