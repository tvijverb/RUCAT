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

ChartView * plotTIC::clearLineChart()
{
    //this->chart = new QChart();
    //this->chartView = new ChartView(chart);
    return chartView;
}

ChartView * plotTIC::redrawLineChart(QRect graphicsViewRect)
{
	this->chart->setGeometry(graphicsViewRect);
	this->chartView->setGeometry(graphicsViewRect);

	//this->chartView = new ChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	return chartView;
}

QChart * plotTIC::plotsingleTIC(GCData * data, QChart * chart){
    // Get graphics scene from GCData file
    
    std::vector<int> ScanRT_i;
    std::vector<int> scan_tic;
    int currtime;
    int starttime;
    int endtime;
    int min;
    int s;
    int ms;
    int min2;
    int s2;
    int ms2;
    QLineSeries * series3 = data->getScanLineSeries();

    series3->setUseOpenGL(true);
    ScanRT_i = data->getScanRT_i();
    scan_tic = data->getScanTIC();

    starttime = ScanRT_i.front();
    endtime = ScanRT_i.back();
    min = floor(starttime/60000);
    s = floor((starttime-min*60000)/1000);
    ms = (starttime-min*60000-s*1000);

    min2 = floor(endtime/60000);
    s2 = floor((endtime-min2*60000)/1000);
    ms2 = (endtime-min2*60000-s2*1000);
    QTime time(0,min2,s2,ms2);
    time.addSecs(-min*60);
    time.addSecs(-s);
    time.addMSecs(-ms);
    int firstmin = floor(ScanRT_i.front()/60000);
    int lastmin = floor(ScanRT_i.back()/60000);

    chart->legend()->hide();
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chart->setPlotAreaBackgroundVisible(true);

    std::vector<int>::iterator maxit = std::max_element(std::begin(scan_tic), std::end(scan_tic));
    int max = scan_tic[std::distance(std::begin(scan_tic), maxit)];
    int zeros = numDigits(max);
    double denom = max / std::pow(10,zeros);
    int round_to = ceil(denom*10);

    axisY->setMax(std::pow(10,zeros-1)*round_to);
    axisY->setMin(0);
    axisY->setTickCount(round_to+1);
    axisY->setTitleText(QString("Reconstructed Ion Count (RIC)"));

    axisX->setTickCount(lastmin-firstmin);
    axisX->setFormat("m:ss");
    axisX->setTitleText("Retention Time (min)");

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
        return chart;
	}
    series2 = chart->series();

    for(int i = 0; i < series2.size(); i++)
    {
        QList<QAbstractAxis*> list = series2.at(i)->attachedAxes();
        for(int j = 0; j < list.size()-1; j++)
        {
            //chart->removeAxis(list.at(j));
        }
    }


    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    series3->attachAxis(axisY);
    series3->attachAxis(axisX);

    return chart;
}
