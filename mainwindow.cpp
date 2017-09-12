#include <string>
#include <vector>
#include <chrono>
#include <stdint.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QtMath>
#include <QtCharts/QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QObject>
#include <QFileDialog>
#include "QtCore/QByteArray"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ImportSaveExport\importmzdata.h"
#include "UI/chart.h"
#include "UI/chartview.h"
#include "UI/dialog.h"

typedef uint32_t u_int32_t;

QT_CHARTS_USE_NAMESPACE


void MainWindow::drawBarChart()
{

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();

    // Set QDark stylesheet
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());

        ui->centralWidget->layout()->setContentsMargins(0, 0, 0, 0);
    }

	QDirModel * model = new QDirModel();

	// Enable modifying file system
    model->setReadOnly(true);

	// Tie TreeView with DirModel
	ui->treeView->setModel(model);
    //ui->treeView->setAlternatingRowColors(true);
    ui->treeView->setPalette( QApplication::palette( ui->treeView ) );
    ui->treeView->setAnimated(false);
    ui->treeView->setIndentation(20);
    ui->treeView->setSortingEnabled(true);
    //ui->treeView->expandToDepth(0);
    ui->treeView->resizeColumnToContents(0);

}
void MainWindow::resizeEvent(QResizeEvent *event)
{
	emit MainWindowResized(event);
}

MainWindow::~MainWindow()
{
    writeSettings();
    delete ui;
}

void MainWindow::on_splitter_splitterMoved()
{
    //if(strllen != 0){
    //    drawChart();
    //}
}

void MainWindow::on_splitter_3_splitterMoved()
{
    //if(strllen != 0){
    //    drawChart();
    //}
}

void MainWindow::on_splitter_2_splitterMoved()
{
    //if(strllen != 0){
    //    drawChart();
    //}
}

void MainWindow::writeSettings()
{
    QSettings settings;
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.setValue("split1",this->ui->splitter->saveState());
    settings.setValue("split2",this->ui->splitter_2->saveState());
    settings.setValue("split3",this->ui->splitter_3->saveState());
    settings.setValue("tabWidget",this->ui->tabWidget->geometry());
}

void MainWindow::readSettings()
{
    QSettings settings;
    qDebug() << "Reading settings from: " << settings.fileName();
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    this->ui->splitter->restoreState(settings.value("split1", QByteArray()).toByteArray());
    this->ui->splitter_2->restoreState(settings.value("split2", QByteArray()).toByteArray());
    this->ui->splitter_3->restoreState(settings.value("split3", QByteArray()).toByteArray());
    this->ui->tabWidget->restoreGeometry(settings.value("tabWidget", QByteArray()).toByteArray());
}

void MainWindow::openProgressbar()
{
    Dialog progressbar;

}
#include "moc_mainwindow.cpp"
