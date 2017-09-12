QT       += core gui charts widgets concurrent winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts printsupport

QMAKE_CXXFLAGS += /MP

LIBS += zlib/lib/libz.a
TEMPLATE = app
TARGET = RUCAT
INCLUDEPATH += .
LIBS += C:\Qt\Tools\mingw530_32\i686-w64-mingw32\lib\libws2_32.a
LIBS += -lws2_32
PRECOMPILED_HEADER = precompiled_header.pch
CONFIG += precompile_header

win32 {
DEFINES += BUILDTIME=\\\"$$system('echo %time%')\\\"
DEFINES += BUILDDATE=\\\"$$system('echo %date%')\\\"
DEFINES += COMPUTERNAME=\\\"$$system('echo %computername%')\\\"
} else {
DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M.%s')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%d/%m/%y')\\\"
DEFINES += COMPUTERNAME=\\\"$$system('echo %computername%')\\\"
}


# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input

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
    #qcustomplot.cpp \
    DataModifier/interpolatetic.cpp \
    UI/advanceddialog.cpp \
    DataModifier/peakpick.cpp

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
    ui_dialog.h \
    ImportSaveExport\exportcsv.h \
    UI/chart.h \
    UI/ui_dialog.h \
    DataModifier/interpolatetic.h \
    DataModifier/spline.h \
    UI/advanceddialog.h \
    DataModifier/peakpick.h

FORMS    += mainwindow.ui \
    dialog.ui \
    UI/advanceddialog.ui

RESOURCES += \
    toolbarresource.qrc \
qdarkstyle/style.qrc
