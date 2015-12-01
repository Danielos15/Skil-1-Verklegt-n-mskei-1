QT += core
QT -= gui

TARGET = Verk1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    database.cpp \
    cps.cpp

HEADERS += \
    database.h \
    cps.h \
    ui.h \
    service.h

DISTFILES += \
    test.csv

