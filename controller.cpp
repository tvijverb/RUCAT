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
    //mychartView->
}

void Controller::connectActions()
{
	QObject::connect(view->ui->actionOpen_file, &QAction::triggered, this, &Controller::openFile);
    QObject::connect(view->ui->actionTICCSVSelected_File, &QAction::triggered, this,&Controller::TICCSVSelected_File);
    QObject::connect(view->ui->actionTICCSVAll_Files, &QAction::triggered, this,&Controller::TICCSVALL_Files);
	QObject::connect(view->ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &Controller::on_treeWidget_itemDoubleClicked);
    QObject::connect(view->ui->ticplot, &ChartView::lineChartClicked, this, &Controller::getlineChartClicked);
    QObject::connect(&futureWatcher, SIGNAL(progressRangeChanged(int,int)), progressbar, SLOT(setRange(int,int)));
    QObject::connect(&futureWatcher, SIGNAL(progressValueChanged(int)),progressbar, SLOT(setValue(int)));
    QObject::connect(&futureWatcher, SIGNAL(finished()),progressbar, SLOT(closethis()));
    QObject::connect(&futureWatcher,&QFutureWatcher<GCData *>::finished,this,&Controller::futureReady);
}

void Controller::TICCSVSelected_File()
{
    csvexporter.export_single_csv(view->ui->treeWidget,data);
}

void Controller::TICCSVALL_Files()
{
    csvexporter.TICCSVALL_Files(view->ui->treeWidget,data);
}

void Controller::on_rangeChanged()
{
    qDebug()<< "onrangechanged";
}

void Controller::getlineChartClicked(QPointF qpoint)
{
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


    qDebug() << "plotting qcustomplot";
    QCustomPlot *customPlot = view->ui->qcWidget;
    customPlot = myMS.plotsingleMS(data, index,customPlot);
    view->ui->qcWidget->replot();
}

void Controller::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	// Generating generic variables needed for plotting
	QString itemclicked = item->text(1);

    qDebug() << "Itemclicked:" << itemclicked;
	GCData * mydata = data.at(itemclicked.toInt() - 1);

	// DoubleClick on TreeWidget adds Linegraph to graphicsView
    mychart = mytic.plotsingleTIC(mydata,mychart);
    view->ui->ticplot->resize(view->ui->ticplot->size() + QSize(1, 1));
    view->ui->ticplot->resize(view->ui->ticplot->size() - QSize(1, 1));
}

void Controller::initializeTreeWidget()
{
    // Qt treeWidget for displaying GC-MS files
    QTreeWidget * tree = view->ui->treeWidget;
    treetab.initializeTreeView(tree);
}

std::vector<GCData*> Controller::getGCData()
{
	return data;
}

void Controller::treeViewUpdate()
{
}

void Controller::newDataLoaded(std::vector<GCData*> data)
{
    // Runs after openFile was succesfull
    GCData * lastdata = data.back();
    std::string fileName;
    fileName = lastdata->getName();

    mychart = mytic.plotsingleTIC(lastdata,mychart);
    treetab.removeEmptyTop(view->ui->treeWidget);

    treetab.topAdd(view->ui->treeWidget,QString::fromStdString(fileName),data.size(), data.back());
    view->ui->treeWidget->setRootIndex(QModelIndex());
    mytic.setLineChartIsInit(true);
}

void Controller::futureReady()
{
    QFuture<GCData*> Qfuture = futureWatcher.future();
    qDebug() << QString("futureReady");
    //futureWatcher.
    for(int i = 0; i < Qfuture.resultCount();i++)
    {
        data.push_back(futureWatcher.resultAt(i));
        newDataLoaded(data);
    }
    qDebug() << "Imported data";
    qDebug() << "Imported data";
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
        progressbar->show();
        progressbar->setZero();

        // Start the computation.
       // futureWatcher.setFuture(QtConcurrent::map(vector, spin));
        futureWatcher.setFuture(QtConcurrent::mapped(fileList,importmzData));
        // Display the dialog and start the event loop.
        //progressbar->exec();

        //futureWatcher.waitForFinished();
    }
	view->ui->tabWidget->setCurrentIndex(1);
}

