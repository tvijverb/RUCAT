
-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T14:49:12
#
#-------------------------------------------------

QT       += core gui charts widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts printsupport

TARGET = QtmzXMLview
TEMPLATE = app

#include (C:\qwt-6.1.3\features\qwt.prf)

LIBS += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\lib\libws2_32.a
LIBS += -lws2_32

SOURCES += main.cpp\
        mainwindow.cpp \
    chartview.cpp \
    importmzdata.cpp \
    gcdata.cpp \
    msdata.cpp \
    controller.cpp \
    plottic.cpp \
    plotms.cpp \
    qcustomplot.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    chartview.h \
    importmzdata.h \
    gcdata.h \
    msdata.h \
    controller.h \
    plottic.h \
    plotms.h \
    qcustomplot.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

TARGET = linechart

RESOURCES += \
    toolbarresource.qrc \
    qdarkstyle/style.qrc
