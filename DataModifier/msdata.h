#ifndef MSDATA_H
#define MSDATA_H

#include <vector>

// SCAN struct, stores MSinformation per scan (Each RT has one scan)
struct Scan
{
	int id;
	int scan_mslvl;
	int scan_peakc;
	int scan_basepeakintensity;

	double scan_lowmz;
	double scan_highmz;
	double scan_basepeakmz;

	std::vector<float> x;
	std::vector<float> y;

	std::vector<float> binBounds;
	std::vector<std::string> binNames;
	std::vector<int> binCount;

	std::string scan_mspeaks;
	void empty();
};

// MSData class, stores MSinformation from GC-MS file
class MSData
{

public:
    MSData();

    int getScanSize();

    std::vector<Scan*> getScans();
    Scan getScan(int num = 0);
    void addScan(Scan * myscan);

	std::string getMSType();
	void setMSType(std::string ms_type);

	std::string getMSDetector();
	void setMSDetector(std::string ms_detector);

	std::string getMSName();
	void setMSName(std::string ms_name);

	std::string getMSVersion();
	void setMSVersion(std::string ms_version);

private:
    std::vector<Scan*> scans;

	std::string ms_type;
	std::string ms_detector;
	std::string ms_name;
	std::string ms_version;
};

#endif // MSDATA_H
