#ifndef PEAKITEM_H
#define PEAKITEM_H

#include <QPainter>
#include <QGraphicsItem>

// class for customization
class peakitem :public QGraphicsPolygonItem
{
public:
    peakitem();

    QRectF boundingRect() const;

    // overriding paint()
    void paint(QPainter * painter,
               const QStyleOptionGraphicsItem * option,
               QWidget * widget);

    // item state
    bool Pressed;
protected:
    // overriding mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PEAKITEM_H
