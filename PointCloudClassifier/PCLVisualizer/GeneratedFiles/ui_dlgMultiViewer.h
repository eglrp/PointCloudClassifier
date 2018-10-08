/********************************************************************************
** Form generated from reading UI file 'dlgMultiViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGMULTIVIEWER_H
#define UI_DLGMULTIVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_dlgMultiViewer
{
public:
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *dlgMultiViewer)
    {
        if (dlgMultiViewer->objectName().isEmpty())
            dlgMultiViewer->setObjectName(QStringLiteral("dlgMultiViewer"));
        dlgMultiViewer->resize(722, 811);
        gridLayout_6 = new QGridLayout(dlgMultiViewer);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox = new QGroupBox(dlgMultiViewer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 0, 1, 1);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout_5->addWidget(radioButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout_5->addWidget(radioButton_2, 0, 3, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        gridLayout_5->addWidget(radioButton_3, 0, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 7, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setScaledContents(true);
        label->setWordWrap(false);
        label->setMargin(10);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout, 1, 0, 1, 4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setScaledContents(true);
        label_2->setWordWrap(false);
        label_2->setMargin(10);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout_2->addWidget(comboBox_2, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 4, 1, 4);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);
        label_3->setMargin(10);

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));

        gridLayout_3->addWidget(comboBox_3, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);
        label_4->setMargin(10);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));

        gridLayout_4->addWidget(comboBox_4, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 2, 4, 1, 4);


        gridLayout_6->addWidget(groupBox, 0, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        pushButton = new QPushButton(dlgMultiViewer);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_6->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(150, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 1, 2, 1, 1);


        retranslateUi(dlgMultiViewer);

        QMetaObject::connectSlotsByName(dlgMultiViewer);
    } // setupUi

    void retranslateUi(QDialog *dlgMultiViewer)
    {
        dlgMultiViewer->setWindowTitle(QApplication::translate("dlgMultiViewer", "\345\244\232\350\247\206\347\252\227\345\217\243\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("dlgMultiViewer", "\350\257\267\351\200\211\346\213\251\347\252\227\345\217\243", 0));
        radioButton->setText(QApplication::translate("dlgMultiViewer", "\345\215\225\347\252\227\345\217\243", 0));
        radioButton_2->setText(QApplication::translate("dlgMultiViewer", "\345\217\214\347\252\227\345\217\243", 0));
        radioButton_3->setText(QApplication::translate("dlgMultiViewer", "\345\244\232\347\252\227\345\217\243", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton->setText(QApplication::translate("dlgMultiViewer", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgMultiViewer: public Ui_dlgMultiViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGMULTIVIEWER_H
