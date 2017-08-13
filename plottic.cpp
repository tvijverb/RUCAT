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

ChartView * plotTIC::clearLineChart()
{
    this->chart = new QChart();
	this->chartView = new ChartView(chart);
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

ChartView * plotTIC::plotsingleTIC(GCData * data, QRect graphicsViewRect){
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

    //QChart *chart = new QChart();
    QDateTime momentInTime;

    QLineSeries *series3= data->getScanLineSeries();

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
		return chartView;
	}

    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<std::endl;
    int firstmin = floor(ScanRT_i.front()/60000);
    int lastmin = floor(ScanRT_i.back()/60000);

    chart->setAnimationOptions(QChart::NoAnimation);
    chart->legend()->hide();
    chart->createDefaultAxes();
    //chart->setBackgroundVisible(false);
    //chart->setMargins(QMargins(0,0,0,0));
    //chart->layout()->setContentsMargins(0,0,0,0);
    chart->setPlotAreaBackgroundBrush(QBrush(Qt::white));
    chart->setPlotAreaBackgroundVisible(true);
    chart->setGeometry(graphicsViewRect);	
    QList<QAbstractSeries*> series2 = chart->series();

    chart->axisY(series2.front())->setTitleText(QString("Reconstructed Ion Count (RIC)"));
    chart->axisY(series2.front())->setMin(0);

    chart->removeAxis(chart->axisX(series2.front()));
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(lastmin-firstmin);
    axisX->setFormat("m:ss");
    axisX->setTitleText("Retention Time (min)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series2.front()->attachAxis(axisX);

	if (!lineChartIsInit)
	{
		this->chartView = new ChartView(chart);
		chartView->setRenderHint(QPainter::Antialiasing);
	}
    //QGraphicsScene * grpcs;
    //grpcs = new QGraphicsScene();
    //grpcs->addWidget(chartView);
    return chartView;
}
