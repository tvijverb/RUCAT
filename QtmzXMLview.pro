
-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T14:49:12
#
#-------------------------------------------------

QT       += core gui charts widgets winextras concurrent

QMAKE_CXXFLAGS += /MP

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts printsupport

TARGET = QtmzXMLview
TEMPLATE = app

#include (C:\qwt-6.1.3\features\qwt.prf)

LIBS += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\lib\libws2_32.a
LIBS += -lws2_32

SOURCES += main.cpp\
        mainwindow.cpp \
    UI/chartview.cpp \
    ImportSaveExport\importmzdata.cpp \
    DataModifier\gcdata.cpp \
    DataModifier\msdata.cpp \
    controller.cpp \
    UI/plottic.cpp \
    UI/plotms.cpp \
    qcustomplot.cpp \
    UI/dialog.cpp \
    UI/treetab_2.cpp \
    ImportSaveExport\exportcsv.cpp \
    UI/chart.cpp \
    UI/chartview.cpp \
    UI/dialog.cpp \
    UI/plotms.cpp \
    UI/plottic.cpp \
    UI/treetab_2.cpp \
    controller.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    DataModifier/interpolatetic.cpp

HEADERS  += mainwindow.h \
    UI/chartview.h \
    ImportSaveExport\importmzdata.h \
    DataModifier\gcdata.h \
    DataModifier\msdata.h \
    controller.h \
    UI/plottic.h \
    UI/plotms.h \
    qcustomplot.h \
    UI/dialog.h \
    UI/treetab_2.h \
    ui_mainwindow.h \
    ui_mainwindow.h \
    ui_dialog.h \
    ImportSaveExport\exportcsv.h \
    UI/chart.h \
    UI/chartview.h \
    UI/dialog.h \
    UI/plotms.h \
    UI/plottic.h \
    UI/treetab_2.h \
    UI/ui_dialog.h \
    controller.h \
    mainwindow.h \
    qcustomplot.h \
    ui_mainwindow.h \
    DataModifier/interpolatetic.h

FORMS    += mainwindow.ui \
    dialog.ui

TARGET = linechart

RESOURCES += \
    toolbarresource.qrc \
    qdarkstyle/style.qrc
