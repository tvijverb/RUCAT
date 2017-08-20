#ifndef PLOTTIC_H
#define PLOTTIC_H

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <climits>

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
    int numDigits(int32_t x);

    bool lineChartIsInit = false;
	ChartView *chartView;
    QLineSeries *series;
    GCData * data;
	QChart * chart = new QChart();
    QDateTimeAxis * axisX = new QDateTimeAxis;
    QDateTime momentInTime;
    QList<QAbstractSeries*> series2;
    QValueAxis * axisY = new QValueAxis();
};

#endif // PLOTTIC_H
