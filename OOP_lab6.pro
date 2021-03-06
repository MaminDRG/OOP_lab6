#-------------------------------------------------
#
# Project created by QtCreator 2019-04-04T15:17:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OOP_lab6
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Equilateral_triangle.cpp \
        Isosceles_triangle.cpp \
        PaintTable.cpp \
        Point.cpp \
        Tlineedit.cpp \
        Triangle.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Equilateral_triangle.h \
        Isosceles_triangle.h \
        PaintTable.h \
        Point.h \
        Tlineedit.h \
        Triangle.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
