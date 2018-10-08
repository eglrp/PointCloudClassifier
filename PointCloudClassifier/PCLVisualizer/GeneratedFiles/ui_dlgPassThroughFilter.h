/********************************************************************************
** Form generated from reading UI file 'dlgPassThroughFilter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPASSTHROUGHFILTER_H
#define UI_DLGPASSTHROUGHFILTER_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_dlgPassThroughFilter
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *rbFiledX;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *rbFiledY;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *rbFiledZ;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label;
    QLineEdit *lineEditMin;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *lineEditMax;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QRadioButton *rbSaveFiled;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QRadioButton *rbDeleteFild;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *dlgPassThroughFilter)
    {
        if (dlgPassThroughFilter->objectName().isEmpty())
            dlgPassThroughFilter->setObjectName(QStringLiteral("dlgPassThroughFilter"));
        dlgPassThroughFilter->setWindowModality(Qt::NonModal);
        dlgPassThroughFilter->resize(1464, 629);
        dlgPassThroughFilter->setAcceptDrops(true);
        dlgPassThroughFilter->setSizeGripEnabled(false);
        gridLayout_3 = new QGridLayout(dlgPassThroughFilter);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(dlgPassThroughFilter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        rbFiledX = new QRadioButton(groupBox);
        rbFiledX->setObjectName(QStringLiteral("rbFiledX"));

        gridLayout_2->addWidget(rbFiledX, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        rbFiledY = new QRadioButton(groupBox);
        rbFiledY->setObjectName(QStringLiteral("rbFiledY"));

        gridLayout_2->addWidget(rbFiledY, 0, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        rbFiledZ = new QRadioButton(groupBox);
        rbFiledZ->setObjectName(QStringLiteral("rbFiledZ"));

        gridLayout_2->addWidget(rbFiledZ, 0, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(135, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 6, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(dlgPassThroughFilter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer_12 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 0, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        lineEditMin = new QLineEdit(groupBox_2);
        lineEditMin->setObjectName(QStringLiteral("lineEditMin"));

        gridLayout_4->addWidget(lineEditMin, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(158, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 4, 1, 1);

        lineEditMax = new QLineEdit(groupBox_2);
        lineEditMax->setObjectName(QStringLiteral("lineEditMax"));

        gridLayout_4->addWidget(lineEditMax, 0, 5, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(38, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 0, 6, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 3);

        groupBox_3 = new QGroupBox(dlgPassThroughFilter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_9 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        rbSaveFiled = new QRadioButton(groupBox_3);
        rbSaveFiled->setObjectName(QStringLiteral("rbSaveFiled"));

        gridLayout->addWidget(rbSaveFiled, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(163, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 4, 1, 1);

        rbDeleteFild = new QRadioButton(groupBox_3);
        rbDeleteFild->setObjectName(QStringLiteral("rbDeleteFild"));

        gridLayout->addWidget(rbDeleteFild, 0, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 2, 0, 1, 3);

        progressBar = new QProgressBar(dlgPassThroughFilter);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 3, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(394, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 4, 0, 1, 1);

        pushButton = new QPushButton(dlgPassThroughFilter);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(394, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 4, 2, 1, 1);


        retranslateUi(dlgPassThroughFilter);

        QMetaObject::connectSlotsByName(dlgPassThroughFilter);
    } // setupUi

    void retranslateUi(QDialog *dlgPassThroughFilter)
    {
        dlgPassThroughFilter->setWindowTitle(QApplication::translate("dlgPassThroughFilter", "\347\233\264\351\200\232\346\273\244\346\263\242\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("dlgPassThroughFilter", "\346\273\244\346\263\242\345\255\227\346\256\265", 0));
        rbFiledX->setText(QApplication::translate("dlgPassThroughFilter", "\345\255\227\346\256\265 X", 0));
        rbFiledY->setText(QApplication::translate("dlgPassThroughFilter", "\345\255\227\346\256\265 Y", 0));
        rbFiledZ->setText(QApplication::translate("dlgPassThroughFilter", "\345\255\227\346\256\265 Z", 0));
        groupBox_2->setTitle(QApplication::translate("dlgPassThroughFilter", "\346\273\244\346\263\242\350\214\203\345\233\264", 0));
        label->setText(QApplication::translate("dlgPassThroughFilter", "\346\234\200\345\260\217\345\200\274", 0));
        label_2->setText(QApplication::translate("dlgPassThroughFilter", "\346\234\200\345\244\247\345\200\274", 0));
        groupBox_3->setTitle(QApplication::translate("dlgPassThroughFilter", "\346\273\244\346\263\242\346\226\271\345\274\217", 0));
        rbSaveFiled->setText(QApplication::translate("dlgPassThroughFilter", "\344\277\235\347\225\231\345\255\227\346\256\265", 0));
        rbDeleteFild->setText(QApplication::translate("dlgPassThroughFilter", "\345\210\240\351\231\244\345\255\227\346\256\265", 0));
        pushButton->setText(QApplication::translate("dlgPassThroughFilter", "\345\274\200\345\247\213\347\233\264\351\200\232\346\273\244\346\263\242", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgPassThroughFilter: public Ui_dlgPassThroughFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPASSTHROUGHFILTER_H
