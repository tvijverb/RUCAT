#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>

#include <QtWidgets/QMainWindow>
#include <QObject>
#include <QDebug>

#include "gcdata.h"
#include "mainwindow.h"
#include "importmzdata.h"
#include "plottic.h"
#include "chart.h"
#include "chartview.h"
#include "plotms.h"
#include "dialog.h"
#include "treetab_2.h"

class Controller : public QMainWindow
{
    Q_OBJECT
public:
    Controller(MainWindow * view);
	std::vector<GCData*> getGCData();

public slots:
    void openFile();
    void treeViewUpdate();

private slots:
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
	void on_splitter_moved();
    void redrawTIC();
	void resizeEvent(QResizeEvent *event);
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
	ChartView * myBarChartView;
    QGraphicsScene * grpcs = new QGraphicsScene();
	QGraphicsScene * grpcs_2 = new QGraphicsScene();
    plotTIC mytic;
	plotMS myMS;
    treeTab_2 treetab;
    Dialog* progressbar_2 = new Dialog();

protected:
	//void resizeEvent(QResizeEvent *event);
};

#endif // CONTROLLER_H
