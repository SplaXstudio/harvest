#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T13:53:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = harvest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    console.cpp \
    header/collision.cpp \
    header/uncollision.cpp \
    danimation.cpp \
    header/danimation.cpp

HEADERS  += mainwindow.h \
    console.h \
    mainloop.h \
    header/collision.h \
    header/uncollision.h \
    danimation.h \
    header/danimation.h

FORMS    += mainwindow.ui \
    console.ui
