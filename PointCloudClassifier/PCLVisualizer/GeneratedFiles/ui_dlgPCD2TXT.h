/********************************************************************************
** Form generated from reading UI file 'dlgPCD2TXT.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPCD2TXT_H
#define UI_DLGPCD2TXT_H

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

class Ui_dlgPCD2TXT
{
public:
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_2;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *dlgPCD2TXT)
    {
        if (dlgPCD2TXT->objectName().isEmpty())
            dlgPCD2TXT->setObjectName(QStringLiteral("dlgPCD2TXT"));
        dlgPCD2TXT->resize(619, 209);
        gridLayout_4 = new QGridLayout(dlgPCD2TXT);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(dlgPCD2TXT);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(dlgPCD2TXT);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setFrame(true);
        lineEdit->setReadOnly(true);

        gridLayout_3->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton = new QToolButton(dlgPCD2TXT);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout_3->addWidget(toolButton, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(dlgPCD2TXT);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(dlgPCD2TXT);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_2, 0, 1, 1, 1);

        toolButton_2 = new QToolButton(dlgPCD2TXT);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        gridLayout_2->addWidget(toolButton_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(dlgPCD2TXT);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgPCD2TXT);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 3, 0, 1, 1);


        retranslateUi(dlgPCD2TXT);

        QMetaObject::connectSlotsByName(dlgPCD2TXT);
    } // setupUi

    void retranslateUi(QWidget *dlgPCD2TXT)
    {
        dlgPCD2TXT->setWindowTitle(QApplication::translate("dlgPCD2TXT", "PCD\350\275\254TXT", 0));
        label->setText(QApplication::translate("dlgPCD2TXT", "\351\200\211\346\213\251\350\275\254\346\215\242\347\232\204PCD\346\226\207\344\273\266", 0));
        toolButton->setText(QApplication::translate("dlgPCD2TXT", "...", 0));
        label_2->setText(QApplication::translate("dlgPCD2TXT", "\351\200\211\346\213\251\347\224\237\346\210\220\347\232\204TXT\350\267\257\345\276\204", 0));
        toolButton_2->setText(QApplication::translate("dlgPCD2TXT", "...", 0));
        pushButton->setText(QApplication::translate("dlgPCD2TXT", "\345\274\200\345\247\213\350\275\254\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgPCD2TXT: public Ui_dlgPCD2TXT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPCD2TXT_H
