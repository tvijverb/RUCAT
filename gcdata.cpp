#include "gcdata.h"

GCData::GCData(QObject *parent) : QObject(parent)
{

}

void GCData::setMSdata(MSData * mymsdata)
{
	this->msdata = mymsdata;
}

bool GCData::getLineSeriesOnChart()
{
    return onLineChart;
}

void GCData::setLineSeriesOnChart(bool chartstate)
{
    this->onLineChart = chartstate;
}

QByteArray GCData::gUncompress(std::string const& compressed_string)
{
    const QByteArray data(compressed_string.c_str(), compressed_string.length());
    if (data.size() <= 4) {
        qWarning("gUncompress: Input data is truncated");
        return QByteArray();
    }

    QByteArray result;

    int ret;
    z_stream strm;
    static const int CHUNK_SIZE = 1024;
    char out[CHUNK_SIZE];

    /* allocate inflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = data.size();
    strm.next_in = (Bytef*)(data.data());

    ret = inflateInit2(&strm, 15 +  32); // gzip decoding
    if (ret != Z_OK)
        return QByteArray();

    // run inflate()
    do {
        strm.avail_out = CHUNK_SIZE;
        strm.next_out = (Bytef*)(out);

        ret = inflate(&strm, Z_NO_FLUSH);
        Q_ASSERT(ret != Z_STREAM_ERROR);  // state not clobbered

        switch (ret) {
        case Z_NEED_DICT:
            ret = Z_DATA_ERROR;     // and fall through
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
            (void)inflateEnd(&strm);
            return QByteArray();
        }

        result.append(out, CHUNK_SIZE - strm.avail_out);
    } while (strm.avail_out == 0);

    // clean up and return
    inflateEnd(&strm);
    return result;
}

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


inline bool GCData::is_base64(unsigned char c) 
{
  return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string GCData::base64_decode(std::string const& encoded_string) 
{
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

std::string GCData::getName()
{
	return fileName;
}

void GCData::setName(std::string fileName)
{
	this->fileName = fileName;
}

std::string GCData::getXML()
{
	return xmlschema_location;
}

void GCData::setXML(std::string xmlSchema)
{
	this->xmlschema_location = xmlSchema;
}

std::string GCData::getStartTime()
{
	return startTime;
}

void GCData::setStartTime(std::string startTime)
{
	int sz = startTime.size();
	startTime.erase(0, 2);
	startTime.erase(sz - 3, 1);
	this->startTime = startTime;
}

std::string GCData::getEndTime()
{
	return endTime;
}

void GCData::setEndTime(std::string endTime)
{
    int sz = endTime.size();
    endTime.erase(0, 2);
    endTime.erase(sz - 3, 1);
	this->endTime = endTime;
}

std::string GCData::getFileType()
{
	return fileType;
}

void GCData::setFileType(std::string fileType)
{
	this->fileType = fileType;
}

std::string GCData::getSHA()
{
	return sha1;
}

void GCData::setSHA(std::string sha1)
{
	this->sha1 = sha1;
}

std::string GCData::getManufacturer()
{
	return manufacturer;
}

void GCData::setManufacturer(std::string manufacturer)
{
	this->manufacturer = manufacturer;
}

std::string GCData::getModel()
{
	return model;
}

void GCData::setModel(std::string model)
{
	this->model = model;
}

std::string GCData::getIonisation()
{
	return ionisation;
}

void GCData::setIonisation(std::string ionisation)
{
	this->ionisation = ionisation;
}

MSData GCData::getMSData()
{
	return *msdata;
}

void GCData::setMSData(MSData * msdata)
{
	this->msdata = msdata;
}

std::vector<int> GCData::getScanRT_i()
{
	return scan_rt_i;
}

void GCData::setScanRT_i(std::vector<int> scan_rt_i)
{
	this->scan_rt_i = scan_rt_i;
}

void GCData::addScanRT_i(int scan_rt_i)
{
    this->scan_rt_i.push_back(scan_rt_i);
}

std::vector<std::string> GCData::getScanRT_s()
{
	return scan_rt_s;
}

void GCData::setScanRT_s(std::vector<std::string> scan_rt_s)
{
    int sz = scan_rt_s.back().size();
    scan_rt_s.back().erase(0,2);
    scan_rt_s.back().erase(sz-3,1);
	this->scan_rt_s = scan_rt_s;
}

void GCData::addScanRT_s(std::string scan_rt_s)
{
    int sz = scan_rt_s.size();
    scan_rt_s.erase(0,2);
    scan_rt_s.erase(sz-3,1);
    this->scan_rt_s.push_back(scan_rt_s);
}

std::vector<double> GCData::getScanRT_d()
{
	return scan_rt_d;
}

void GCData::setScanRT_d(std::vector<double> scan_rt_d)
{
	this->scan_rt_d = scan_rt_d;
}

void GCData::addScanRT_d(double scan_rt_d)
{
    this->scan_rt_d.push_back(scan_rt_d);
}

std::vector<int> GCData::getScanTIC()
{
    return scan_tic;
}

void GCData::setScanTIC(std::vector<int> scan_tic)
{
    this->scan_tic = scan_tic;
}

void GCData::ScanAddTIC(int tic)
{
	this->scan_tic.push_back(tic);
}

void GCData::setLinePoints(std::vector<int> ScanRT_i, std::vector<int> scan_tic)
{
    //QLineSeries *series = new QLineSeries();
    QDateTime momentInTime;
    int currtime;
    int starttime;
    int endtime;
    int min;
    int s;
    int ms;

    for (int i = 0; i < ScanRT_i.size(); i++) {
        currtime = ScanRT_i.at(i);
        min = floor(currtime/60000);
        s = floor((currtime-min*60000)/1000);
        ms = (currtime-min*60000-s*1000);
        QTime time(0,min,s,ms);
        momentInTime.setTime(time);
        QPointF p(momentInTime.toMSecsSinceEpoch(),scan_tic.at(i));
        series->append(p);
        this->scan_tic_qp.append(p);
    }
}

QList<QPointF> GCData::getScanLinePoints()
{
    return scan_tic_qp;
}

QLineSeries* GCData::getScanLineSeries()
{
    return series;
}