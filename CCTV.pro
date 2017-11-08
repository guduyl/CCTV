#-------------------------------------------------
#
# Project created by QtCreator 2017-11-08T09:32:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CCTV
TEMPLATE = app


SOURCES += main.cpp\
        cctv.cpp \
    televisionwidget.cpp \
    televisioncontrolwidget.cpp \
    televisioncontrolbutton.cpp

HEADERS  += cctv.h \
    televisionwidget.h \
    televisioncontrolwidget.h \
    televisioncontrolbutton.h \
    headers.h

DISTFILES += \
    RECORD.md \
    README.md
