/********************************************************************************
** Form generated from reading UI file 'dlgTxt2PCD.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTXT2PCD_H
#define UI_DLGTXT2PCD_H

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

class Ui_dlgTxt2PCD
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolBtn1;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QToolButton *toolBtn2;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *dlgTxt2PCD)
    {
        if (dlgTxt2PCD->objectName().isEmpty())
            dlgTxt2PCD->setObjectName(QStringLiteral("dlgTxt2PCD"));
        dlgTxt2PCD->resize(619, 219);
        gridLayout_4 = new QGridLayout(dlgTxt2PCD);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dlgTxt2PCD);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(dlgTxt2PCD);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        toolBtn1 = new QToolButton(dlgTxt2PCD);
        toolBtn1->setObjectName(QStringLiteral("toolBtn1"));

        gridLayout->addWidget(toolBtn1, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(dlgTxt2PCD);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(dlgTxt2PCD);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);

        toolBtn2 = new QToolButton(dlgTxt2PCD);
        toolBtn2->setObjectName(QStringLiteral("toolBtn2"));

        gridLayout_2->addWidget(toolBtn2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(dlgTxt2PCD);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 2, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgTxt2PCD);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 1);


        retranslateUi(dlgTxt2PCD);

        QMetaObject::connectSlotsByName(dlgTxt2PCD);
    } // setupUi

    void retranslateUi(QWidget *dlgTxt2PCD)
    {
        dlgTxt2PCD->setWindowTitle(QApplication::translate("dlgTxt2PCD", "TXT\350\275\254PCD", 0));
        label->setText(QApplication::translate("dlgTxt2PCD", "\351\200\211\346\213\251\345\244\204\347\220\206\347\232\204TXT\346\226\207\344\273\266", 0));
        toolBtn1->setText(QApplication::translate("dlgTxt2PCD", "...", 0));
        label_2->setText(QApplication::translate("dlgTxt2PCD", "\351\200\211\346\213\251PCD\347\232\204\345\255\230\345\202\250\350\267\257\345\276\204", 0));
        toolBtn2->setText(QApplication::translate("dlgTxt2PCD", "...", 0));
        pushButton->setText(QApplication::translate("dlgTxt2PCD", "\345\274\200\345\247\213\350\275\254\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgTxt2PCD: public Ui_dlgTxt2PCD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTXT2PCD_H
