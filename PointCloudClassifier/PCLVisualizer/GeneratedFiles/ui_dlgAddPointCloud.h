/********************************************************************************
** Form generated from reading UI file 'dlgAddPointCloud.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGADDPOINTCLOUD_H
#define UI_DLGADDPOINTCLOUD_H

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

class Ui_dlgAddPointCloud
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *dlgAddPointCloud)
    {
        if (dlgAddPointCloud->objectName().isEmpty())
            dlgAddPointCloud->setObjectName(QStringLiteral("dlgAddPointCloud"));
        dlgAddPointCloud->resize(641, 179);
        gridLayout_3 = new QGridLayout(dlgAddPointCloud);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dlgAddPointCloud);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(dlgAddPointCloud);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton = new QToolButton(dlgAddPointCloud);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout->addWidget(toolButton, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        progressBar = new QProgressBar(dlgAddPointCloud);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgAddPointCloud);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(dlgAddPointCloud);

        QMetaObject::connectSlotsByName(dlgAddPointCloud);
    } // setupUi

    void retranslateUi(QWidget *dlgAddPointCloud)
    {
        dlgAddPointCloud->setWindowTitle(QApplication::translate("dlgAddPointCloud", "\346\267\273\345\212\240\347\202\271\344\272\221\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("dlgAddPointCloud", "\350\257\267\351\200\211\346\213\251\347\202\271\344\272\221\350\267\257\345\276\204", 0));
        toolButton->setText(QApplication::translate("dlgAddPointCloud", "...", 0));
        pushButton->setText(QApplication::translate("dlgAddPointCloud", "\346\267\273\345\212\240", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgAddPointCloud: public Ui_dlgAddPointCloud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGADDPOINTCLOUD_H
