/********************************************************************************
** Form generated from reading UI file 'dlgIntensityFix.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINTENSITYFIX_H
#define UI_DLGINTENSITYFIX_H

#include <QtCore/QObject>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlgIntensityFix
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEditFile;
    QToolButton *toolButton;
    QLabel *label_2;
    QLineEdit *lineEditResolution;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditK;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLineEdit *lineEditDeltaIntensity;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditDeltaH;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_27;
    QPushButton *btnYes;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *horizontalSpacer_30;
    QPushButton *btnNo;

    void setupUi(QWidget *dlgIntensityFix)
    {
        if (dlgIntensityFix->objectName().isEmpty())
            dlgIntensityFix->setObjectName(QStringLiteral("dlgIntensityFix"));
        dlgIntensityFix->resize(562, 186);
        gridLayout_3 = new QGridLayout(dlgIntensityFix);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(dlgIntensityFix);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        lineEditFile = new QLineEdit(groupBox);
        lineEditFile->setObjectName(QStringLiteral("lineEditFile"));

        gridLayout_2->addWidget(lineEditFile, 0, 2, 1, 4);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        gridLayout_2->addWidget(toolButton, 0, 6, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEditResolution = new QLineEdit(groupBox);
        lineEditResolution->setObjectName(QStringLiteral("lineEditResolution"));

        gridLayout_2->addWidget(lineEditResolution, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 4, 1, 1);

        lineEditK = new QLineEdit(groupBox);
        lineEditK->setObjectName(QStringLiteral("lineEditK"));

        gridLayout_2->addWidget(lineEditK, 1, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 6, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 4, 1, 1);

        lineEditDeltaIntensity = new QLineEdit(groupBox);
        lineEditDeltaIntensity->setObjectName(QStringLiteral("lineEditDeltaIntensity"));

        gridLayout_2->addWidget(lineEditDeltaIntensity, 2, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 6, 1, 1);

        lineEditDeltaH = new QLineEdit(groupBox);
        lineEditDeltaH->setObjectName(QStringLiteral("lineEditDeltaH"));

        gridLayout_2->addWidget(lineEditDeltaH, 2, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_27 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_27, 0, 0, 1, 1);

        btnYes = new QPushButton(dlgIntensityFix);
        btnYes->setObjectName(QStringLiteral("btnYes"));

        gridLayout->addWidget(btnYes, 0, 1, 1, 1);

        horizontalSpacer_26 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_26, 0, 2, 1, 1);

        horizontalSpacer_30 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_30, 0, 4, 1, 1);

        btnNo = new QPushButton(dlgIntensityFix);
        btnNo->setObjectName(QStringLiteral("btnNo"));

        gridLayout->addWidget(btnNo, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(dlgIntensityFix);

        QMetaObject::connectSlotsByName(dlgIntensityFix);
    } // setupUi

    void retranslateUi(QWidget *dlgIntensityFix)
    {
        dlgIntensityFix->setWindowTitle(QApplication::translate("dlgIntensityFix", "\345\217\215\345\260\204\345\274\272\345\272\246\344\277\256\345\244\215", 0));
        groupBox->setTitle(QApplication::translate("dlgIntensityFix", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("dlgIntensityFix", "\351\200\211\346\213\251\347\202\271\344\272\221\346\226\207\344\273\266", 0));
        toolButton->setText(QApplication::translate("dlgIntensityFix", "...", 0));
        label_2->setText(QApplication::translate("dlgIntensityFix", "Resolution", 0));
        label_3->setText(QApplication::translate("dlgIntensityFix", "\346\220\234\347\264\242\350\214\203\345\233\264\345\200\274", 0));
        label_4->setText(QApplication::translate("dlgIntensityFix", "\351\253\230\347\250\213\345\267\256\351\230\210\345\200\274", 0));
        label_5->setText(QApplication::translate("dlgIntensityFix", "\345\217\215\345\260\204\345\274\272\345\272\246\345\267\256", 0));
        btnYes->setText(QApplication::translate("dlgIntensityFix", "\347\241\256\345\256\232", 0));
        btnNo->setText(QApplication::translate("dlgIntensityFix", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgIntensityFix: public Ui_dlgIntensityFix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINTENSITYFIX_H
