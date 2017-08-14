#ifndef TREETAB_2_H
#define TREETAB_2_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QString>

#include "gcdata.h"

class treeTab_2 : public QObject
{
    Q_OBJECT
public:
    explicit treeTab_2(QObject *parent = nullptr);
    void initializeTreeView(QTreeWidget*);
    void topAddChild (QTreeWidget *, QString,int,GCData*);
    void addChildInfo(QTreeWidget*, QTreeWidgetItem*, GCData*);

public:
    //QTreeWidget * Tree;


signals:

public slots:

private:
//QTreeWidget * Tree;

};



#endif // TREETAB_2_H
