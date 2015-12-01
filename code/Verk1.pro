QT += core
QT -= gui

TARGET = Verk1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ui.cpp \
    repo.cpp \
    service.cpp \
    scientist.cpp

HEADERS += \
    ui.h \
    service.h \
    scientist.h \
    repo.h

DISTFILES += \
    test.csv

