#ifndef PLOTTIC_H
#define PLOTTIC_H

#include <string>
#include <vector>
#include <chrono>
#include <iostream>

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtCharts/QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QAbstractSeries>
#include <QDateTime>
#include <QDebug>
#include <QtMath>

#include "chart.h"
#include "chartview.h"
#include "gcdata.h"

class plotTIC
{
public:
    plotTIC();

    bool getLineChartIsInit();
    void setLineChartIsInit(bool chartstate);
    int getClickedPointIndex(QAbstractSeries *, QPointF);

	ChartView * clearLineChart();
    QChart * plotsingleTIC(GCData * data, QChart *);
	ChartView * redrawLineChart(QRect graphicsViewRect);

public:
    QGraphicsScene * grpcs;

private:
    bool lineChartIsInit = false;
	ChartView *chartView;
    QLineSeries *series;
    GCData * data;
	QChart * chart = new QChart();
};

#endif // PLOTTIC_H
