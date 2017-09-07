#include "plottic.h"

plotTIC::plotTIC()
{
}

bool plotTIC::getLineChartIsInit()
{
    return this->lineChartIsInit;
}

void plotTIC::setLineChartIsInit(bool chartstate)
{
    this->lineChartIsInit = chartstate;
}

int plotTIC::getClickedPointIndex(QAbstractSeries * myseries, QPointF clickedPoint)
{
    QLineSeries * mylineseries = (QLineSeries *)myseries;

    QPointF closest(INT_MAX, INT_MAX);
    // process items in numerical order by index
    // do something with "list[i]";
    qreal distance(INT_MAX);

    int j = 0;
    int k = 0;
    foreach(QPointF currentPoint, mylineseries->points()) {
        qreal currentDistance = qSqrt((currentPoint.x() - clickedPoint.x())
            * (currentPoint.x() - clickedPoint.x())
            + (2 - 1)
            * (2 - 1));
        if (currentDistance < distance) {
            distance = currentDistance;
            closest = currentPoint;
            k = j;
        }
        j++;
    }
    return k;
}

int plotTIC::numDigits(int32_t x)
{
    if (x == INT_MIN) return 10 + 1;
    if (x < 0) return numDigits(-x) + 1;

    if (x >= 10000) {
        if (x >= 10000000) {
            if (x >= 100000000) {
                if (x >= 1000000000)
                    return 10;
                return 9;
            }
            return 8;
        }
        if (x >= 100000) {
            if (x >= 1000000)
                return 7;
            return 6;
        }
        return 5;
    }
    if (x >= 100) {
        if (x >= 1000)
            return 4;
        return 3;
    }
    if (x >= 10)
        return 2;
    return 1;
}

void plotTIC::clearLineChart(QChart * chart, std::vector<GCData *> dataset)
{
	series2 = chart->series();

	for (int i = 0; i < series2.size(); i++)
	{
		chart->removeSeries(series2.at(i));
	}
    for(int i = 0; i < dataset.size(); i++)
    {
        dataset[i]->setLineSeriesOnChart(false);
    }

}

void plotTIC::removeSeriesLineChart(QChart * chart,GCData* data)
{
    if(data->hasCurrentSeriesOnChart())
    {
        series3 = data->getCurrentLineSeries();
    }
    if(data->getLineSeriesOnChart())
    {
        series3 = data->getScanLineSeries();
    }
    chart->removeSeries(series3);
    data->setLineSeriesOnChart(false);
}

ChartView * plotTIC::redrawLineChart(QRect graphicsViewRect)
{
	this->chart->setGeometry(graphicsViewRect);
	this->chartView->setGeometry(graphicsViewRect);

	//this->chartView = new ChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	return chartView;
}



QChart * plotTIC::plotsingleTIC(GCData* data, std::vector<GCData *> dataset, QChart * chart){
    // Get graphics scene from GCData file
    qDebug() << "Plotting TIC";

    if(data->hasUpdateCurrLineSeries())
    {
        series3 = data->getPreviousSeries();
        chart->removeSeries(series3);
        data->setLineSeriesOnChart(false);
        data->setHasUpdateCurrLineSeries(false);
        //return chart;
    }
    series3 = data->getCurrentLineSeries();

    series3->setUseOpenGL(true);
    chart->legend()->hide();

    qDebug() << series3->points();
    if(data->getLineSeriesOnChart() == false)
    {
        chart->addSeries(series3);
        data->setLineSeriesOnChart(true);
		std::cout << "Series added to chart.";
		qDebug() << QString("Series added to chart");
    }
	else
	{
		chart->removeSeries(series3);
		data->setLineSeriesOnChart(false);
		qDebug() << QString("ERROR: this series was already on the chart, removing QLineSeries");
	}
	
    int max_at = 0;
	int max_currently = 0;
    int max_time_at = 0;
    QTime max_time_currently = QTime(0,0,0,0);
	
	for(int i = 0; i < dataset.size(); i++)
	{
        if(dataset[i]->getLineSeriesOnChart())
		{
            if(dataset[i]->getMaxTicValue() > max_currently)
            {
                max_currently = dataset[i]->getMaxTicValue();
				max_at = i;
            }
            if(dataset[i]->getMaxTimeValue() > max_time_currently)
            {
                max_time_currently = dataset[i]->getMaxTimeValue();
                max_time_at = i;
            }

		}
	}

    int zeros = numDigits(max_currently);
    double denom = max_currently / std::pow(10,zeros);
    int round_to = ceil(denom*10);

    chart->createDefaultAxes();
    series2 = chart->series();
    chart->addAxis(dataset[max_time_at]->XAxis(), Qt::AlignBottom);

    for(int i = 0; i < series2.size(); i++)
    {
        chart->removeAxis(chart->axisX(series2.at(i)));
        series2.at(i)->attachAxis(dataset[max_time_at]->XAxis());
    }

    for(int i = 0; i < dataset.size(); i++)
    {
        if(dataset[i]->getLineSeriesOnChart())
        {
            dataset[i]->setXAxis(dataset[max_time_at]->XAxis());
        }
    }
    series3->attachAxis(dataset[max_time_at]->XAxis());
    chart->axisY()->setMax(std::pow(10,zeros-1)*round_to);

    chart->setAnimationOptions(QChart::NoAnimation);
    chart->removeAxis(chart->axisX(series2.front()));
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(20);
    axisX->setFormat("m:ss");
    axisX->setTitleText("Retention Time (min)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series2.front()->attachAxis(axisX);

    return chart;
}
