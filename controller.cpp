#include "controller.h"

Controller::Controller(MainWindow * view)
{
    this->view = view;
    connectActions();
    initializeTreeWidget();
    view->ui->tabWidget->setCurrentIndex(0);
    view->ui->ticplot->setChart(mychart);
    view->ui->ticplot->setRubberBand( QChartView::HorizontalRubberBand );
}

void Controller::connectActions()
{
	QObject::connect(view->ui->actionOpen_file, &QAction::triggered, this, &Controller::openFile);
	QObject::connect(view->ui->treeView, &QTreeView::expanded, this, &Controller::treeViewUpdate);
	QObject::connect(view->ui->treeView, &QTreeView::collapsed, this, &Controller::treeViewUpdate);
	QObject::connect(view->ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &Controller::on_treeWidget_itemDoubleClicked);
	QObject::connect(view->ui->splitter, &QSplitter::splitterMoved, this, &Controller::on_splitter_moved);
	QObject::connect(view->ui->splitter_2, &QSplitter::splitterMoved, this, &Controller::on_splitter_moved);
	QObject::connect(view->ui->splitter_3, &QSplitter::splitterMoved, this, &Controller::on_splitter_moved);
    QObject::connect(view->ui->ticplot, &ChartView::lineChartClicked, this, &Controller::getlineChartClicked);
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
    qDebug() << "Entering getlineChartClicked on Controller";
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

void Controller::on_splitter_moved()
{

}

void Controller::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	// Generating generic variables needed for plotting
	QString itemclicked = item->text(1);
	GCData * mydata = data.at(itemclicked.toInt() - 1);

	// DoubleClick on TreeWidget adds Linegraph to graphicsView
    mychart = mytic.plotsingleTIC(mydata,mychart);
	
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

    treetab.topAddChild(view->ui->treeWidget,QString::fromStdString(fileName),data.size(), data.back());
    mytic.setLineChartIsInit(true);
}

void Controller::redrawTIC()
{
    qDebug() << QString("redraw TIC here");
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
        progressbar_2->show();
        progressbar_2->setZero();
        progressbar_2->setMax2(fileList.size());

        int file_count = 1;
        for (QStringList::iterator it = fileList.begin(); it != fileList.end(); ++it)
        {
            QString current = *it;
            data.push_back(importmzData(current,progressbar_2));
            newDataLoaded(data);
            progressbar_2->setValue2(file_count);
            file_count++;
        }
        progressbar_2->closethis();
    }
	view->ui->tabWidget->setCurrentIndex(1);
}

