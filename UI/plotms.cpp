#include "plotms.h"

#include <qvector.h>
#include <iterator>

#include <qvalueaxis.h>


plotMS::plotMS(QObject *parent) : QObject(parent)
{

}

bool plotMS::getBarChartIsInit()
{
	return this->barChartIsInit;
}

void plotMS::setBarChartIsInit(bool chartstate)
{
	this->barChartIsInit = chartstate;
}

ChartView * plotMS::clearBarChart()
{
    //this->chart2 = new QChart();
    //this->chartView = new ChartView(chart2);
    return chartView;
}

ChartView * plotMS::redrawBarChart(QRect graphicsViewRect)
{
	this->chart2->setGeometry(graphicsViewRect);
	this->chartView->setGeometry(graphicsViewRect);

	//this->chartView = new ChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	return chartView;
}

std::vector<int> plotMS::getGCDataOnChart(std::vector<GCData*> vecdata)
{
	std::vector<int> onChart;
	for (int i = 0; i < vecdata.size(); i++)
	{
		GCData *data = vecdata.at(i);
		if (data->getLineSeriesOnChart() == false)
		{
			onChart.push_back(0);
		}
		else
		{
			onChart.push_back(1);
		}
	}
	return(onChart);
}

QCustomPlot * plotMS::plotsingleMS(std::vector<GCData*> data, int clickedPoints_index, QCustomPlot *customPlot)
{

	//Input
	assert(data.size() != 0);


    // Debugging info
	std::vector<int> onChart = getGCDataOnChart(data);
	int sum_of_elems = 0;
	int first_plotted_data = 0;
	int first_plotted_data_isset = 0;

	for (int index = 0; index < onChart.size(); index++)
	{
		sum_of_elems += onChart[index];
		if (onChart[index] == 1 && first_plotted_data_isset == 0)
		{
			first_plotted_data = index;
			first_plotted_data_isset = 1;
		}
	}

	qDebug() << "Number of QLineSeries on TIC: " << sum_of_elems;
	qDebug() << "Showing plot:" << first_plotted_data << "from treeview.";

	if (sum_of_elems > 1)
	{
		qDebug() << "Multiple charts are in TIC plot, Mass Spectrum plot only supports one plot.";
		qDebug() << "Showing MS from top (visible) TIC @ TreeView: " << first_plotted_data;
	}

	if (sum_of_elems == 0)
	{
		return customPlot;
	}

    // Clear MS plot
	customPlot->clearPlottables();

    QVector<MSData*> mymsdata;
	QVector<Scan> scans;

    mymsdata.append(data.at(first_plotted_data)->getMSData());
    MSData *d = (mymsdata.at(0));
    scans.append(d->getScan(clickedPoints_index));

	// create empty bar chart objects:
	QCPBars *bar1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	bar1->setAntialiased(false); // gives more crisp, pixel aligned bar borders

	// set names and colors:
	bar1->setName("bar1erative");
	bar1->setPen(QPen(QColor(0, 168, 140).lighter(130)));
	bar1->setBrush(QColor(0, 168, 140));

	// prepare x axis with labels:
	// x1:
	QVector<double> ticks;
	QVector<QString> labels;
	std::vector<std::stringstream> stream;
	std::vector<std::string> stringVec;
	std::stringstream mystream;
	std::string mystring;

	std::vector<double> doubleVec(scans.at(0).x.begin(), scans.at(0).x.end());

	for (int index = 0; index < doubleVec.size(); index++)
	{
		doubleVec.at(index) = round(doubleVec.at(index) * 1000.0) / 1000.0;
		
		std::ostringstream mystream;
		mystream << std::fixed << std::setprecision(2) << doubleVec.at(index);
		mystring = mystream.str();
		if (index % 2)
		{
			mystring = ("");
		}
		stringVec.push_back(mystring);
	}

	QVector<double> qVec = QVector<double>::fromStdVector(doubleVec);
	
	ticks << qVec;

	QVector<QString> QStringvec;
	for (int i = 0; i < stringVec.size(); i++) {
		QStringvec.append(QString::fromStdString(stringVec.at(i)));
	}


	std::vector<double> doubleYVec(scans.at(0).y.begin(), scans.at(0).y.end());

	// prepare x axis:
	if (scans.at(0).x.empty()) {
		return customPlot;
	}
	double lowerrangex = doubleVec.front();
	double upperrangex = doubleVec.back();
	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);

	customPlot->xAxis->setTicker(textTicker);
	customPlot->xAxis->setTickLabelRotation(45);
    customPlot->xAxis->setSubTicks(true);//modded to true
	customPlot->xAxis->setTickLength(0, 4);
	customPlot->xAxis->setRange(lowerrangex, upperrangex);
    customPlot->xAxis->setLabel("m/z");

	// prepare y axis:
	auto biggest = std::max_element(std::begin(doubleYVec), std::end(doubleYVec));
	customPlot->yAxis->setRange(0, *biggest);
	customPlot->yAxis->setPadding(5); // a bit more space to the left border
	customPlot->yAxis->setLabel("Intensity");
	customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

	// Add data:
    QVector<double> bar1Data;
	QVector<double> qYVec = QVector<double>::fromStdVector(doubleYVec);
	bar1Data << qYVec;
	bar1->setData(ticks, bar1Data);

return customPlot;
}

#include "moc_plotms.cpp"
