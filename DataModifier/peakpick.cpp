#include "peakpick.h"

peakpick::peakpick(QObject *parent) : QObject(parent)
{

}

std::vector<int> * peakpick::peakpickTIC(QtCharts::QLineSeries * lineseries, std::vector<int> sliderValues)
{
    double sum;
    double mean;
    double isum;
    double imean;
    int lag = sliderValues[0];
    double threshold = double(sliderValues[1])/double(10);
    double cutoff = double(sliderValues[2])/double(10);

    std::vector<int>* myvec;

    QList<QPointF> pointList = lineseries->points();
    std::vector<double> x(pointList.size(),0.0);
    std::vector<double> upper(pointList.size(),0.0);
    std::vector<double> mystd(pointList.size(),0.0);

    sum = std::accumulate(pointList.begin(), pointList.end(), 0.0);
    mean = sum / pointList.size();

    std::vector<double> diff(pointList.size());
    std::transform(pointList.begin(), pointList.end(), diff.begin(), [mean](double x) { return x - mean; });
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / pointList.size());

    for(int i = (1+lag); i < (pointList.size()-lag); i++)
    {
        isum = std::accumulate(pointList.at(i-lag), pointList.at(i+lag), 0.0);
        imean = sum / pointList.size();
        mystd.at(i) = pointList[i].y() - imean;
    }


    //pointList.
    return myvec;
}
