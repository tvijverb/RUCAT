#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QtCharts>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QtMath>
#include <QtCharts/QValueAxis>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <string>
#include <QString>
#include <QtGlobal>

#include "Extra/CpuWidget.h"
#include "Extra/MemoryWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int value() const { return m_value; }
    void drawBarChart();
    void openProgressbar();
    //void readmzXML(QString &current, mzXML *mzXMLarray,int strllen, int curr);
	//void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

public:
    Ui::MainWindow *ui;

public:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_splitter_splitterMoved();
    void on_splitter_3_splitterMoved();
    void on_splitter_2_splitterMoved();

    void writeSettings();
    void readSettings();

    //void on_tableWidget_itemClicked(QTableWidgetItem *item);

    //void on_tableWidget_itemPressed(QTableWidgetItem *item);

private:
    QGraphicsScene *grpcs;
    QGraphicsScene *nomnom;
    QChartView *chartView;
    QWidget *myscene;
    QChart *chart;
    QObjectList *plist;
    QRectF *bounds;
    int m_value;
    QStringListModel *model;
    //QAbstractAxis *axisX;
    QValueAxis *axisY;
    CpuWidget mCpuWidget;
    MemoryWidget mMemoryWidget;

signals:
	void MainWindowResized(QResizeEvent *event);
};


#endif // MAINWINDOW_H




