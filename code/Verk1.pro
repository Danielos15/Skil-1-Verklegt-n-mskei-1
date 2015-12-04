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
<<<<<<< HEAD
    computer.cpp
=======
    datarepo.cpp
>>>>>>> origin/master

HEADERS += \
    ui.h \
    service.h \
    scientist.h \
    repo.h \
    computer.h \
<<<<<<< HEAD
    computer.h
=======
    datarepo.h
>>>>>>> origin/master

DISTFILES += \
    test.csv

