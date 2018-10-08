/********************************************************************************
** Form generated from reading UI file 'dlgBinarySignal.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGBINARYSIGNAL_H
#define UI_DLGBINARYSIGNAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dlgBinarySignal
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QToolButton *toolButton1;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit1;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLineEdit *lineEdit2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLineEdit *lineEdit3;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QLineEdit *lineEdit4;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_6;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *dlgBinarySignal)
    {
        if (dlgBinarySignal->objectName().isEmpty())
            dlgBinarySignal->setObjectName(QStringLiteral("dlgBinarySignal"));
        dlgBinarySignal->resize(794, 289);
        gridLayout_4 = new QGridLayout(dlgBinarySignal);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(dlgBinarySignal);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton1 = new QToolButton(groupBox);
        toolButton1->setObjectName(QStringLiteral("toolButton1"));

        gridLayout_2->addWidget(toolButton1, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        toolButton2 = new QToolButton(groupBox);
        toolButton2->setObjectName(QStringLiteral("toolButton2"));

        gridLayout_2->addWidget(toolButton2, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(dlgBinarySignal);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit1 = new QLineEdit(groupBox_2);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));

        gridLayout_3->addWidget(lineEdit1, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        lineEdit2 = new QLineEdit(groupBox_2);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));

        gridLayout_3->addWidget(lineEdit2, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        lineEdit3 = new QLineEdit(groupBox_2);
        lineEdit3->setObjectName(QStringLiteral("lineEdit3"));

        gridLayout_3->addWidget(lineEdit3, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 2, 3, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 3, 0, 1, 1);

        lineEdit4 = new QLineEdit(groupBox_2);
        lineEdit4->setObjectName(QStringLiteral("lineEdit4"));

        gridLayout_3->addWidget(lineEdit4, 3, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 3, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(182, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 3, 3, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(dlgBinarySignal);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgBinarySignal);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 3, 0, 1, 1);


        retranslateUi(dlgBinarySignal);

        QMetaObject::connectSlotsByName(dlgBinarySignal);
    } // setupUi

    void retranslateUi(QDialog *dlgBinarySignal)
    {
        dlgBinarySignal->setWindowTitle(QApplication::translate("dlgBinarySignal", "\344\272\214\350\277\233\345\210\266\344\277\241\345\217\267\347\224\237\346\210\220", 0));
        groupBox->setTitle(QApplication::translate("dlgBinarySignal", "\351\200\211\346\213\251\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("dlgBinarySignal", "\351\200\211\346\200\216\345\244\204\347\220\206\347\232\204PCD\347\202\271\344\272\221\346\226\207\344\273\266", 0));
        toolButton1->setText(QApplication::translate("dlgBinarySignal", "...", 0));
        label_2->setText(QApplication::translate("dlgBinarySignal", "\351\200\211\346\213\251\350\246\201\350\276\223\345\207\272\347\232\204TXT\346\226\207\344\273\266", 0));
        toolButton2->setText(QApplication::translate("dlgBinarySignal", "...", 0));
        groupBox_2->setTitle(QApplication::translate("dlgBinarySignal", "\351\230\210\345\200\274\350\256\276\347\275\256", 0));
        label_3->setText(QApplication::translate("dlgBinarySignal", "\351\230\210\345\200\2741", 0));
        label_7->setText(QApplication::translate("dlgBinarySignal", "\357\274\210\350\257\264\346\230\216\357\274\232*******************\357\274\211", 0));
        label_4->setText(QApplication::translate("dlgBinarySignal", "\351\230\210\345\200\2742", 0));
        label_8->setText(QApplication::translate("dlgBinarySignal", "\357\274\210\350\257\264\346\230\216\357\274\232*******************\357\274\211", 0));
        label_5->setText(QApplication::translate("dlgBinarySignal", "\351\230\210\345\200\2743", 0));
        label_9->setText(QApplication::translate("dlgBinarySignal", "\357\274\210\350\257\264\346\230\216\357\274\232*******************\357\274\211", 0));
        label_6->setText(QApplication::translate("dlgBinarySignal", "\351\230\210\345\200\2744", 0));
        label_10->setText(QApplication::translate("dlgBinarySignal", "\357\274\210\350\257\264\346\230\216\357\274\232*******************\357\274\211", 0));
        pushButton->setText(QApplication::translate("dlgBinarySignal", "\345\274\200\345\247\213\345\244\204\347\220\206", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgBinarySignal: public Ui_dlgBinarySignal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGBINARYSIGNAL_H
