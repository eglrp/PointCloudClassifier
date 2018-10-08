/********************************************************************************
** Form generated from reading UI file 'dlgLAS2TXT.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGLAS2TXT_H
#define UI_DLGLAS2TXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dlgLAS2TXT
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *dlgLAS2TXT)
    {
        if (dlgLAS2TXT->objectName().isEmpty())
            dlgLAS2TXT->setObjectName(QStringLiteral("dlgLAS2TXT"));
        dlgLAS2TXT->resize(627, 156);
        gridLayout_3 = new QGridLayout(dlgLAS2TXT);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(dlgLAS2TXT);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(dlgLAS2TXT);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton = new QToolButton(dlgLAS2TXT);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout->addWidget(toolButton, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgLAS2TXT);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(dlgLAS2TXT);

        QMetaObject::connectSlotsByName(dlgLAS2TXT);
    } // setupUi

    void retranslateUi(QDialog *dlgLAS2TXT)
    {
        dlgLAS2TXT->setWindowTitle(QApplication::translate("dlgLAS2TXT", "LAS\350\275\254TXT", 0));
        label->setText(QApplication::translate("dlgLAS2TXT", "\350\257\267\351\200\211\346\213\251LAS\346\226\207\344\273\266", 0));
        toolButton->setText(QApplication::translate("dlgLAS2TXT", "...", 0));
        pushButton->setText(QApplication::translate("dlgLAS2TXT", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgLAS2TXT: public Ui_dlgLAS2TXT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGLAS2TXT_H
