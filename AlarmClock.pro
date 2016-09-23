#-------------------------------------------------
#
# Project created by QtCreator 2016-09-21T15:45:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlarmClock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    alarmthread.h

FORMS    += mainwindow.ui
