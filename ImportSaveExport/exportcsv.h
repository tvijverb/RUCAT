#ifndef EXPORTCSV_H
#define EXPORTCSV_H

#include <QAbstractItemModel>
#include <QTreeWidget>
#include <QDebug>
#include <iostream>
#include <fstream>

#include "DataModifier/gcdata.h"

class exportcsv : public QObject
{
    Q_OBJECT

public:
    explicit exportcsv(QObject *parent = nullptr);
    void export_single_csv(QTreeWidget*,std::vector<GCData*>);
    void TICCSVALL_Files(QTreeWidget * treewidget,std::vector<GCData*> data);
private:
    std::vector<GCData*> data;
};

#endif // EXPORTCSV_H
