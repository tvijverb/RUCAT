/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"
#include "UI/chartview.h"

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
    QAction *actionTICCSVSelected_File;
    QAction *actionTICCSVAll_Files;
    QAction *actionEmpty_TIC_plot;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_3;
    QHBoxLayout *horizontalLayout_3;
    ChartView *ticplot;
    QSplitter *splitter_2;
    QListView *listView_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *qcWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuTIC_CSV;
    QMenu *menuTools;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(823, 580);
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
        QIcon icon;
        icon.addFile(QStringLiteral("png/RU.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionOpen_file = new QAction(MainWindow);
        actionOpen_file->setObjectName(QStringLiteral("actionOpen_file"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/png/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon1);
        actionBatch_Open = new QAction(MainWindow);
        actionBatch_Open->setObjectName(QStringLiteral("actionBatch_Open"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/png/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
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
        actionTICCSVSelected_File = new QAction(MainWindow);
        actionTICCSVSelected_File->setObjectName(QStringLiteral("actionTICCSVSelected_File"));
        actionTICCSVAll_Files = new QAction(MainWindow);
        actionTICCSVAll_Files->setObjectName(QStringLiteral("actionTICCSVAll_Files"));
        actionEmpty_TIC_plot = new QAction(MainWindow);
        actionEmpty_TIC_plot->setObjectName(QStringLiteral("actionEmpty_TIC_plot"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/png/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmpty_TIC_plot->setIcon(icon3);
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
        QFont font;
        font.setFamily(QStringLiteral("MS Sans Serif"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Sans Serif"));
        font1.setPointSize(16);
        font1.setStyleStrategy(QFont::PreferAntialias);
        tab->setFont(font1);
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeView = new QTreeView(tab);
        treeView->setObjectName(QStringLiteral("treeView"));
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
        treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeView->setAutoScrollMargin(5);

        verticalLayout->addWidget(treeView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        QFont font2;
        font2.setStyleStrategy(QFont::PreferAntialias);
        tab_2->setFont(font2);
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->header()->setVisible(false);

        verticalLayout_2->addWidget(treeWidget);

        tabWidget->addTab(tab_2, QString());
        splitter->addWidget(tabWidget);
        dockWidget_2 = new QDockWidget(splitter);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidget_2->setMinimumSize(QSize(450, 300));
        dockWidget_2->setFont(font);
        dockWidget_2->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        horizontalLayout_3 = new QHBoxLayout(dockWidgetContents_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        ticplot = new ChartView(dockWidgetContents_3);
        ticplot->setObjectName(QStringLiteral("ticplot"));

        horizontalLayout_3->addWidget(ticplot);

        dockWidget_2->setWidget(dockWidgetContents_3);
        splitter->addWidget(dockWidget_2);
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
        dockWidget->setMinimumSize(QSize(450, 200));
        dockWidget->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/png/bar.png"), QSize(), QIcon::Normal, QIcon::Off);
        dockWidget->setWindowIcon(icon4);
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
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
        menuBar->setGeometry(QRect(0, 0, 823, 21));
        QPalette palette3;
        QBrush brush6(QColor(160, 160, 160, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        menuBar->setPalette(palette3);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuTIC_CSV = new QMenu(menuExport);
        menuTIC_CSV->setObjectName(QStringLiteral("menuTIC_CSV"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addAction(actionSave);
        menuFile->addAction(menuExport->menuAction());
        menuFile->addAction(actionExit);
        menuExport->addAction(menuTIC_CSV->menuAction());
        menuTIC_CSV->addAction(actionTICCSVSelected_File);
        menuTIC_CSV->addAction(actionTICCSVAll_Files);
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
        mainToolBar->addAction(actionEmpty_TIC_plot);

        retranslateUi(MainWindow);
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), tabWidget, SLOT(update()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen_file->setText(QApplication::translate("MainWindow", "Open file", Q_NULLPTR));
        actionBatch_Open->setText(QApplication::translate("MainWindow", "Batch Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionConcentration_Timeline->setText(QApplication::translate("MainWindow", "Align Chromatograms", Q_NULLPTR));
        actionPeak_Pick_Chromatograms->setText(QApplication::translate("MainWindow", "Peak Pick Chromatograms", Q_NULLPTR));
        actionIntegrate_Peaks->setText(QApplication::translate("MainWindow", "Integrate Peaks", Q_NULLPTR));
        actionPCA_Analysis->setText(QApplication::translate("MainWindow", "PCA Analysis", Q_NULLPTR));
        actionGenerate_CSV_integrated_peaklist->setText(QApplication::translate("MainWindow", "Generate .CSV integrated peaklist", Q_NULLPTR));
        actionTechnical_Support->setText(QApplication::translate("MainWindow", "Technical Support", Q_NULLPTR));
        actionReport_A_Bug->setText(QApplication::translate("MainWindow", "Report A Bug", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionTICCSVSelected_File->setText(QApplication::translate("MainWindow", "Selected File", Q_NULLPTR));
        actionTICCSVAll_Files->setText(QApplication::translate("MainWindow", "All Files", Q_NULLPTR));
        actionEmpty_TIC_plot->setText(QApplication::translate("MainWindow", "Empty TIC plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "File Browser", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "GC-MS files", Q_NULLPTR));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Total Ion Current Chromatogram", Q_NULLPTR));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Mass Spectrum", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        menuTIC_CSV->setTitle(QApplication::translate("MainWindow", "TIC CSV", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
