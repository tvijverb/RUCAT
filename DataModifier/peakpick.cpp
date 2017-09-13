#include "peakpick.h"

peakpick::peakpick(QObject *parent) : QObject(parent)
{

}

std::vector<int> * peakpick::peakpickTIC(QtCharts::QLineSeries * lineseries)
{
    qDebug() << "inside peakpick";
    std::vector<int>* myvec;
    return myvec;
}
