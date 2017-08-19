#ifndef TREETAB_2_H
#define TREETAB_2_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QTreeWidget>
#include <QString>

#include "gcdata.h"

class treeTab_2 : public QTreeWidget
{
    Q_OBJECT
public:
    explicit treeTab_2(QWidget *parent = nullptr);
    void initializeTreeView(QTreeWidget*);
    void topAddChild (QTreeWidget *, QString,int,GCData*);
    void topAdd (QTreeWidget *, QString,int,GCData*);
    void addChildInfo(QTreeWidget*, QTreeWidgetItem*, GCData*);
    void removeEmptyTop(QTreeWidget * Tree);

public:
    //QTreeWidget * Tree;


signals:

public slots:

protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent( QMouseEvent* aEvent );

private:
//QTreeWidget * Tree;
    bool m_isTouching;
    bool topIsRemoved = false;
    QTreeWidgetItem * topLevel = new QTreeWidgetItem();

};



#endif // TREETAB_2_H
