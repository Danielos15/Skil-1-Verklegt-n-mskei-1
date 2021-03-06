#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T22:29:14
#
#-------------------------------------------------

QT       += core gui sql
CONFIG   += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = code
TEMPLATE = app


SOURCES += main.cpp\
    ui/mainwindow.cpp \
    models/computer.cpp \
    models/scientist.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    repositories/scientistrepository.cpp \
    services/computerservice.cpp \
    services/linkservice.cpp \
    services/scientistservice.cpp \
    utilities/utils.cpp \
    ui/addsci.cpp \
    ui/addcpu.cpp \
    ui/areyousure.cpp

HEADERS  += ui/mainwindow.h \
    models/computer.h \
    models/scientist.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    repositories/scientistrepository.h \
    services/computerservice.h \
    services/linkservice.h \
    services/scientistservice.h \
    utilities/constants.h \
    utilities/utils.h \
    ui/addsci.h \
    ui/addcpu.h \
    ui/areyousure.h

FORMS    += ui/mainwindow.ui \
    ui/addsci.ui \
    ui/addcpu.ui \
    ui/areyousure.ui

RESOURCES += \
    ui/myres.qrc
