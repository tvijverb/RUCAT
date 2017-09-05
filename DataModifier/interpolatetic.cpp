#include "interpolatetic.h"

interpolatetic::interpolatetic(QObject *parent)
    : QObject(parent)
{

}

std::vector<double> interpolatetic::getInterpolatePoints(std::vector<double> scanRT,int dataFrequency)
{
    std::vector<double> interpolatePoints;

    return interpolatePoints;
}

bool interpolatetic::interpolateLineSeries(std::vector<GCData*> data,int dataFrequency)
{
    QList<QPointF> chromatogramTIC;
    std::vector<GCData*> dataOnChart;
    QList<QPointF> pointList;

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
    }

    //qDebug() << "pointList size:" << pointList.size();

    return false;
}
