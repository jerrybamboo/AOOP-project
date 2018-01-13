#-------------------------------------------------
#
# Project created by QtCreator 2017-12-02T21:46:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calculator.cpp \
    data.cpp \
    notoperator.cpp \
    operator.cpp \
    transformation.cpp \
    calculation.cpp \
    mygraphicview.cpp

HEADERS  += mainwindow.h \
    calculator.h \
    data.h \
    notoperator.h \
    transformation.h \
    operator.h \
    calculation.h \
    mygraphicview.h

FORMS    += mainwindow.ui
