#include "treetab_2.h"

treeTab_2::treeTab_2(QWidget *parent) : QTreeWidget(parent),
    m_isTouching(false)
{

}

bool treeTab_2::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.

    }

    return QTreeWidget::viewportEvent(event);
}

void treeTab_2::mousePressEvent( QMouseEvent* aEvent )
{
    QTreeWidget::mousePressEvent( aEvent );


    const QPoint clickedPosition    = aEvent->pos();
    const QRect itemRectangle       = visualItemRect( itemAt( clickedPosition ) );
    const int iconOffset            = itemRectangle.height() - iconSize().height();

    QRect iconRectangle;
    iconRectangle.setTopLeft( itemRectangle.topLeft() + QPoint( iconOffset, iconOffset ) );
    iconRectangle.setWidth( iconSize().width() );
    iconRectangle.setHeight( iconSize().height() );
}

void treeTab_2::initializeTreeView(QTreeWidget * Tree)
{
    topLevel->setText(0, "No data loaded in RUCAT");
    Tree->addTopLevelItem(topLevel);
}

void treeTab_2::topAdd (QTreeWidget * Tree, QString childName,int childData, GCData* data)
{
   // Adds childeren to the treeViewModel
   QTreeWidgetItem *item = new QTreeWidgetItem();
   item->setText(0,childName);
   item->setData(1,0,QVariant(childData));
   Tree->addTopLevelItem(item);
   addChildInfo(Tree,item,data);
   Tree->setExpandsOnDoubleClick(false);
}

void treeTab_2::removeEmptyTop(QTreeWidget * Tree)
{
    if(!topIsRemoved)
    {
        topLevel->setHidden(true);
        topIsRemoved = true;
    }
}

void treeTab_2::topAddChild (QTreeWidget * Tree, QString childName,int childData, GCData* data)
{
   // Adds childeren to the treeViewModel
   QTreeWidgetItem *item = new QTreeWidgetItem();
   item->setText(0,childName);
   item->setData(1,0,QVariant(childData));
   item->setFlags(item->flags()&~Qt::ItemIsSelectable);
   QTreeWidgetItem * parent = Tree->topLevelItem(0);
   parent->addChild(item);
   //parent->setExpanded(true);
   addChildInfo(Tree,item,data);
}



void treeTab_2::addChildInfo(QTreeWidget * Tree, QTreeWidgetItem * item, GCData* data)
{
    QTreeWidgetItem * scans = new QTreeWidgetItem();
    QString gclength = QString::number(data->getScan_n());
    scans->setText(0,"chromatogram data length: " + gclength);
    scans->setData(1,0,QVariant(data->getScan_n()));
    item->addChild(scans);
}


