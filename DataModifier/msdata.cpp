#include <QDebug>

#include "msdata.h"

MSData::MSData()
{

}

int MSData::getScanSize()
{
    return scans.size();
}

void MSData::addScan(Scan * myscan)
{
	this->scans.push_back(myscan);
}

void MSData::setScans(std::vector<Scan *> myscans)
{
    this->scans = myscans;
}
Scan MSData::getScan(int num)
{
    if (num >= scans.size())
    {
        qDebug() << "Incorrect scan number specified";
		qDebug() << "Requested Scan num: " << num;
		qDebug() << "We only store: " << scans.size() << "scans for this TIC curve";
        return(*scans[scans.size()-1]);
    }
    else
    {
        return *scans[num];
    }
}

std::vector<Scan*> MSData::getScans()
{
    return scans;
}

std::string MSData::getMSType()
{
	return ms_type;
}

void MSData::setMSType(std::string ms_type)
{
    this->ms_type = ms_type;
}

std::string MSData::getMSDetector()
{
	return ms_detector;
}

void MSData::setMSDetector(std::string ms_detector)
{
    this->ms_detector = ms_detector;
}

std::string MSData::getMSName()
{
	return ms_name;
}

void MSData::setMSName(std::string ms_name)
{
    this->ms_name = ms_name;
}

std::string MSData::getMSVersion()
{
	return ms_version;
}

void MSData::setMSVersion(std::string ms_version)
{
    this->ms_version = ms_version;
}

void Scan::empty()
{
	this->id = {};
	this->scan_mslvl= {};
	this->scan_peakc = {};
	this->scan_basepeakintensity = {};

	this->scan_lowmz = {};
	this->scan_highmz = {};
	this->scan_basepeakmz = {};

	this->x = {};
	this->y = {};

	this->scan_mspeaks = {};
}
