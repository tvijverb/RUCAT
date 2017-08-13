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

QCustomPlot * plotMS::plotsingleMS(std::vector<GCData*> data, std::vector<QPointF> clickedPoints, std::vector<int> clickedPoints_index, QCustomPlot *customPlot)
{
    // Debugging info
    qDebug() << QString("GCData length sent to plotsingMS");
    qDebug() << data.size();

    // Clear MS plot
	customPlot->clearPlottables();

	QVector<MSData> mymsdata;
	QVector<Scan> scans;

	for (int datalen = 0; datalen < data.size(); datalen++) {
		// Only take chromatogram `1  for now
		
		mymsdata.append(data.at(datalen)->getMSData());
		MSData d = (mymsdata.at(datalen));
		scans.append(d.getScan(clickedPoints_index.at(datalen)));

	}

	//demoName = "Bar Chart Demo";
	// set dark background gradient:
    //QLinearGradient gradient(0, 0, 0, 400);
    //gradient.setColorAt(0, QColor(90, 90, 90));
    //gradient.setColorAt(0.38, QColor(105, 105, 105));
    //gradient.setColorAt(1, QColor(70, 70, 70));
    //customPlot->setBackground(QBrush(gradient));

	// create empty bar chart objects:
	QCPBars *bar1 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	QCPBars *bar2 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	QCPBars *bar3 = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	bar1->setAntialiased(false); // gives more crisp, pixel aligned bar borders
	bar2->setAntialiased(false);
	bar3->setAntialiased(false);
	//bar1->setStackingGap(1);
	//bar2->setStackingGap(1);
	//bar3->setStackingGap(1);
	// set names and colors:
	bar3->setName("bar3 fuels");
	bar3->setPen(QPen(QColor(111, 9, 176).lighter(170)));
	bar3->setBrush(QColor(111, 9, 176));
	bar2->setName("bar2");
	bar2->setPen(QPen(QColor(250, 170, 20).lighter(150)));
	bar2->setBrush(QColor(250, 170, 20));
	bar1->setName("bar1erative");
	bar1->setPen(QPen(QColor(0, 168, 140).lighter(130)));
	bar1->setBrush(QColor(0, 168, 140));
	// stack bars on top of each other:
	//bar2->moveAbove(bar3);
	//bar1->moveAbove(bar2);

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
	textTicker->addTicks(ticks2, labels2);
	textTicker->addTicks(ticks3, labels3);

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
	QVector<double> bar3Data, bar2Data, bar1Data;
	QVector<double> qYVec = QVector<double>::fromStdVector(doubleYVec);
	bar1Data << qYVec;
	bar1->setData(ticks, bar1Data);

	if (data.size() > 1) {
		QVector<double> qYVec2 = QVector<double>::fromStdVector(doubleYVec2);
		bar2Data << qYVec2;
		bar2->setData(ticks, bar2Data);
	}
	if (data.size() > 2) {
		QVector<double> qYVec3 = QVector<double>::fromStdVector(doubleYVec3);
		bar3Data << qYVec3;
		bar3->setData(ticks3, bar3Data);
	}
return customPlot;
}
