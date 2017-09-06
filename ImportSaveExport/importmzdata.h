#ifndef IMPORTMZDATA_H
#define IMPORTMZDATA_H

#include <QString>
#include <QApplication>

#include <netinet/in.h>
#include <vector>

#include "DataModifier/gcdata.h"
#include "UI/dialog.h"

GCData * importmzData(const QString current);



#endif
