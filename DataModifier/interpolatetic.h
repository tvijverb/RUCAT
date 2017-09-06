#ifndef INTERPOLATETIC_H
#define INTERPOLATETIC_H

#include <QAbstractItemModel>
#include <QTreeWidget>
#include <QDebug>
#include <iostream>
#include <fstream>

#include "DataModifier/gcdata.h"
#include "DataModifier/spline.h"

class interpolatetic : public QObject
{
    Q_OBJECT

public:
    interpolatetic(QObject *parent = nullptr);
    std::vector<double> getInterpolatePoints(std::vector<double>,int);
    bool interpolateLineSeries(std::vector<GCData*>,int);
private:

    //QVector<QLineSeries*> interpolatedLineSeriesVec;
};

#endif // INTERPOLATETIC_H
