#include "interpolatetic.h"

interpolatetic::interpolatetic(QObject *parent)
    : QObject(parent)
{

}

std::vector<double> interpolatetic::getInterpolatePoints(std::vector<double> scanRT,int dataFrequency)
{
    std::vector<double> interpolatePoints;
    double front = scanRT.front();
    double back = scanRT.back();
    double length = floor(back - front);
    int numPoints = floor(length * dataFrequency);
    double stepSize = 1 / (double)dataFrequency;
    for(int i = 0; i < numPoints; i++)
    {
        double interPolationPoint = front + stepSize * i;
        if (std::binary_search(scanRT.begin(), scanRT.end(), interPolationPoint) != 1)
            interpolatePoints.push_back(interPolationPoint);
    }


    qDebug() << interpolatePoints.front() << interpolatePoints.back() << interpolatePoints.size();

    return interpolatePoints;
}

bool interpolatetic::interpolateLineSeries(std::vector<GCData*> data,int dataFrequency)
{
    QList<QPointF> chromatogramTIC;
    QList<QPointF> pointList;
    std::vector<GCData*> dataOnChart;


    if(data.size() == 0) // Abort if we have no data loaded
        return true;

    for(int i = 0; i < data.size(); i++)
    {
        if(data[i]->getLineSeriesOnChart())
        {
            dataOnChart.push_back(data.at(i));
        }
    }

    if(dataOnChart.size() == 0) // Abort if no data is on linechart
        return true;

    for(int i = 0; i < dataOnChart.size(); i++)
    {
        tk::spline s;
        s.set_points(dataOnChart[i]->getScanRT_d(),dataOnChart[i]->getScanTIC_d());
        std::vector<double> pointsToInterpolate = getInterpolatePoints(dataOnChart[i]->getScanRT_d(),dataFrequency);
        std::vector<double> interpolateTIC;
        std::vector<double> ScanRT = dataOnChart[i]->getScanRT_d();
        std::vector<double> TIC = dataOnChart[i]->getScanTIC_d();
        ScanRT.insert(ScanRT.end(), pointsToInterpolate.begin(), pointsToInterpolate.end() );
        TIC.insert(TIC.end(), interpolateTIC.begin(), interpolateTIC.end() );

        for(int i = 0; i < pointsToInterpolate.size(); i++)
        {
            TIC.push_back(s(pointsToInterpolate[i]));
        }
        dataOnChart.at(i)->setCurrentLinePoints(ScanRT,TIC);
    }
    return false;
}
