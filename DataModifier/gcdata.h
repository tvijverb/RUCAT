#ifndef GCDATA_H
#define GCDATA_H

#include <vector>
#include <string>

#include <QObject>
#include <QtCharts/QLineSeries>
#include <QDateTime>
#include <QtZlib/zlib.h>
#include <QDebug>

#include "UI/chart.h"
#include "UI/chartview.h"
#include "msdata.h"

//GCData class, 
class GCData : public QObject
{
    Q_OBJECT

public: // Functions
    explicit GCData(QObject *parent = 0);

    int getMaxTicValue();
    QTime getMaxTimeValue();

	QByteArray gUncompress(std::string const& compressed_string);

    int numDigits(int32_t x);
	static inline bool is_base64(unsigned char c);

	std::string base64_decode(std::string const& encoded_string);

	void setMSdata(MSData * mymsdata);

    bool getLineSeriesOnChart();
    void setLineSeriesOnChart(bool chartstate);

    bool hasCurrentSeriesOnChart();
    void setCurrentSeriesOnChart(bool);

    std::string getName();
    void setName(std::string fileName);

	std::string getXML();
	void setXML(std::string xmlSchema);

	std::string getStartTime();
	void setStartTime(std::string startTime);

	std::string getEndTime();
	void setEndTime(std::string endTime);

	std::string getFileType();
	void setFileType(std::string fileType);

	std::string getSHA();
	void setSHA(std::string sha1);

	std::string getManufacturer();
	void setManufacturer(std::string manufacturer);

	std::string getModel();
	void setModel(std::string model);

	std::string getIonisation();
	void setIonisation(std::string ionisation);

	MSData getMSData();
	void setMSData(MSData * msdata);

    int getScan_n();

	std::vector<int> getScanRT_i();
	void setScanRT_i(std::vector<int>);
    void addScanRT_i(int);

	std::vector<std::string> getScanRT_s();
	void setScanRT_s(std::vector<std::string>);
    void addScanRT_s(std::string);

	std::vector<double> getScanRT_d();
	void setScanRT_d(std::vector<double>);
    void addScanRT_d(double);

	std::vector<int> getScanTIC();
    void setScanTIC(std::vector<int>);
	void ScanAddTIC(int);

    std::vector<double> getScanTIC_d();
    void setScanTIC_d(std::vector<double>);
    void ScanAddTIC_d(double);

    void setLinePoints(std::vector<int>,std::vector<int>);
    QList<QPointF> getScanLinePoints();

    QLineSeries* getScanLineSeries();
    QLineSeries* getCurrentLineSeries();
    QLineSeries* getPreviousSeries();
    void setCurrentLinePoints(std::vector<double>,std::vector<double>);
    void setCurrentLineSeries(QLineSeries*);
	
	void setXAxis(QDateTimeAxis *);
	QDateTimeAxis* XAxis();
	
	void setYAxis(QValueAxis *);
	QValueAxis* YAxis();

    bool hasUpdateCurrLineSeries();
    void setHasUpdateCurrLineSeries(bool maybe);

private: // Functions

signals:
    void sendQLine(QLineSeries * series);

private: // Vars
	MSData * msdata;

    bool onLineChart = false;
    bool hasCurrentSeriesData = false;
    bool hasUpdateCurrentLineSeries = false;

    std::string xmlschema_location;
    std::string ms_scancount;
    std::string startTime;
    std::string endTime;
    std::string fileName;
    std::string fileType;
    std::string sha1;
    std::string manufacturer;
    std::string model;
    std::string ionisation;

    std::vector<std::string> scan_rt_s;
    std::vector<double> scan_rt_d;
    std::vector<int> scan_rt_i;
    std::vector<int> scan_tic;
    std::vector<double> scan_tic_d;
    QList<QPointF> scan_tic_qp;
    QList<QPointF> scan_tic_current_qp;
    QLineSeries* series = new QLineSeries();
    QLineSeries* currentSeries = new QLineSeries();
    QLineSeries* previousSeries = new QLineSeries();
	int maxTicValue = 0;
    QTime maxTimeValue;
	QDateTimeAxis * axisX = new QDateTimeAxis();
    QValueAxis * axisY = new QValueAxis();

public slots:
};

#endif // GCDATA_H
