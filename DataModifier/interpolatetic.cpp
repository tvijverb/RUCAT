#include "interpolatetic.h"

interpolatetic::interpolatetic(QObject *parent)
    : QObject(parent)
{

}

QVector<QLineSeries*> interpolatetic::interpolateLineSeries(std::vector<GCData*> data)
{
    QList<QPointF> chromatogramTIC;
    std::vector<GCData*> dataOnChart;
    QList<QPointF> pointList;

    for(int i = 0; i < data.size(); i++)
    {
        if(data[i]->getLineSeriesOnChart())
        {
            dataOnChart.push_back(data.at(i));
        }
    }

    for(int i = 0; i < dataOnChart.size(); i++)
    {
        pointList += dataOnChart[i]->getScanLinePoints();
        qDebug() << pointList.size();
    }



    return this->interpolatedLineSeriesVec;
}
