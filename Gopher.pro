#-------------------------------------------------
#
# Project created by QtCreator 2013-05-22T14:29:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gopher
TEMPLATE = app


SOURCES += main.cpp\
        gopher.cpp \
    instrument.cpp \
    imagemode.cpp \
    save.cpp \
    import.cpp \
    tem2d.cpp \
    temtomo.cpp

HEADERS  += gopher.h \
    tem2d.h \
    temtomo.h

FORMS    += gopher.ui

RESOURCES +=
