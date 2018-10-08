/********************************************************************************
** Form generated from reading UI file 'dlgKdTreeCluster.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGKDTREECLUSTER_H
#define UI_DLGKDTREECLUSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_dlgKdTreeCluster
{
public:
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEditInput;
    QToolButton *toolButtonInput;
    QSpacerItem *horizontalSpacer_10;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEditOutput;
    QToolButton *toolButtonOutput;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QRadioButton *rbK;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_7;
    QLineEdit *lineEditK;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_12;
    QRadioButton *rbRadius;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QLineEdit *lineEditRadius;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_14;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBoxPrimary;
    QLabel *label;
    QLineEdit *lineEditPrimaryDeltaH;
    QLabel *label_2;
    QLineEdit *lineEditPrimaryDeltaI;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBoxSecondary;
    QLabel *label_3;
    QLineEdit *lineEditSecondaryDeltaH;
    QLabel *label_4;
    QLineEdit *lineEditSecondaryDeltaI;
    QSpacerItem *horizontalSpacer_15;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_9;
    QLineEdit *lineEditResult3;
    QLabel *label_15;
    QLineEdit *lineEditResult4;
    QSpacerItem *horizontalSpacer_21;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_12;
    QLineEdit *lineEditResult1;
    QLineEdit *lineEditResult2;
    QLabel *label_13;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *dlgKdTreeCluster)
    {
        if (dlgKdTreeCluster->objectName().isEmpty())
            dlgKdTreeCluster->setObjectName(QStringLiteral("dlgKdTreeCluster"));
        dlgKdTreeCluster->resize(797, 407);
        gridLayout_10 = new QGridLayout(dlgKdTreeCluster);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        groupBox_2 = new QGroupBox(dlgKdTreeCluster);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_9 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_9, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEditInput = new QLineEdit(groupBox_2);
        lineEditInput->setObjectName(QStringLiteral("lineEditInput"));
        lineEditInput->setReadOnly(true);

        gridLayout->addWidget(lineEditInput, 0, 1, 1, 1);

        toolButtonInput = new QToolButton(groupBox_2);
        toolButtonInput->setObjectName(QStringLiteral("toolButtonInput"));

        gridLayout->addWidget(toolButtonInput, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_10, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEditOutput = new QLineEdit(groupBox_2);
        lineEditOutput->setObjectName(QStringLiteral("lineEditOutput"));
        lineEditOutput->setReadOnly(true);

        gridLayout_2->addWidget(lineEditOutput, 0, 1, 1, 1);

        toolButtonOutput = new QToolButton(groupBox_2);
        toolButtonOutput->setObjectName(QStringLiteral("toolButtonOutput"));

        gridLayout_2->addWidget(toolButtonOutput, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);


        gridLayout_10->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(dlgKdTreeCluster);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalSpacer_11 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        rbK = new QRadioButton(groupBox);
        rbK->setObjectName(QStringLiteral("rbK"));

        gridLayout_8->addWidget(rbK, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_8->addWidget(label_7, 0, 3, 1, 1);

        lineEditK = new QLineEdit(groupBox);
        lineEditK->setObjectName(QStringLiteral("lineEditK"));

        gridLayout_8->addWidget(lineEditK, 0, 4, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_8->addWidget(label_9, 0, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_7, 0, 6, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_12, 1, 0, 1, 1);

        rbRadius = new QRadioButton(groupBox);
        rbRadius->setObjectName(QStringLiteral("rbRadius"));

        gridLayout_8->addWidget(rbRadius, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(38, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_8->addWidget(label_8, 1, 3, 1, 1);

        lineEditRadius = new QLineEdit(groupBox);
        lineEditRadius->setObjectName(QStringLiteral("lineEditRadius"));

        gridLayout_8->addWidget(lineEditRadius, 1, 4, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_8->addWidget(label_10, 1, 5, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_8, 1, 6, 1, 1);


        gridLayout_10->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(dlgKdTreeCluster);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalSpacer_14 = new QSpacerItem(28, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        checkBoxPrimary = new QCheckBox(groupBox_3);
        checkBoxPrimary->setObjectName(QStringLiteral("checkBoxPrimary"));

        gridLayout_6->addWidget(checkBoxPrimary, 0, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 1, 0, 1, 1);

        lineEditPrimaryDeltaH = new QLineEdit(groupBox_3);
        lineEditPrimaryDeltaH->setObjectName(QStringLiteral("lineEditPrimaryDeltaH"));

        gridLayout_6->addWidget(lineEditPrimaryDeltaH, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_6->addWidget(label_2, 2, 0, 1, 1);

        lineEditPrimaryDeltaI = new QLineEdit(groupBox_3);
        lineEditPrimaryDeltaI->setObjectName(QStringLiteral("lineEditPrimaryDeltaI"));
        lineEditPrimaryDeltaI->setEnabled(true);

        gridLayout_6->addWidget(lineEditPrimaryDeltaI, 2, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        checkBoxSecondary = new QCheckBox(groupBox_3);
        checkBoxSecondary->setObjectName(QStringLiteral("checkBoxSecondary"));

        gridLayout_5->addWidget(checkBoxSecondary, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        lineEditSecondaryDeltaH = new QLineEdit(groupBox_3);
        lineEditSecondaryDeltaH->setObjectName(QStringLiteral("lineEditSecondaryDeltaH"));

        gridLayout_5->addWidget(lineEditSecondaryDeltaH, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_5->addWidget(label_4, 2, 0, 1, 1);

        lineEditSecondaryDeltaI = new QLineEdit(groupBox_3);
        lineEditSecondaryDeltaI->setObjectName(QStringLiteral("lineEditSecondaryDeltaI"));

        gridLayout_5->addWidget(lineEditSecondaryDeltaI, 2, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 0, 3, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_15, 0, 4, 1, 1);


        gridLayout_10->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(dlgKdTreeCluster);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_9 = new QGridLayout(groupBox_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        lineEditResult3 = new QLineEdit(groupBox_4);
        lineEditResult3->setObjectName(QStringLiteral("lineEditResult3"));
        lineEditResult3->setEnabled(false);
        lineEditResult3->setAlignment(Qt::AlignCenter);
        lineEditResult3->setReadOnly(true);

        gridLayout_9->addWidget(lineEditResult3, 0, 6, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_9->addWidget(label_15, 0, 7, 1, 1);

        lineEditResult4 = new QLineEdit(groupBox_4);
        lineEditResult4->setObjectName(QStringLiteral("lineEditResult4"));
        lineEditResult4->setEnabled(false);
        lineEditResult4->setAlignment(Qt::AlignCenter);
        lineEditResult4->setReadOnly(true);

        gridLayout_9->addWidget(lineEditResult4, 0, 8, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_21, 0, 9, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_9->addWidget(label_14, 0, 5, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_16, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_9->addWidget(label_12, 0, 1, 1, 1);

        lineEditResult1 = new QLineEdit(groupBox_4);
        lineEditResult1->setObjectName(QStringLiteral("lineEditResult1"));
        lineEditResult1->setEnabled(false);
        lineEditResult1->setAlignment(Qt::AlignCenter);
        lineEditResult1->setReadOnly(true);

        gridLayout_9->addWidget(lineEditResult1, 0, 2, 1, 1);

        lineEditResult2 = new QLineEdit(groupBox_4);
        lineEditResult2->setObjectName(QStringLiteral("lineEditResult2"));
        lineEditResult2->setEnabled(false);
        lineEditResult2->setAlignment(Qt::AlignCenter);
        lineEditResult2->setReadOnly(true);

        gridLayout_9->addWidget(lineEditResult2, 0, 4, 1, 1);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_9->addWidget(label_13, 0, 3, 1, 1);


        gridLayout_10->addWidget(groupBox_4, 3, 0, 1, 1);

        progressBar = new QProgressBar(dlgKdTreeCluster);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_10->addWidget(progressBar, 4, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(dlgKdTreeCluster);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 5, 0, 1, 1);


        retranslateUi(dlgKdTreeCluster);

        QMetaObject::connectSlotsByName(dlgKdTreeCluster);
    } // setupUi

    void retranslateUi(QDialog *dlgKdTreeCluster)
    {
        dlgKdTreeCluster->setWindowTitle(QApplication::translate("dlgKdTreeCluster", "Kd-Tree \350\266\205\350\201\232\347\261\273", 0));
        groupBox_2->setTitle(QApplication::translate("dlgKdTreeCluster", "\346\226\207\344\273\266\351\200\211\346\213\251", 0));
        label_5->setText(QApplication::translate("dlgKdTreeCluster", "\350\201\232\347\261\273\347\232\204PCD\346\226\207\344\273\266", 0));
        toolButtonInput->setText(QApplication::translate("dlgKdTreeCluster", "...", 0));
        label_6->setText(QApplication::translate("dlgKdTreeCluster", "\350\276\223\345\207\272\347\232\204PCD\346\226\207\344\273\266", 0));
        toolButtonOutput->setText(QApplication::translate("dlgKdTreeCluster", "...", 0));
        groupBox->setTitle(QApplication::translate("dlgKdTreeCluster", "\350\201\232\347\261\273\346\226\271\345\274\217", 0));
        rbK->setText(QApplication::translate("dlgKdTreeCluster", "\347\202\271\346\225\260\346\263\225", 0));
        label_7->setText(QApplication::translate("dlgKdTreeCluster", "\347\202\271\346\225\260\346\234\200\345\244\247\345\200\274", 0));
        label_9->setText(QApplication::translate("dlgKdTreeCluster", "\357\274\210\346\237\245\346\211\276\350\267\235\347\246\273\346\220\234\347\264\242\347\202\271\346\234\200\350\277\221\347\232\204\347\202\271\357\274\211", 0));
        rbRadius->setText(QApplication::translate("dlgKdTreeCluster", "\345\215\212\345\276\204\346\263\225", 0));
        label_8->setText(QApplication::translate("dlgKdTreeCluster", "\345\215\212\345\276\204\346\234\200\345\244\247\345\200\274", 0));
        label_10->setText(QApplication::translate("dlgKdTreeCluster", "\357\274\210\346\237\245\346\211\276\346\220\234\347\264\242\347\202\271\344\270\200\345\256\232\345\215\212\345\276\204\350\214\203\345\233\264\345\206\205\347\232\204\347\202\271\357\274\211", 0));
        groupBox_3->setTitle(QApplication::translate("dlgKdTreeCluster", "\346\210\220\345\210\206\345\210\206\346\236\220", 0));
        checkBoxPrimary->setText(QApplication::translate("dlgKdTreeCluster", "\344\270\273\346\210\220\345\210\206", 0));
        label->setText(QApplication::translate("dlgKdTreeCluster", "\351\253\230\347\250\213\345\267\256\347\273\235\345\257\271\345\200\274", 0));
        label_2->setText(QApplication::translate("dlgKdTreeCluster", "\345\217\215\345\260\204\345\274\272\345\272\246\345\267\256\347\273\235\345\257\271\345\200\274", 0));
        checkBoxSecondary->setText(QApplication::translate("dlgKdTreeCluster", "\345\211\257\346\210\220\345\210\206", 0));
        label_3->setText(QApplication::translate("dlgKdTreeCluster", "\351\253\230\347\250\213\345\267\256\347\273\235\345\257\271\345\200\274", 0));
        label_4->setText(QApplication::translate("dlgKdTreeCluster", "\345\217\215\345\260\204\345\274\272\345\272\246\345\267\256\347\273\235\345\257\271\345\200\274", 0));
        groupBox_4->setTitle(QApplication::translate("dlgKdTreeCluster", "\345\210\206\347\261\273\347\273\223\346\236\234", 0));
        label_15->setText(QApplication::translate("dlgKdTreeCluster", "\350\266\205\350\201\232\347\261\273\345\207\206\347\241\256\347\216\207", 0));
        label_14->setText(QApplication::translate("dlgKdTreeCluster", "\346\257\217\347\260\207\345\271\263\345\235\207\347\202\271\344\272\221\346\225\260\351\207\217", 0));
        label_12->setText(QApplication::translate("dlgKdTreeCluster", "\345\216\237\345\247\213\347\202\271\344\272\221\346\225\260\351\207\217", 0));
        label_13->setText(QApplication::translate("dlgKdTreeCluster", "\350\266\205\350\201\232\347\261\273\347\260\207\346\225\260\351\207\217", 0));
        pushButton->setText(QApplication::translate("dlgKdTreeCluster", "\345\274\200\345\247\213\350\266\205\350\201\232\347\261\273", 0));
    } // retranslateUi

};

namespace Ui {
    class dlgKdTreeCluster: public Ui_dlgKdTreeCluster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGKDTREECLUSTER_H
