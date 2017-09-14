// peakitem.cpp

#include "peakitem.h"

peakitem::peakitem()
{
    Pressed = false;
    //setFlag(ItemIsMovable);
}

QRectF peakitem::boundingRect() const
{
    // outer most edges
    /*
    QRectF rect = QRectF(0, 0, 100, 100);



    painter.fillPath(path, QBrush(QColor ("blue")));*/
    return QRectF(0,0,10,10);
}

void peakitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QPainterPath path;

    path.moveTo(rect.left() + (rect.width() / 2), rect.bottom());
    path.lineTo(rect.topLeft());
    path.lineTo(rect.topRight());
    path.lineTo(rect.left() + (rect.width() / 2), rect.bottom());
    path.moveTo(rect.center());
    painter->fillPath(path, QBrush(QColor ("blue")));
}

void peakitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void peakitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
