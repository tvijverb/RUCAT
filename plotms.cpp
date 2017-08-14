#include "plotms.h"

#include <qvector.h>

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
	this->chart2 = new QChart();
	this->chartView = new ChartView(chart2);
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

QCustomPlot * plotMS::plotsingleMS(std::vector<GCData*> data, int clickedPoints_index, QCustomPlot *customPlot)
{
    // Debugging info
    qDebug() << QString("GCData length sent to plotsingMS");
    qDebug() << data.size();

    // Clear MS plot
	customPlot->clearPlottables();

	QVector<MSData> mymsdata;
	QVector<Scan> scans;

    mymsdata.append(data.at(0)->getMSData());
    MSData d = (mymsdata.at(0));
    scans.append(d.getScan(clickedPoints_index));

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

	std::vector<double> doubleVec(scans.at(0).x.begin(), scans.at(0).x.end());
	QVector<double> qVec = QVector<double>::fromStdVector(doubleVec);
	ticks << qVec;

	std::vector<std::string> stringVec;
	stringVec.reserve(doubleVec.size());
	std::transform(doubleVec.begin(),
		doubleVec.end(),
		std::back_inserter(stringVec),
		[](double d) { return std::to_string(d); }
	);
	QVector<QString> QStringvec;
	for (int i = 0; i < stringVec.size(); i++) {
		QStringvec.append(QString::fromStdString(stringVec.at(i)));
	}

	labels << QStringvec;
	std::vector<double> doubleYVec(scans.at(0).y.begin(), scans.at(0).y.end());
	std::vector<double> doubleYVec2;
	std::vector<double> doubleYVec3;

	// x2:
	QVector<double> ticks2;
	QVector<QString> labels2;

	if (data.size() > 1)
	{
		std::vector<double> doubleVec2(scans.at(1).x.begin(), scans.at(1).x.end());
		QVector<double> qVec2 = QVector<double>::fromStdVector(doubleVec2);
		ticks2 << qVec2;

		std::vector<std::string> stringVec2;
		stringVec2.reserve(doubleVec2.size());
		std::transform(doubleVec2.begin(),
			doubleVec2.end(),
			std::back_inserter(stringVec2),
			[](double d) { return std::to_string(d); }
		);
		QVector<QString> QStringvec2;
		for (int i = 0; i < stringVec2.size(); i++) {
			QStringvec2.append(QString::fromStdString(stringVec2.at(i)));
		}

		labels2 << QStringvec2;
		std::vector<double> doubleYVec2(scans.at(1).y.begin(), scans.at(1).y.end());
	}

	// x3:
	QVector<double> ticks3;
	QVector<QString> labels3;

	if (data.size() > 2)
	{
		std::vector<double> doubleVec3(scans.at(2).x.begin(), scans.at(2).x.end());
		QVector<double> qVec3 = QVector<double>::fromStdVector(doubleVec3);
		ticks3 << qVec3;

		std::vector<std::string> stringVec3;
		stringVec3.reserve(doubleVec3.size());
		std::transform(doubleVec3.begin(),
			doubleVec3.end(),
			std::back_inserter(stringVec3),
			[](double d) { return std::to_string(d); }
		);
		QVector<QString> QStringvec3;
		for (int i = 0; i < stringVec3.size(); i++) {
			QStringvec3.append(QString::fromStdString(stringVec3.at(i)));
		}

		labels3 << QStringvec3;
		std::vector<double> doubleYVec3(scans.at(2).y.begin(), scans.at(2).y.end());
	}

	// prepare x axis:
	if (scans.at(0).x.empty()) {
		return customPlot;
	}
	double lowerrangex = doubleVec.front();
	double upperrangex = doubleVec.back();
	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);

	customPlot->xAxis->setTicker(textTicker);
	customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(true);//modded to true
	customPlot->xAxis->setTickLength(0, 4);
	customPlot->xAxis->setRange(lowerrangex, upperrangex);

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
