#include "controller.h"

Controller::Controller(MainWindow * view)
{
    this->view = view;
    connectActions();
    initializeTreeWidget();
    view->ui->tabWidget->setCurrentIndex(0);
    view->ui->ticplot->setChart(mychart);

    // TABWIDGET HORROR
    /*
    qDebug() << "Controller.cpp";
    qDebug() << "tabWidget Geometry: " << view->ui->tabWidget->geometry();
    qDebug() << "tab Geometry" << view->ui->tab->geometry();
    qDebug() << "tab_2 Geometry" << view->ui->tab_2->geometry();
    */
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
	QObject::connect(view, &MainWindow::MainWindowResized, this, &Controller::resizeEvent);
}

void Controller::getlineChartClicked(QPointF qpoint)
{
	// Get closest point from click to chartView
	QChart * mychart = mychartView->chart();
	QList<QAbstractSeries *> myseries = mychart->series();
    int index = mytic.getClickedPointIndex(myseries[0],qpoint);

	// DoubleClick on TreeWidget adds barChart to graphicsView_2
	//QRect graphics_2ViewRect = view->ui->graphicsView_2->frameRect();
    QCustomPlot *customPlot = view->ui->qcWidget;
    customPlot = myMS.plotsingleMS(data, index,customPlot);
	view->ui->qcWidget = customPlot;
	view->ui->qcWidget->repaint();
	view->ui->qcWidget->replot();
}

void Controller::resizeEvent(QResizeEvent *event)
{
	view->ui->treeView->setGeometry(view->ui->tab->geometry());
	view->ui->treeWidget->setGeometry(view->ui->tab_2->geometry());
	//view->ui->graphicsView_2->updateGeometry();
	on_splitter_moved();
}

void Controller::on_splitter_moved()
{
	if (grpcs->isActive())
	{
		// Update LineSeries plotting at graphicsView
		// Redrawing required after splitter movement
		if (mytic.getLineChartIsInit()) {
            //QRect graphicsViewRect = view->ui->graphicsView->frameRect();
            //mychartView = mytic.redrawLineChart(graphicsViewRect);
            //view->ui->graphicsView->setSceneRect(mychartView->sceneRect());
			grpcs->setSceneRect(mychartView->sceneRect());
            //view->ui->graphicsView->repaint();
		}

		// Update BarSeries plotting at graphicsView
		// Redrawing required after splitter movement
	}
    //view->ui->treeView->setGeometry(view->ui->tab->geometry());
    //view->ui->treeWidget->setGeometry(view->ui->tab_2->geometry());
}

void Controller::on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
	// Generating generic variables needed for plotting
	QString itemclicked = item->text(1);
    //QRect graphicsViewRect = view->ui->graphicsView->frameRect();
	GCData * mydata = data.at(itemclicked.toInt() - 1);

	// DoubleClick on TreeWidget adds Linegraph to graphicsView
    //mychartView = mytic.plotsingleTIC(mydata,graphicsViewRect);

	// Add chartview to the graphicsscene 
	// Connect clickactions on chartview
	if (!mytic.getLineChartIsInit())
	{
		grpcs->addWidget(mychartView);
        //view->ui->graphicsView->setScene(grpcs);
		QObject::connect(mychartView, &ChartView::lineChartClicked, this, &Controller::getlineChartClicked);
		mytic.setLineChartIsInit(true);
	}
    //mychartView = mytic.redrawLineChart(graphicsViewRect);
    //view->ui->graphicsView->setSceneRect(mychartView->sceneRect());
	grpcs->setSceneRect(mychartView->sceneRect());
    //view->ui->graphicsView->repaint();
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
    //Treeview Geometry updater
    //view->ui->treeView->updateGeometry();
   // view->ui->treeView->resizeColumnToContents(0);
    //view->ui->treeView->resizeColumnToContents(1);
}

void Controller::newDataLoaded(std::vector<GCData*> data)
{
    // Runs after openFile was succesfull
    GCData * lastdata = data.back();
    std::string fileName;
    fileName = lastdata->getName();
    treetab.topAddChild(view->ui->treeWidget,QString::fromStdString(fileName),data.size(), data.back());
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

