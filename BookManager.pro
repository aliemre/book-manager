#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T22:19:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookManager
TEMPLATE = app
ICON = appicon.icns

SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    booklist.cpp \
    bookadd.cpp \
    bookdetail.cpp

HEADERS  += mainwindow.h \
    database.h \
    booklist.h \
    bookadd.h \
    bookdetail.h

FORMS    += mainwindow.ui \
    booklist.ui \
    bookadd.ui \
    bookdetail.ui

RESOURCES += \
    resources.qrc
