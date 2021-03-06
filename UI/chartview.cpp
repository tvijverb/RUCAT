/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "UI/chartview.h"
#include <QtGui/QMouseEvent>

ChartView::ChartView(QWidget *parent) :
    QChartView(parent),
    m_isTouching(false)
{

}

void ChartView::setGData(std::vector<GCData *> myGCdata)
{
    this->data = myGCdata;
}

void ChartView::updatePeaks()
{
    for(auto i1 = begin(data); i1 != end(data); ++i1)
    {
        GCData * thisdata = *i1;
        std::vector<peakitem*> myPeakItems = thisdata->getPeakItems();
        for (auto it = begin(myPeakItems); it != end(myPeakItems); ++it)
        {
            int iteratorIndex = std::distance(begin(myPeakItems), it);

            QPointF thisPoint = myPeakItems.at(iteratorIndex)->getDataValue();

            thisPoint = chart()->mapToPosition(thisPoint);
            thisPoint.setX(thisPoint.x()-5);
            thisPoint.setY(thisPoint.y()-15);
            myPeakItems.at(iteratorIndex)->setPos(thisPoint);
        }
    }
}

bool ChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void ChartView::resizeEvent(QResizeEvent *event)
{
    QChartView::resizeEvent(event);
    updatePeaks();
}

void ChartView::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;

    if(event->button() == Qt::RightButton)
        {
            chart()->zoomReset();
            updatePeaks();
            return;
        }
    QChartView::mousePressEvent(event);
}

void ChartView::mouseMoveEvent(QMouseEvent *event)
{
    qreal x = (event->pos()).x();
    qreal y = (event->pos()).y();

    qreal xVal = chart()->mapToValue(event->pos()).x();
    qreal yVal = chart()->mapToValue(event->pos()).y();


    QPointF Max = chart()->mapToValue(chart()->plotArea().topRight());
    QPointF Min = chart()->mapToValue(chart()->plotArea().bottomLeft());

    if(xVal != 0 && yVal != 0 && xVal > Min.x() && xVal < Max.x() && yVal > Min.y() && yVal < Max.y())
    {
        Line.setLine(chart()->mapToPosition(Max).x(),y,chart()->mapToPosition(Min).x(),y);
        Line2.setLine(x,chart()->mapToPosition(Max).y(),x,chart()->mapToPosition(Min).y());
        penLine.setColor(QColor(0, 0, 0));
        penLine.setStyle(Qt::DotLine);
        item->setLine(Line);
        item2->setLine(Line2);
        item->setPen(penLine);
        item2->setPen(penLine);
        if(!item->isActive())
        {
            chart()->scene()->addItem(item);
            chart()->scene()->addItem(item2);
        }
    }
    else
    {
        if(item->isActive())
        {
            chart()->scene()->removeItem(item);
            chart()->scene()->removeItem(item2);
        }
    }

    if (m_isTouching)
        return;
    QChartView::mouseMoveEvent(event);
}

void ChartView::mouseDoubleClickEvent( QMouseEvent * event )
{

    if ( event->button() == Qt::LeftButton )
    {
        emit lineChartClicked(chart()->mapToValue(mapToScene(event->pos())));
    }
    QChartView::mouseDoubleClickEvent(event);
}

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    if (event->type() != QEvent::MouseMove)
    {

    }

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    //chart()->setAnimationOptions(QChart::SeriesAnimations);
    if(event->button() == Qt::RightButton)
        {
            return; //event doesn't go further
        }
    QChartView::mouseReleaseEvent(event);
    updatePeaks();
}

//![1]
void ChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomReset();
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}

 void ChartView::drawPeaks(GCData *currData,std::vector<int> peakList)
 {
    QLineSeries * currSeries = currData->getCurrentLineSeries();
    QList<QPointF> currPoints = currSeries->points();
    std::vector<peakitem*> myPeakItems;

    // Remove current items
    std::vector<peakitem*> currentItems = currData->getPeakItems();
    for (auto it = begin(currentItems); it != end(currentItems); ++it)
    {
        int iteratorIndex = std::distance(begin(currentItems), it);
        chart()->scene()->removeItem(currentItems.at(iteratorIndex));
    }

    // Add new items
    for (auto it = begin (peakList); it != end (peakList); ++it)
    {
        int iteratorIndex = std::distance(begin (peakList), it);
        if(*it == 1)
        {
			peakitem * newItem = new peakitem();

            QPointF thisPoint = currPoints.at(iteratorIndex);

            newItem->setDataValue(thisPoint);

			thisPoint = chart()->mapToPosition(thisPoint);
            thisPoint.setX(thisPoint.x()-5);
            thisPoint.setY(thisPoint.y()-15);
			newItem->setPos(thisPoint);	
            chart()->scene()->addItem(newItem);
            myPeakItems.push_back(newItem);
        }
    }
    currData->setPeakItems(myPeakItems);
    updatePeaks();
 }

#include "moc_chartview.cpp"
