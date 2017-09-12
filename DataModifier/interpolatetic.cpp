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

    return interpolatePoints;
}

bool interpolatetic::myfn(int i, int j) { return i<j; }

Scan * interpolatetic::scanInterpolate(Scan * newScan, std::vector<double> ScanRT,MSData * mymsdata, double pointToInterPolate)
{
    std::vector<double> upper;
    std::vector<double> lower;
    std::vector<float> x;

    for(int i = 0; i < ScanRT.size(); i++)
    {
        if((ScanRT[i] - pointToInterPolate) >= 0)
            upper.push_back(ScanRT[i] - pointToInterPolate);
        else
            lower.push_back(ScanRT[i] - pointToInterPolate);
    }

    int lowend = lower.size()-1;
    int highend = lower.size();

    if(lower.size() == 0 || upper.size() == 0)
    {
        qDebug() << "interpolatetic/scanInterpolate TIC out of bounds";
        return newScan;
    }


	std::vector<Scan*> durr = mymsdata->getScans();

    Scan lowerScan = mymsdata->getScan(lowend);
    Scan higherScan = mymsdata->getScan(highend);

    std::vector<float> lowScanX = lowerScan.x;
    std::vector<float> lowScanY = lowerScan.y;
    std::vector<float> highScanX = higherScan.x;
    std::vector<float> highScanY = higherScan.y;

    if(lowScanX.size() != lowScanY.size() || highScanX.size() != highScanY.size())
    {
        qDebug() << "interpolatetic/scanInterpolate Scan out of bounds";
        return newScan;
    }

    lowScanX.insert(lowScanX.end(), highScanX.begin(), highScanX.end());
    lowScanY.insert(lowScanY.end(), highScanY.begin(), highScanY.end());

    std::vector<double> y(lowScanX.size());

    // Sorting algorithm to have x-points in increasing order
    std::size_t n(0);
    std::generate(std::begin(y), std::end(y), [&]{ return n++; });

    std::sort(  std::begin(y),
                std::end(y),
                [&](int i1, int i2) { return ScanRT[i1] < ScanRT[i2]; } );


    // Index positions of ordering sequence
    for (auto v : y)
    {
        x.push_back(lowScanY.at(v));
    }
    std::sort (lowScanX.begin(),lowScanX.end());

    for(int i = lowScanX.size() - 1; i >= 0; i--)
    {
        if(i != 0)
        {
            if(abs(lowScanX[i] - lowScanX[i-1]) < (float)0.3)
            {
                double xx = abs(lower.back()) + abs(upper.front());
                double lowerfrac = abs(lower.back()) / xx;


                x.at(i - 1) = (x[i -1 ] * lowerfrac) + (x[i] * (1-lowerfrac));
                lowScanX.erase( lowScanX.begin() + i );
                x.erase( x.begin() + i );
            }
        }
    }

    newScan->x = lowScanX;
    newScan->y = x;

   return newScan;
}

bool interpolatetic::interpolateLineSeries(std::vector<GCData*> &data,int dataFrequency, Dialog* progressbar)
{
	qApp->processEvents();
    QList<QPointF> chromatogramTIC;
    QList<QPointF> pointList;
    int j = 0;

    if(data.size() == 0) // Abort if we have no data loaded
        return true;

    for(int i = 0; i < data.size(); i++)
    {
        if(data[i]->getLineSeriesOnChart())
        {
            j++;
        }
    }

    progressbar->setRange(0,j);
    j = 0;

    // Add interpolation points to currentLinePoints
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i]->getLineSeriesOnChart())
        {
            std::string name = data[i]->getName();
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

            // Check interpolation points bounds
            if(pointsToInterpolate[0] < ScanRT[0] || pointsToInterpolate.back() > ScanRT.back())
            {
                qDebug() << "interpolatetic, pointsToInterpolate out of bounds.";
                return true;
            }

            // MSData appending and spline y point calculation
            MSData * mymsdata = data[i]->getMSData();
            std::vector<Scan*> myscans = mymsdata->getScans();
			for (int i = 0; i < pointsToInterpolate.size(); i++)
			{
                Scan* newScan = new Scan();
				interpolateTIC.push_back(s(pointsToInterpolate[i]));
                myscans.push_back(scanInterpolate(newScan,ScanRT,mymsdata,pointsToInterpolate[i]));                          // WE LEAVE THE INTERPOLATED MSDATA EMPTY FOR NOW
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

            // Set new MSData and update currentLinePoints
            mymsdata->setScans(sortscans);
            data[i]->setMSData(mymsdata);
            std::sort (ScanRT.begin(),ScanRT.end());
            data[i]->setCurrentLinePoints(ScanRT, x);
            j++;
            progressbar->setValue(j);
            qApp->processEvents();
        }
    }

    progressbar->closethis();
    if(data.size() == 0) // Abort if no data is on linechart
        return true;
    return false;
}

#include "moc_interpolatetic.cpp"
