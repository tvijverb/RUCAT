#include "treetab_2.h"

treeTab_2::treeTab_2(QObject *parent) : QObject(parent)
{

}

void treeTab_2::initializeTreeView(QTreeWidget * Tree)
{
    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, "GC-MS files");
    Tree->addTopLevelItem(topLevel);
}

void treeTab_2::topAddChild (QTreeWidget * Tree, QString childName,int childData)
{
   // Adds childeren to the treeViewModel
   QTreeWidgetItem *item = new QTreeWidgetItem();
   item->setText(0,childName);
   item->setData(1,0,QVariant(childData));
   QTreeWidgetItem * parent = Tree->topLevelItem(0);
   parent->addChild(item);
   parent->setExpanded(true);
}
