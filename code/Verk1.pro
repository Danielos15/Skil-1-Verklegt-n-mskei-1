QT += core sql
QT -= gui

TARGET = Verk1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ui.cpp \
    service.cpp \
    scientist.cpp \
    computer.cpp \
    datarepo.cpp \
    relationscputosci.cpp

HEADERS += \
    ui.h \
    service.h \
    scientist.h \
    computer.h \
    datarepo.h \
    relationscputosci.h

DISTFILES += \

