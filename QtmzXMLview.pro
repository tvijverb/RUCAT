######################################################################
# Automatically generated by qmake (3.1) Fri Sep 1 17:12:15 2017
######################################################################
QT       += core gui charts widgets winextras concurrent

QMAKE_CXXFLAGS += -MP

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts printsupport
#include (C:\qwt-6.1.3\features\qwt.prf)

LIBS += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\lib\libws2_32.a
LIBS += -lws2_32
TEMPLATE = app
TARGET = QtmzXMLview
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
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
    DataModifier/interpolatetic.h \
    DataModifier/spline.h

FORMS    += mainwindow.ui \
    dialog.ui

TARGET = linechart

RESOURCES += \
    toolbarresource.qrc \
qdarkstyle/style.qrc
