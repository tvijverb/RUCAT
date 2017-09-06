#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QEvent>
#include <QDebug>
#include <QCoreApplication>
#include <QThread>
#include <QtConcurrent>
#include <QOpenGLWidget>
#include <QHoverEvent>
#include <QApplication>
#include <QGraphicsLayout>

#include "DataModifier/gcdata.h"
#include "mainwindow.h"
#include "ImportSaveExport/importmzdata.h"
#include "UI/plottic.h"
#include "UI/chart.h"
#include "UI/chartview.h"
#include "UI/plotms.h"
#include "UI/dialog.h"
#include "UI/treetab_2.h"
#include "ImportSaveExport/exportcsv.h"
#include "DataModifier/interpolatetic.h"

class Controller : public QMainWindow
{
    Q_OBJECT
public:
    Controller(MainWindow * view);
	std::vector<GCData*> getGCData();

public slots:
    void openFile();
    void TICCSVSelected_File();
    void TICCSVALL_Files();
    void actionEmpty_TIC_plot();
    void actionInterpolate_Chromatogram();
    void treeViewUpdate();
    void on_rangeChanged();

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void futureReady();
	void getlineChartClicked(QPointF qpoint);


private:
    void connectActions();
    void initializeTreeWidget();
    void newDataLoaded(std::vector<GCData*> data);

private:
    MainWindow * view;
    std::vector<GCData*> data;
    QTreeWidgetItem * topLevel;
    QTreeWidget * tree;
    QLineSeries * series = new QLineSeries();
	ChartView * mychartView;
    QGraphicsScene * grpcs = new QGraphicsScene(this);
    QChart * mychart = new QChart();
    plotTIC mytic;
	plotMS myMS;
    treeTab_2 treetab;
    Dialog* progressbar = new Dialog();
    QCustomPlot *customPlot;
    QFutureWatcher<GCData *> futureWatcher;
    exportcsv *csvexporter;
    interpolatetic *interpolation;

private:
    int dataFreq = 10;

protected:
	//void resizeEvent(QResizeEvent *event);
};

#endif // CONTROLLER_H
