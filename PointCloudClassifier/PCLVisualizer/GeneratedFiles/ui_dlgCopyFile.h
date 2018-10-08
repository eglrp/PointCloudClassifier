/********************************************************************************
** Form generated from reading UI file 'dlgCopyFile.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCOPYFILE_H
#define UI_DLGCOPYFILE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dlgCopyFile
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QDialog *dlgCopyFile)
    {
        if (dlgCopyFile->objectName().isEmpty())
            dlgCopyFile->setObjectName(QStringLiteral("dlgCopyFile"));
        dlgCopyFile->resize(573, 253);
        gridLayout_4 = new QGridLayout(dlgCopyFile);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_3 = new QGroupBox(dlgCopyFile);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setChecked(true);

        gridLayout_3->addWidget(radioButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout_3->addWidget(radioButton_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(dlgCopyFile);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        toolButton_2 = new QToolButton(groupBox_2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        gridLayout->addWidget(toolButton_2, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        pushButton = new QPushButton(dlgCopyFile);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 3, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 3, 2, 1, 1);

        groupBox = new QGroupBox(dlgCopyFile);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFrame(true);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout_2->addWidget(toolButton, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 3);


        retranslateUi(dlgCopyFile);

        QMetaObject::connectSlotsByName(dlgCopyFile);
    } // setupUi

    void retranslateUi(QDialog *dlgCopyFile)
    {
        dlgCopyFile->setWindowTitle(QApplication::translate("dlgCopyFile", "\346\226\207\344\273\266\345\244\215\345\210\266", 0));
        groupBox_3->setTitle(QApplication::translate("dlgCopyFile", "\350\276\223\345\205\245\346\226\207\344\273\266\350\267\257\345\276\204\347\261\273\345\236\213", 0));
        radioButton->setText(QApplication::translate("dlgCopyFile", "\343\200\220\\\343\200\221\350\267\257\345\276\204", 0));
        radioButton_2->setText(QApplication::translate("dlgCopyFile", "\343\200\220/\343\200\221\350\267\257\345\276\204", 0));
        groupBox_2->setTitle(QApplication::translate("dlgCopyFile", "\350\276\223\345\207\272\346\226\207\344\273\266", 0));
        label_3->setText(QApplication::translate("dlgCopyFile", "\350\246\201\350\276\223\345\207\272\347\232\204\350\267\257\345\276\204", 0));
        lineEdit_2->setPlaceholderText(QApplication::translate("dlgCopyFile", "\350\257\267\351\200\211\346\213\251\350\276\223\345\207\272\346\226\207\344\273\266\345\220\215", 0));
        toolButton_2->setText(QApplication::translate("dlgCopyFile", "...", 0));
        pushButton->setText(QApplication::translate("dlgCopyFile", "\345\274\200\345\247\213\345\244\215\345\210\266", 0));
        groupBox->setTitle(QApplication::translate("dlgCopyFile", "\350\276\223\345\205\245\346\226\207\344\273\266", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setPlaceholderText(QApplication::translate("dlgCopyFile", "\350\257\267 \351\200\211\346\213\251 / \350\276\223\345\205\245 \346\226\207\344\273\266\345\220\215", 0));
        label->setText(QApplication::translate("dlgCopyFile", "\350\246\201\345\244\215\345\210\266\347\232\204\346\226\207\344\273\266", 0));
        toolButton->setText(QApplication::translate("dlgCopyFile", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgCopyFile: public Ui_dlgCopyFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCOPYFILE_H
