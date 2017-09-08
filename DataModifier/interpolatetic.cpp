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

bool interpolatetic::interpolateLineSeries(std::vector<GCData*> &data,int dataFrequency)
{
    QList<QPointF> chromatogramTIC;
    QList<QPointF> pointList;

    if(data.size() == 0) // Abort if we have no data loaded
        return true;

    // Add interpolation points to currentLinePoints
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i]->getLineSeriesOnChart())
        {
            // Spline fitting
			tk::spline s;
            std::vector<double> interpolateTIC;
            std::vector<double> ScanRT = data[i]->getScanRT_d();
            std::vector<double> TIC = data[i]->getScanTIC_d();
            std::vector<double> x;
            std::vector<Scan*> sortscans;

			s.set_points(data[i]->getScanRT_d(), data[i]->getScanTIC_d());

            // Calculate Interpolation points
			std::vector<double> pointsToInterpolate = getInterpolatePoints(data[i]->getScanRT_d(), dataFrequency);

            // MSData appending and spline y point calculation
            MSData * mymsdata = data[i]->getMSData();
            std::vector<Scan*> myscans = mymsdata->getScans();
			for (int i = 0; i < pointsToInterpolate.size(); i++)
			{
				interpolateTIC.push_back(s(pointsToInterpolate[i]));
                myscans.push_back(new Scan());                          // WE LEAVE THE INTERPOLATED MSDATA EMPTY FOR NOW
			}

			ScanRT.insert(ScanRT.end(), pointsToInterpolate.begin(), pointsToInterpolate.end());
			TIC.insert(TIC.end(), interpolateTIC.begin(), interpolateTIC.end());

            std::vector<double> y(ScanRT.size());

            // Sorting algorithm to have x-points in increasing order
            std::size_t n(0);
            std::generate(std::begin(y), std::end(y), [&]{ return n++; });

            std::sort(  std::begin(y),
                        std::end(y),
                        [&](int i1, int i2) { return ScanRT[i1] < ScanRT[i2]; } );


            // Index positions of ordering sequence
            for (auto v : y)
            {
                x.push_back(TIC.at(v));
                sortscans.push_back(myscans.at(v));
            }


            qDebug() << "I go";

            // Set new MSData and update currentLinePoints
            mymsdata->setScans(sortscans);
            data[i]->setMSData(mymsdata);
            qDebug() << "Everywhere";
            std::sort (ScanRT.begin(),ScanRT.end());
            qDebug() << "Everywhere" << ScanRT.size() << x.size() << sortscans.size();
            data[i]->setCurrentLinePoints(ScanRT, x);



        }
    }

    if(data.size() == 0) // Abort if no data is on linechart
        return true;
    return false;
}
