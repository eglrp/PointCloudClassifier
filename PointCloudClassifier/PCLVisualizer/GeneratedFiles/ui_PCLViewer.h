/********************************************************************************
** Form generated from reading UI file 'PCLViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *action_open;
    QAction *action_voxel;
    QAction *action_KNN;
    QAction *action_Radius;
    QAction *action_cluster;
    QAction *action_compress;
    QAction *action_about;
    QAction *action_las2txt;
    QAction *action_pass;
    QAction *action_voxelgrid;
    QAction *action_outliner;
    QAction *action_project;
    QAction *action66;
    QAction *action_pcdb2pcda;
    QAction *action_fixintensity;
    QAction *action_txt2pcd;
    QAction *action_pcd2txt;
    QAction *action_kdtree;
    QAction *action_exit;
    QAction *action_binarysignal;
    QAction *action_cloud2grayimage;
    QAction *action_zoomin;
    QAction *action_zoomout;
    QAction *action_trim;
    QAction *action_viewer1;
    QAction *action_viewer2;
    QAction *action_viewer4;
    QAction *action_fixintensity_2;
    QAction *action_kdtree_2;
    QAction *action_binarysignal_2;
    QAction *action_image2cloud;
    QAction *action_help;
    QAction *action_saveas;
    QAction *action_zoom;
    QAction *action_screenshot;
    QAction *action_setting;
    QAction *action_copy;
    QAction *action_fullscreen;
    QAction *action_coordinate;
    QAction *action_vegetation;
    QAction *action_beta;
    QAction *action_rgbresampling;
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QVTKWidget *qvtkWidget1;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QVTKWidget *qvtkWidget2;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QVTKWidget *qvtkWidget3;
    QGridLayout *gridLayout_8;
    QLabel *label;
    QProgressBar *proBar;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_T;
    QMenu *menuKdTree;
    QMenu *menuAbnzghu;
    QMenu *menu_C;
    QMenu *menu_L;
    QMenu *menu_V;
    QMenu *menu;
    QToolBar *toolBar;
    QDockWidget *dockWidget1;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QDockWidget *dockWidget2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QTableWidget *tableWidget;
    QDockWidget *dockWidget3;
    QWidget *dockWidgetContents_8;
    QGridLayout *gridLayout_7;
    QListView *listView;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QStringLiteral("PCLViewer"));
        PCLViewer->resize(1707, 990);
        PCLViewer->setMinimumSize(QSize(0, 0));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        PCLViewer->setFocusPolicy(Qt::StrongFocus);
        PCLViewer->setAcceptDrops(true);
        PCLViewer->setDockNestingEnabled(false);
        action_open = new QAction(PCLViewer);
        action_open->setObjectName(QStringLiteral("action_open"));
        QIcon icon;
        icon.addFile(QStringLiteral("images/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        action_voxel = new QAction(PCLViewer);
        action_voxel->setObjectName(QStringLiteral("action_voxel"));
        action_KNN = new QAction(PCLViewer);
        action_KNN->setObjectName(QStringLiteral("action_KNN"));
        action_Radius = new QAction(PCLViewer);
        action_Radius->setObjectName(QStringLiteral("action_Radius"));
        action_cluster = new QAction(PCLViewer);
        action_cluster->setObjectName(QStringLiteral("action_cluster"));
        action_compress = new QAction(PCLViewer);
        action_compress->setObjectName(QStringLiteral("action_compress"));
        action_about = new QAction(PCLViewer);
        action_about->setObjectName(QStringLiteral("action_about"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_about->setIcon(icon1);
        action_las2txt = new QAction(PCLViewer);
        action_las2txt->setObjectName(QStringLiteral("action_las2txt"));
        action_pass = new QAction(PCLViewer);
        action_pass->setObjectName(QStringLiteral("action_pass"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_pass->setIcon(icon2);
        action_voxelgrid = new QAction(PCLViewer);
        action_voxelgrid->setObjectName(QStringLiteral("action_voxelgrid"));
        action_outliner = new QAction(PCLViewer);
        action_outliner->setObjectName(QStringLiteral("action_outliner"));
        action_project = new QAction(PCLViewer);
        action_project->setObjectName(QStringLiteral("action_project"));
        action66 = new QAction(PCLViewer);
        action66->setObjectName(QStringLiteral("action66"));
        action_pcdb2pcda = new QAction(PCLViewer);
        action_pcdb2pcda->setObjectName(QStringLiteral("action_pcdb2pcda"));
        action_fixintensity = new QAction(PCLViewer);
        action_fixintensity->setObjectName(QStringLiteral("action_fixintensity"));
        action_txt2pcd = new QAction(PCLViewer);
        action_txt2pcd->setObjectName(QStringLiteral("action_txt2pcd"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("images/exchange.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_txt2pcd->setIcon(icon3);
        action_pcd2txt = new QAction(PCLViewer);
        action_pcd2txt->setObjectName(QStringLiteral("action_pcd2txt"));
        action_kdtree = new QAction(PCLViewer);
        action_kdtree->setObjectName(QStringLiteral("action_kdtree"));
        action_exit = new QAction(PCLViewer);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_binarysignal = new QAction(PCLViewer);
        action_binarysignal->setObjectName(QStringLiteral("action_binarysignal"));
        action_cloud2grayimage = new QAction(PCLViewer);
        action_cloud2grayimage->setObjectName(QStringLiteral("action_cloud2grayimage"));
        action_zoomin = new QAction(PCLViewer);
        action_zoomin->setObjectName(QStringLiteral("action_zoomin"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("images/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_zoomin->setIcon(icon4);
        action_zoomout = new QAction(PCLViewer);
        action_zoomout->setObjectName(QStringLiteral("action_zoomout"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("images/zoom-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_zoomout->setIcon(icon5);
        action_trim = new QAction(PCLViewer);
        action_trim->setObjectName(QStringLiteral("action_trim"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("images/clip.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_trim->setIcon(icon6);
        action_viewer1 = new QAction(PCLViewer);
        action_viewer1->setObjectName(QStringLiteral("action_viewer1"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("images/multiviewer1.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_viewer1->setIcon(icon7);
        action_viewer2 = new QAction(PCLViewer);
        action_viewer2->setObjectName(QStringLiteral("action_viewer2"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("images/multiviewer2.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_viewer2->setIcon(icon8);
        action_viewer4 = new QAction(PCLViewer);
        action_viewer4->setObjectName(QStringLiteral("action_viewer4"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("images/multiviewer4.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_viewer4->setIcon(icon9);
        action_fixintensity_2 = new QAction(PCLViewer);
        action_fixintensity_2->setObjectName(QStringLiteral("action_fixintensity_2"));
        action_kdtree_2 = new QAction(PCLViewer);
        action_kdtree_2->setObjectName(QStringLiteral("action_kdtree_2"));
        action_binarysignal_2 = new QAction(PCLViewer);
        action_binarysignal_2->setObjectName(QStringLiteral("action_binarysignal_2"));
        action_image2cloud = new QAction(PCLViewer);
        action_image2cloud->setObjectName(QStringLiteral("action_image2cloud"));
        action_help = new QAction(PCLViewer);
        action_help->setObjectName(QStringLiteral("action_help"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("images/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_help->setIcon(icon10);
        action_saveas = new QAction(PCLViewer);
        action_saveas->setObjectName(QStringLiteral("action_saveas"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("images/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_saveas->setIcon(icon11);
        action_zoom = new QAction(PCLViewer);
        action_zoom->setObjectName(QStringLiteral("action_zoom"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("images/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_zoom->setIcon(icon12);
        action_screenshot = new QAction(PCLViewer);
        action_screenshot->setObjectName(QStringLiteral("action_screenshot"));
        QIcon icon13;
        icon13.addFile(QStringLiteral("images/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_screenshot->setIcon(icon13);
        action_setting = new QAction(PCLViewer);
        action_setting->setObjectName(QStringLiteral("action_setting"));
        QIcon icon14;
        icon14.addFile(QStringLiteral("images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_setting->setIcon(icon14);
        action_copy = new QAction(PCLViewer);
        action_copy->setObjectName(QStringLiteral("action_copy"));
        QIcon icon15;
        icon15.addFile(QStringLiteral("images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_copy->setIcon(icon15);
        action_fullscreen = new QAction(PCLViewer);
        action_fullscreen->setObjectName(QStringLiteral("action_fullscreen"));
        QIcon icon16;
        icon16.addFile(QStringLiteral("images/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_fullscreen->setIcon(icon16);
        action_coordinate = new QAction(PCLViewer);
        action_coordinate->setObjectName(QStringLiteral("action_coordinate"));
        QIcon icon17;
        icon17.addFile(QStringLiteral("images/coordinate.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_coordinate->setIcon(icon17);
        action_vegetation = new QAction(PCLViewer);
        action_vegetation->setObjectName(QStringLiteral("action_vegetation"));
        QIcon icon18;
        icon18.addFile(QStringLiteral("images/grass.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_vegetation->setIcon(icon18);
        action_beta = new QAction(PCLViewer);
        action_beta->setObjectName(QStringLiteral("action_beta"));
        QIcon icon19;
        icon19.addFile(QStringLiteral("images/beta.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_beta->setIcon(icon19);
        action_rgbresampling = new QAction(PCLViewer);
        action_rgbresampling->setObjectName(QStringLiteral("action_rgbresampling"));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qvtkWidget1 = new QVTKWidget(tab);
        qvtkWidget1->setObjectName(QStringLiteral("qvtkWidget1"));

        gridLayout->addWidget(qvtkWidget1, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        qvtkWidget2 = new QVTKWidget(tab_2);
        qvtkWidget2->setObjectName(QStringLiteral("qvtkWidget2"));

        gridLayout_4->addWidget(qvtkWidget2, 0, 0, 1, 2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        qvtkWidget3 = new QVTKWidget(tab_3);
        qvtkWidget3->setObjectName(QStringLiteral("qvtkWidget3"));

        gridLayout_5->addWidget(qvtkWidget3, 0, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_8->addWidget(label, 0, 0, 1, 1);

        proBar = new QProgressBar(centralwidget);
        proBar->setObjectName(QStringLiteral("proBar"));
        proBar->setValue(24);

        gridLayout_8->addWidget(proBar, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_8, 1, 0, 1, 1);

        PCLViewer->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1707, 26));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QStringLiteral("menu_T"));
        menuKdTree = new QMenu(menu_T);
        menuKdTree->setObjectName(QStringLiteral("menuKdTree"));
        QIcon icon20;
        icon20.addFile(QStringLiteral("images/tree.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuKdTree->setIcon(icon20);
        menuAbnzghu = new QMenu(menuBar);
        menuAbnzghu->setObjectName(QStringLiteral("menuAbnzghu"));
        menu_C = new QMenu(menuBar);
        menu_C->setObjectName(QStringLiteral("menu_C"));
        menu_L = new QMenu(menuBar);
        menu_L->setObjectName(QStringLiteral("menu_L"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        PCLViewer->setMenuBar(menuBar);
        toolBar = new QToolBar(PCLViewer);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        PCLViewer->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidget1 = new QDockWidget(PCLViewer);
        dockWidget1->setObjectName(QStringLiteral("dockWidget1"));
        dockWidget1->setMouseTracking(true);
        dockWidget1->setLayoutDirection(Qt::LeftToRight);
        dockWidget1->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        treeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setEnabled(true);
        treeWidget->setFocusPolicy(Qt::ClickFocus);
        treeWidget->setProperty("showDropIndicator", QVariant(false));

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);

        dockWidget1->setWidget(dockWidgetContents);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget1);
        dockWidget2 = new QDockWidget(PCLViewer);
        dockWidget2->setObjectName(QStringLiteral("dockWidget2"));
        dockWidget2->setAcceptDrops(true);
        dockWidget2->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableWidget = new QTableWidget(dockWidgetContents_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout_3->addWidget(tableWidget, 0, 0, 1, 1);

        dockWidget2->setWidget(dockWidgetContents_2);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget2);
        dockWidget3 = new QDockWidget(PCLViewer);
        dockWidget3->setObjectName(QStringLiteral("dockWidget3"));
        dockWidget3->setLayoutDirection(Qt::LeftToRight);
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QStringLiteral("dockWidgetContents_8"));
        gridLayout_7 = new QGridLayout(dockWidgetContents_8);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        listView = new QListView(dockWidgetContents_8);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setMouseTracking(true);

        gridLayout_7->addWidget(listView, 0, 0, 1, 1);

        dockWidget3->setWidget(dockWidgetContents_8);
        PCLViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget3);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menuBar->addAction(menu_L->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_C->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuAbnzghu->menuAction());
        menu_F->addAction(action_open);
        menu_F->addAction(action_saveas);
        menu_F->addSeparator();
        menu_F->addAction(action_exit);
        menu_T->addAction(action_zoomin);
        menu_T->addAction(action_zoomout);
        menu_T->addAction(action_zoom);
        menu_T->addSeparator();
        menu_T->addAction(action_compress);
        menu_T->addAction(action_cluster);
        menu_T->addAction(menuKdTree->menuAction());
        menu_T->addAction(action_voxel);
        menu_T->addSeparator();
        menu_T->addAction(action_trim);
        menu_T->addAction(action_screenshot);
        menu_T->addSeparator();
        menu_T->addAction(action_copy);
        menuKdTree->addAction(action_KNN);
        menuKdTree->addAction(action_Radius);
        menuAbnzghu->addAction(action_setting);
        menuAbnzghu->addAction(action_about);
        menuAbnzghu->addSeparator();
        menuAbnzghu->addAction(action_help);
        menuAbnzghu->addAction(action_beta);
        menu_C->addAction(action_las2txt);
        menu_C->addAction(action_txt2pcd);
        menu_C->addAction(action_pcdb2pcda);
        menu_C->addAction(action_pcd2txt);
        menu_L->addAction(action_pass);
        menu_L->addAction(action_voxelgrid);
        menu_L->addAction(action_outliner);
        menu_L->addAction(action_project);
        menu_L->addSeparator();
        menu_L->addAction(action_cloud2grayimage);
        menu_L->addAction(action_vegetation);
        menu_V->addAction(action_viewer1);
        menu_V->addAction(action_viewer2);
        menu_V->addAction(action_viewer4);
        menu_V->addSeparator();
        menu_V->addAction(action_fullscreen);
        menu_V->addAction(action_coordinate);
        menu->addAction(action_fixintensity_2);
        menu->addAction(action_kdtree_2);
        menu->addAction(action_binarysignal_2);
        menu->addSeparator();
        menu->addAction(action_image2cloud);
        menu->addAction(action_rgbresampling);
        toolBar->addAction(action_open);
        toolBar->addAction(action_saveas);
        toolBar->addSeparator();
        toolBar->addAction(action_zoomin);
        toolBar->addAction(action_zoom);
        toolBar->addAction(action_zoomout);
        toolBar->addSeparator();
        toolBar->addAction(action_viewer1);
        toolBar->addAction(action_viewer2);
        toolBar->addAction(action_viewer4);
        toolBar->addSeparator();
        toolBar->addAction(action_pass);
        toolBar->addAction(action_trim);
        toolBar->addAction(action_screenshot);
        toolBar->addSeparator();
        toolBar->addAction(action_txt2pcd);
        toolBar->addAction(action_beta);

        retranslateUi(PCLViewer);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0));
        action_open->setText(QApplication::translate("PCLViewer", "\346\211\223\345\274\200(&p)", 0));
        action_voxel->setText(QApplication::translate("PCLViewer", "\344\275\223\347\264\240\345\214\226", 0));
        action_KNN->setText(QApplication::translate("PCLViewer", "KNN", 0));
        action_Radius->setText(QApplication::translate("PCLViewer", "Radius", 0));
        action_cluster->setText(QApplication::translate("PCLViewer", "\350\201\232\347\261\273", 0));
        action_compress->setText(QApplication::translate("PCLViewer", "\345\216\213\347\274\251", 0));
        action_about->setText(QApplication::translate("PCLViewer", "\345\205\263\344\272\216", 0));
        action_las2txt->setText(QApplication::translate("PCLViewer", "LAS\350\275\254TXT", 0));
        action_pass->setText(QApplication::translate("PCLViewer", "PassThrough \347\233\264\351\200\232\346\273\244\346\263\242", 0));
        action_voxelgrid->setText(QApplication::translate("PCLViewer", "VoxelGrid \344\270\213\351\207\207\346\240\267", 0));
        action_outliner->setText(QApplication::translate("PCLViewer", "StatisicalOutlierRemoval \347\247\273\351\231\244\347\246\273\347\276\244\347\202\271", 0));
        action_project->setText(QApplication::translate("PCLViewer", "Projection \347\202\271\344\272\221\346\212\225\345\275\261", 0));
        action66->setText(QApplication::translate("PCLViewer", "\346\217\220\345\217\226\347\264\242\345\274\225", 0));
        action_pcdb2pcda->setText(QApplication::translate("PCLViewer", "PCD(Binary)\350\275\254PCD(ASCII)", 0));
        action_fixintensity->setText(QApplication::translate("PCLViewer", "\345\217\215\345\260\204\345\274\272\345\272\246\344\277\256\345\244\215", 0));
        action_txt2pcd->setText(QApplication::translate("PCLViewer", "TXT\350\275\254PCD(ASCII)", 0));
        action_pcd2txt->setText(QApplication::translate("PCLViewer", "PCD(ASCII)\350\275\254TXT", 0));
        action_kdtree->setText(QApplication::translate("PCLViewer", "Kd-Tree \350\266\205\350\201\232\347\261\273", 0));
        action_exit->setText(QApplication::translate("PCLViewer", "\351\200\200\345\207\272", 0));
        action_binarysignal->setText(QApplication::translate("PCLViewer", "\344\272\214\350\277\233\345\210\266\344\277\241\345\217\267\347\224\237\346\210\220", 0));
        action_cloud2grayimage->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\350\275\254\347\201\260\345\272\246\345\233\276", 0));
        action_zoomin->setText(QApplication::translate("PCLViewer", "\346\224\276\345\244\247", 0));
        action_zoomout->setText(QApplication::translate("PCLViewer", "\347\274\251\345\260\217", 0));
        action_trim->setText(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\350\243\201\345\211\252", 0));
        action_viewer1->setText(QApplication::translate("PCLViewer", "\345\215\225\350\247\206\345\233\276", 0));
        action_viewer2->setText(QApplication::translate("PCLViewer", "\345\217\214\350\247\206\345\233\276", 0));
        action_viewer4->setText(QApplication::translate("PCLViewer", "\345\244\232\350\247\206\345\233\276", 0));
        action_fixintensity_2->setText(QApplication::translate("PCLViewer", "\345\217\215\345\260\204\345\274\272\345\272\246\344\277\256\345\244\215", 0));
        action_kdtree_2->setText(QApplication::translate("PCLViewer", "Kd-Tree \350\266\205\350\201\232\347\261\273", 0));
        action_binarysignal_2->setText(QApplication::translate("PCLViewer", "\344\272\214\350\277\233\345\210\266\344\277\241\345\217\267\347\224\237\346\210\220", 0));
        action_image2cloud->setText(QApplication::translate("PCLViewer", "\345\233\276\347\211\207\350\275\254\344\270\211\347\273\264\347\202\271\344\272\221", 0));
        action_help->setText(QApplication::translate("PCLViewer", "\344\275\277\347\224\250\350\257\264\346\230\216", 0));
        action_saveas->setText(QApplication::translate("PCLViewer", "\345\217\246\345\255\230\344\270\272", 0));
        action_zoom->setText(QApplication::translate("PCLViewer", "\350\277\230\345\216\237", 0));
        action_screenshot->setText(QApplication::translate("PCLViewer", "\346\210\252\345\233\276", 0));
        action_setting->setText(QApplication::translate("PCLViewer", "\350\256\276\347\275\256", 0));
        action_copy->setText(QApplication::translate("PCLViewer", "\345\244\215\345\210\266\347\202\271\344\272\221\346\226\207\344\273\266", 0));
        action_fullscreen->setText(QApplication::translate("PCLViewer", "\345\205\250\345\261\217\346\230\276\347\244\272", 0));
        action_coordinate->setText(QApplication::translate("PCLViewer", "\345\235\220\346\240\207\347\263\273", 0));
        action_vegetation->setText(QApplication::translate("PCLViewer", "\346\244\215\350\242\253\346\217\220\345\217\226", 0));
        action_beta->setText(QApplication::translate("PCLViewer", "AlphaTest", 0));
        action_rgbresampling->setText(QApplication::translate("PCLViewer", "\351\242\234\350\211\262\351\207\215\351\207\207\346\240\267", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PCLViewer", "\344\270\273\350\247\206\347\252\227", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PCLViewer", "\345\257\271\346\257\224\350\247\206\347\252\227 1x2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PCLViewer", "\345\257\271\346\257\224\350\247\206\347\252\227 2x2", 0));
        label->setText(QApplication::translate("PCLViewer", "\345\275\223\345\211\215\350\277\233\345\272\246\357\274\232", 0));
        menu_F->setTitle(QApplication::translate("PCLViewer", "\346\226\207\344\273\266(&F)", 0));
        menu_T->setTitle(QApplication::translate("PCLViewer", "\345\267\245\345\205\267(&T)", 0));
        menuKdTree->setTitle(QApplication::translate("PCLViewer", "KdTree", 0));
        menuAbnzghu->setTitle(QApplication::translate("PCLViewer", "\345\270\256\345\212\251(&H)", 0));
        menu_C->setTitle(QApplication::translate("PCLViewer", "\346\225\260\346\215\256\350\275\254\346\215\242(&C)", 0));
        menu_L->setTitle(QApplication::translate("PCLViewer", "\346\273\244\346\263\242(&L)", 0));
        menu_V->setTitle(QApplication::translate("PCLViewer", "\350\247\206\345\233\276(&V)", 0));
        menu->setTitle(QApplication::translate("PCLViewer", "\351\233\267\350\276\276\346\225\260\346\215\256\345\244\204\347\220\206(&L)", 0));
        toolBar->setWindowTitle(QApplication::translate("PCLViewer", "\345\267\245\345\205\267\346\240\217", 0));
        dockWidget1->setWindowTitle(QApplication::translate("PCLViewer", "\347\202\271\344\272\221\346\226\207\344\273\266\345\210\227\350\241\250", 0));
        dockWidget2->setWindowTitle(QApplication::translate("PCLViewer", "\345\261\236\346\200\247", 0));
        dockWidget3->setWindowTitle(QApplication::translate("PCLViewer", "\346\216\247\345\210\266\345\217\260", 0));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
