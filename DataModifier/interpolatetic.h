#ifndef INTERPOLATETIC_H
#define INTERPOLATETIC_H

#include <QAbstractItemModel>
#include <QTreeWidget>
#include <QDebug>
#include <iostream>
#include <fstream>

#include "DataModifier\gcdata.h"

class interpolatetic : public QObject
{
    Q_OBJECT

public:
    interpolatetic(QObject *parent = nullptr);

    QVector<QLineSeries*> interpolateLineSeries(std::vector<GCData*>);
private:
    QVector<QLineSeries*> interpolatedLineSeriesVec;
};

#endif // INTERPOLATETIC_H
