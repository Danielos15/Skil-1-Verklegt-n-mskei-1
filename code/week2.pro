QT += core
QT -= gui
QT += sql

TARGET = week2
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    utilities/utils.cpp \
    models/computer.cpp \
    services/computerservice.cpp \
    repositories/computerrepository.cpp \
    repositories/linkrepository.cpp \
    services/linkservice.cpp

HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    ui/consoleui.h \
    models/computer.h \
    services/computerservice.h \
    repositories/computerrepository.h \
    repositories/linkrepository.h \
    services/linkservice.h

INCLUDEPATH += models \
    repositories \
    services \
    ui
