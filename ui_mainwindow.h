/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_file;
    QAction *actionBatch_Open;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionConcentration_Timeline;
    QAction *actionPeak_Pick_Chromatograms;
    QAction *actionIntegrate_Peaks;
    QAction *actionPCA_Analysis;
    QAction *actionGenerate_CSV_integrated_peaklist;
    QAction *actionTechnical_Support;
    QAction *actionReport_A_Bug;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTreeView *treeView;
    QWidget *tab_2;
    QTreeWidget *treeWidget;
    QGraphicsView *graphicsView;
    QSplitter *splitter_2;
    QListView *listView_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *qcWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1041, 563);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(85, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush2(QColor(170, 170, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        QBrush brush4(QColor(247, 247, 247, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush2);
        MainWindow->setPalette(palette);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon);
        actionBatch_Open = new QAction(MainWindow);
        actionBatch_Open->setObjectName(QStringLiteral("actionBatch_Open"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionConcentration_Timeline = new QAction(MainWindow);
        actionConcentration_Timeline->setObjectName(QStringLiteral("actionConcentration_Timeline"));
        actionPeak_Pick_Chromatograms = new QAction(MainWindow);
        actionPeak_Pick_Chromatograms->setObjectName(QStringLiteral("actionPeak_Pick_Chromatograms"));
        actionIntegrate_Peaks = new QAction(MainWindow);
        actionIntegrate_Peaks->setObjectName(QStringLiteral("actionIntegrate_Peaks"));
        actionPCA_Analysis = new QAction(MainWindow);
        actionPCA_Analysis->setObjectName(QStringLiteral("actionPCA_Analysis"));
        actionGenerate_CSV_integrated_peaklist = new QAction(MainWindow);
        actionGenerate_CSV_integrated_peaklist->setObjectName(QStringLiteral("actionGenerate_CSV_integrated_peaklist"));
        actionTechnical_Support = new QAction(MainWindow);
        actionTechnical_Support->setObjectName(QStringLiteral("actionTechnical_Support"));
        actionReport_A_Bug = new QAction(MainWindow);
        actionReport_A_Bug->setObjectName(QStringLiteral("actionReport_A_Bug"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        centralWidget->setPalette(palette1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 0, -1, 0);
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        treeView = new QTreeView(tab);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(0, 0, 391, 221));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush);
        treeView->setPalette(palette2);
        treeView->setStyleSheet(QLatin1String("QTreeWidget#TreeWithBranches::branch:has-siblings,\n"
"QTreeWidget#TreeWithBranches::branch:open:has-children:has-siblings,\n"
"QTreeView#TreeWithBranches::branch:has-siblings,\n"
"QTreeView#TreeWithBranches::branch:open:has-children:has-siblings {\n"
"  background: url(:/Resources/icons/vline.png);\n"
"  background-repeat: repeat-y;\n"
"  background-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:has-siblings:adjoins-item,\n"
"QTreeView#TreeWithBranches::branch:has-siblings:adjoins-item {\n"
"  image: url(:/Resources/icons/branch-more.png);\n"
"  image-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:!has-siblings:adjoins-item,\n"
"QTreeView#TreeWithBranches::branch:!has-siblings:adjoins-item {\n"
"  background: none;\n"
"  image: url(:/Resources/icons/branch-end.png);\n"
"  image-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:closed:has-children,\n"
"QTreeView#TreeWithBranches::branch:closed:has-children {\n"
"  image: url(:/Resources/icons/branch-closed.png);\n"
"  "
                        "image-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:open:has-children,\n"
"QTreeView#TreeWithBranches::branch:open:has-children {\n"
"  image: url(:/Resources/icons/branch-open.png);\n"
"  image-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:closed:has-children:!has-siblings:adjoins-item,\n"
"QTreeView#TreeWithBranches::branch:closed:has-children:!has-siblings:adjoins-item {\n"
"  background: url(:/Resources/icons/branch-end.png);\n"
"  background-repeat: no-repeat;\n"
"  background-position: top;\n"
"  image: url(:/Resources/icons/branch-closed.png);\n"
"  image-position: top;\n"
"}\n"
"QTreeWidget#TreeWithBranches::branch:open:has-children:!has-siblings:adjoins-item,\n"
"QTreeView#TreeWithBranches::branch:open:has-children:!has-siblings:adjoins-item {\n"
"  background: url(:/Resources/icons/branch-end.png);\n"
"  background-repeat: no-repeat;\n"
"  background-position: top;\n"
"  image: url(:/Resources/icons/branch-open.png);\n"
"  image-position: top;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(-5, 1, 401, 221));
        treeWidget->header()->setVisible(false);
        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(450, 250));
        QPalette palette3;
        QBrush brush6(QColor(168, 168, 168, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        graphicsView->setPalette(palette3);
        graphicsView->setAutoFillBackground(true);
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setLineWidth(0);
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        graphicsView->setRubberBandSelectionMode(Qt::ContainsItemShape);
        graphicsView->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing|QGraphicsView::DontClipPainter|QGraphicsView::DontSavePainterState|QGraphicsView::IndirectPainting);
        splitter->addWidget(graphicsView);
        splitter_3->addWidget(splitter);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setSizeIncrement(QSize(1, 1));
        splitter_2->setMouseTracking(true);
        splitter_2->setAutoFillBackground(true);
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(2);
        listView_2 = new QListView(splitter_2);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setBaseSize(QSize(200, 0));
        splitter_2->addWidget(listView_2);
        dockWidget = new QDockWidget(splitter_2);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout_2 = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(1, 1, 1, 1);
        qcWidget = new QCustomPlot(dockWidgetContents_2);
        qcWidget->setObjectName(QStringLiteral("qcWidget"));

        horizontalLayout_2->addWidget(qcWidget);

        dockWidget->setWidget(dockWidgetContents_2);
        splitter_2->addWidget(dockWidget);
        splitter_3->addWidget(splitter_2);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1041, 21));
        QPalette palette4;
        QBrush brush7(QColor(160, 160, 160, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        menuBar->setPalette(palette4);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionBatch_Open);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit);
        menuTools->addAction(actionConcentration_Timeline);
        menuTools->addAction(actionPeak_Pick_Chromatograms);
        menuTools->addAction(actionIntegrate_Peaks);
        menuTools->addAction(actionPCA_Analysis);
        menuTools->addAction(actionGenerate_CSV_integrated_peaklist);
        menuHelp->addAction(actionTechnical_Support);
        menuHelp->addAction(actionReport_A_Bug);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionOpen_file);
        mainToolBar->addAction(actionSave);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", 0));
        actionBatch_Open->setText(QApplication::translate("MainWindow", "Batch Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionConcentration_Timeline->setText(QApplication::translate("MainWindow", "Align Chromatograms", 0));
        actionPeak_Pick_Chromatograms->setText(QApplication::translate("MainWindow", "Peak Pick Chromatograms", 0));
        actionIntegrate_Peaks->setText(QApplication::translate("MainWindow", "Integrate Peaks", 0));
        actionPCA_Analysis->setText(QApplication::translate("MainWindow", "PCA Analysis", 0));
        actionGenerate_CSV_integrated_peaklist->setText(QApplication::translate("MainWindow", "Generate .CSV integrated peaklist", 0));
        actionTechnical_Support->setText(QApplication::translate("MainWindow", "Technical Support", 0));
        actionReport_A_Bug->setText(QApplication::translate("MainWindow", "Report A Bug", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "File Browser", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "GC-MS files", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
