#include "controller.h"
#include <qfuturewatcher.h>


Controller::Controller(MainWindow * view)
{
    this->view = view;
    connectActions();
    initializeTreeWidget();
    view->ui->tabWidget->setCurrentIndex(0);
    view->ui->ticplot->setChart(mychart);
    view->ui->ticplot->setRubberBand( QChartView::HorizontalRubberBand );
    mychart->layout()->setContentsMargins(0,0,0,0);
    mychart->setBackgroundRoundness(0);

    QImageReader reader("png/RUCAT_TIC_BG.png");
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    QPixmap pix = QPixmap::fromImage(newImage);
    QPainter painter( &pix );
    QFont titillium = QFont("Titillium Web");
    titillium.setPointSize(20);
    painter.setFont( titillium);
    painter.drawText( QPoint(100, 100), "Welcome to RUCAT - No Data Loaded - Click Open File to start" );
    imageLabel->setPixmap(pix);
    imageLabel->adjustSize();
    view->ui->dockWidget_2->setWidget(imageLabel);
}

void Controller::connectActions()
{
	QObject::connect(view->ui->actionOpen_file, &QAction::triggered, this, &Controller::openFile);
    QObject::connect(view->ui->actionAlign_Chromatogram, &QAction::triggered, this, &Controller::actionAlign_Chromatogram);
    QObject::connect(view->ui->actionPeak_Pick_Chromatograms, &QAction::triggered, this, &Controller::peakPickSetup);
    QObject::connect(view->ui->actionInterpolate_Chromatogram, &QAction::triggered, this, &Controller::actionInterpolate_Chromatogram);
    QObject::connect(view->ui->actionEmpty_TIC_plot, &QAction::triggered, this, &Controller::actionEmpty_TIC_plot);
    QObject::connect(view->ui->actionTICCSVSelected_File, &QAction::triggered, this,&Controller::TICCSVSelected_File);
    QObject::connect(view->ui->actionTICCSVAll_Files, &QAction::triggered, this,&Controller::TICCSVALL_Files);
	QObject::connect(view->ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &Controller::on_treeWidget_itemDoubleClicked);
    QObject::connect(view->ui->ticplot, &ChartView::lineChartClicked, this, &Controller::getlineChartClicked);
    QObject::connect(&futureWatcher, SIGNAL(progressRangeChanged(int,int)), progressbar, SLOT(setRange(int,int)));
    QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)),progressbar, SLOT(setValue(int)));
    QObject::connect(&futureWatcher, SIGNAL(finished()),progressbar, SLOT(closethis()));
    QObject::connect(&futureWatcher,&QFutureWatcher<GCData *>::finished,this,&Controller::futureReady);
    QObject::connect(advancedDialog,&QDialog::finished,this,&Controller::peakPick);
    QObject::connect(alignmentdialog,&QDialog::finished,this,&Controller::alignment);
}

void Controller::alignment(int status)
{
    if(status)
    {

    }
}

void Controller::actionAlign_Chromatogram()
{
    bool dataonchart = false;
    for(int i = 0; i < data.size(); i++)
    {
        if(data.at(i)->getLineSeriesOnChart())
        {
            dataonchart = true;
        }
    }
    if(dataonchart)
    {
        alignmentdialog->show();
    }
}

void Controller::peakPickSetup()
{
    bool dataonchart = false;
    for(int i = 0; i < data.size(); i++)
    {
        if(data.at(i)->getLineSeriesOnChart())
        {
            dataonchart = true;
        }
    }
    if(dataonchart)
    {
        advancedDialog->show();
        advancedDialog->setWindowTitle("Peak Picking Settings");
        advancedDialog->setSlidersRange(1,50,1,50,1,50);
        advancedDialog->setSlidersvalue(5,5,15);
    }
}

void Controller::peakPick(int status)
{
    if(status)
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data.at(i)->getLineSeriesOnChart())
            {
                std::vector<int> peakList = peakpickdata->peakpickTIC(data.at(i)->getCurrentLineSeries(),advancedDialog->getSlidersvalue());
                view->ui->ticplot->setGData(data);
                view->ui->ticplot->drawPeaks(data.at(i),peakList);
            }
        }
    }
}

void Controller::actionEmpty_TIC_plot() // Delete lineseries on mychart
{
    mytic.clearLineChart(mychart,data);
    view->ui->ticplot->resize(view->ui->ticplot->size() + QSize(1, 1));
    view->ui->ticplot->resize(view->ui->ticplot->size() - QSize(1, 1));
}

void Controller::actionInterpolate_Chromatogram() // Delete lineseries on mychart
{
    progressbar->setTitle("Interpolating Data");
    progressbar->show();
    progressbar->setZero();
    bool succes = false;
    succes = interpolation->interpolateLineSeries(data,dataFreq,progressbar);
    if(succes == false)
    {
        for(int i = 0; i < data.size(); i++)
        {
            if(data.at(i)->getLineSeriesOnChart())
            {
                mytic.removeSeriesLineChart(mychart,data.at(i));
                mytic.plotsingleTIC(data.at(i),data,mychart);
            }
        }
    }
	progressbar->closethis();
    view->ui->ticplot->resize(view->ui->ticplot->size() + QSize(1, 1));
    view->ui->ticplot->resize(view->ui->ticplot->size() - QSize(1, 1));
}

void Controller::TICCSVSelected_File() // Export selected file to executing dir
{
    csvexporter->export_single_csv(view->ui->treeWidget,data);
}

void Controller::TICCSVALL_Files()  //Export all tic files to csv in executing dir
{
    csvexporter->TICCSVALL_Files(view->ui->treeWidget,data);
}

void Controller::on_rangeChanged()
{
    qDebug()<< "onrangechanged";
}

void Controller::getlineChartClicked(QPointF qpoint)
{
    // Plotting MSData bargraph after doubleclick on ticplot - see connect statement
    // Emitted from chartview.cpp
    if (!mytic.getLineChartIsInit())
    {
        qDebug() << "LineChart is not initialized";
        return;
    }
	// Get closest point from click to chartView
    QList<QAbstractSeries *> myseries = mychart->series();
	if (myseries.size() == 0)
	{
		qDebug() << "No data in plot";
		return;
	}

    int index = mytic.getClickedPointIndex(myseries[0],qpoint);

	// DoubleClick on TreeWidget adds barChart to graphicsView_2
	//QRect graphics_2ViewRect = view->ui->graphicsView_2->frameRect();

    QCustomPlot *customPlot = view->ui->qcWidget;
    customPlot = myMS.plotsingleMS(data, index,customPlot);
    view->ui->qcWidget->replot();
}

void Controller::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	// Generating generic variables needed for plotting

    for(int i = 0; i < data.size(); i++)
    {
        // Find selected string in dataset
        if(QString::fromStdString(data[i]->getName()) == item->text(column) )
        {
            mychart = mytic.plotsingleTIC(data.at(i),data,mychart);
            view->ui->ticplot->resize(view->ui->ticplot->size() + QSize(1, 1));
            view->ui->ticplot->resize(view->ui->ticplot->size() - QSize(1, 1));
        }
    }
}

void Controller::initializeTreeWidget()
{
    // Qt treeWidget for displaying GC-MS files
    QTreeWidget * tree = view->ui->treeWidget;
    treetab.initializeTreeView(tree);
}

std::vector<GCData*> Controller::getGCData() // Probably not needed
{
	return data;
}

void Controller::treeViewUpdate() // Can be removed
{
}

void Controller::newDataLoaded(std::vector<GCData*> data)
{
    // Runs after openFile was succesfull
    GCData * lastdata = data.back();
    std::string fileName;
    fileName = lastdata->getName();

    mychart = mytic.plotsingleTIC(lastdata,data,mychart);
    treetab.removeEmptyTop(view->ui->treeWidget);

    treetab.topAdd(view->ui->treeWidget,QString::fromStdString(fileName),data.size(), data.back());
    view->ui->treeWidget->setRootIndex(QModelIndex());
    mytic.setLineChartIsInit(true);
}

void Controller::futureReady()
{
    // Multithreaded implementation of importdata.cpp
    // Triggered when multithreaded function is ready - see connect statement
    QFuture<GCData*> Qfuture = futureWatcher.future();
    qDebug() << QString("futureReady");
    //futureWatcher.
    for(int i = 0; i < Qfuture.resultCount();i++)
    {
        data.push_back(futureWatcher.resultAt(i));
        newDataLoaded(data);
    }
    view->ui->dockWidget_2->setWidget(view->ui->dockWidgetContents_3);
}

void Controller::openFile()
{
    // DropDown 'Open File' clicked
    // Open .mzXML file(s)
    QStringList fileList = QFileDialog::getOpenFileNames(this,
                                                    tr("Open File"),
                                                    "C:\\",
                                                    "mzXML files (*.mzXML)");
    // Import mzData from file to variable
    if(fileList.size() > 0){
        progressbar->setTitle("Importing Data");
        progressbar->show();
        progressbar->setZero();
        futureWatcher.setFuture(QtConcurrent::mapped(fileList,importmzData));
    }
	view->ui->tabWidget->setCurrentIndex(1);
}
#include "moc_controller.cpp"
