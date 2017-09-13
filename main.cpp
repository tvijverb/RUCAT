
#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>


#include "controller.h"

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath("plugins");
    QCoreApplication::addLibraryPath("png");
    QCoreApplication::addLibraryPath("qdarkstyle");
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Thomas Vijverberg");
    QCoreApplication::setOrganizationDomain("thomas.vijverb.nl");
    QCoreApplication::setApplicationName("RUCAT - Radboud University Chromatogram Analysis Tool");

    MainWindow view;
    Controller controller(&view);
    view.setWindowTitle(QObject::tr("RUCAT Radboud University Chromatogram Analysis Tool"));
    view.show();

    return a.exec();
}
