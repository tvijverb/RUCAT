#ifndef INTERPOLATETIC_H
#define INTERPOLATETIC_H

#include <QApplication>
#include <QAbstractItemModel>
#include <QTreeWidget>
#include <QDebug>
#include <iostream>
#include <fstream>

#include "DataModifier\gcdata.h"
#include "DataModifier\spline.h"
#include "UI/dialog.h"

class interpolatetic : public QObject
{
    Q_OBJECT

public:
    interpolatetic(QObject *parent = nullptr);
    std::vector<double> getInterpolatePoints(std::vector<double>,int);
    bool interpolateLineSeries(std::vector<GCData*>&,int,Dialog*);
private:
    Scan * scanInterpolate(Scan *, std::vector<double> ,MSData *, double);
    bool myfn(int i, int j);
    //QVector<QLineSeries*> interpolatedLineSeriesVec;
};

#endif // INTERPOLATETIC_H
