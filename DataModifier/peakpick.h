#ifndef PEAKPICK_H
#define PEAKPICK_H

#include <QLineSeries>
#include <QDebug>

class peakpick: public QObject
{
    Q_OBJECT
public:
    explicit peakpick( QObject *parent = 0);
    std::vector<int> * peakpickTIC(QtCharts::QLineSeries*);
};

#endif // PEAKPICK_H
