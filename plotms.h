#ifndef PLOTMS_H
#define PLOTMS_H
#define QCUSTOMPLOT_COMPILE_LIBRARY

#include <string>

#include <QString>
#include <QObject>
#include <QBarSeries>
#include <QBarset>
#include <QBarCategoryAxis>
#include <QFont>
#include <QVector>

#include <gcdata.h>
#include "qcustomplot.h"

class plotMS : public QObject
{
    Q_OBJECT
public:
    explicit plotMS(QObject *parent = 0);

	bool getBarChartIsInit();
	void setBarChartIsInit(bool chartstate);

	ChartView * clearBarChart();
	ChartView * redrawBarChart(QRect graphicsViewRect);
    QCustomPlot * plotsingleMS(std::vector<GCData*> data, int, QCustomPlot *customPlot);

private:
    bool barChartIsInit = false;
    ChartView * chartView;
    GCData * data;
	QBarSeries *series2 = new QBarSeries();
	QChart * chart2 = new QChart();

signals:

public slots:
};

#endif // PLOTMS_H
