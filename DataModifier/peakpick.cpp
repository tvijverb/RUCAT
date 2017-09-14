#include "peakpick.h"

peakpick::peakpick(QObject *parent) : QObject(parent)
{

}

bool myfunction (int i, int j) {
  if(i == 0)
      return 0;

  return (i==j);
}

void clean_adjacent_x (std::vector<int> &x, std::vector<double> &TIC)
{
    auto i1 = std::adjacent_find(x.begin(), x.end(),myfunction);

    while(i1 != x.end())
    {
        int startElement = int(std::distance(x.begin(), i1));
        int i = 0;
        auto i2 = std::adjacent_find(x.begin() + startElement, x.end(),myfunction);

        while(std::distance(x.begin()+startElement+i, i2) == 0)
        {
            i++;
           i2 = std::adjacent_find(x.begin() + startElement + i, x.end(),myfunction);
        }
        int endElement = startElement+i;

        //qDebug() << "BeginElement & endElement=" << startElement << endElement;
        auto biggest = std::max_element(begin (TIC) + startElement, begin (TIC) + endElement);
        int biggestIndex = int(std::distance(std::begin(TIC) + startElement, biggest));

        i1 = std::adjacent_find(x.begin()+endElement, x.end(),myfunction);

        for (auto it = begin (x) + startElement; it != begin (x) + endElement + 1; ++it)
        {
            if(std::distance(begin (x) + startElement, it) == biggestIndex)
                *it = 1;
            else
                *it = 0;
        }
    }
}

std::vector<int> peakpick::peakpickTIC(QtCharts::QLineSeries * lineseries, std::vector<int> sliderValues)
{
    double sum;
    double mean;
    double isum;
    double imean;
    int lag = sliderValues[0];
    double threshold = double(sliderValues[1])/double(10);
    double cutoff = double(sliderValues[2])/double(10);

    QList<QPointF> pointList = lineseries->points();
    std::vector<double> Y;
    QList<QPointF>::iterator i;
    for (i = pointList.begin(); i != pointList.end(); ++i)
        Y.push_back(double(i.i->t().y()));

    std::vector<int> x(pointList.size(),0.0);
    std::vector<double> upper(pointList.size(),0.0);
    std::vector<double> mystd(pointList.size(),0.0);

    sum = std::accumulate(Y.begin(), Y.end(), 0.0);
    mean = sum / Y.size();

    std::vector<double> diff(Y.size());
    std::transform(Y.begin(), Y.end(), diff.begin(), [mean](double x) { return x - mean; });
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    double tstdev = std::sqrt(sq_sum / Y.size());


    for(int i = (1+lag); i < (pointList.size()-lag); i++)
    {
        isum = std::accumulate(Y.begin()+i-lag, Y.begin()+i+lag, 0.0);
        imean = isum / Y.size();
        mystd.at(i) = Y.at(i) - imean;

        std::vector<double> diff(2*lag+1);
        std::transform(Y.begin()+i-lag, Y.begin()+i+lag, diff.begin(), [mean](double x) { return x - mean; });
        double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
        double stdev = std::sqrt(sq_sum / diff.size());

        upper.at(i) = imean + threshold * stdev;
        if(Y.at(i) > upper.at(i) && mystd.at(i) > tstdev*cutoff)
        {
            x.at(i) = 1;
        }
    }
    clean_adjacent_x(x,Y);
    return x;
}
