QT += core sql
QT -= gui

TARGET = Verk1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ui.cpp \
    repo.cpp \
    service.cpp \
    scientist.cpp \
    computer.cpp \
    datarepo.cpp

HEADERS += \
    ui.h \
    service.h \
    scientist.h \
    repo.h \
    computer.h \
    datarepo.h

DISTFILES += \
    test.csv

