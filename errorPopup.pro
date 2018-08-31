#-------------------------------------------------
#
# Project created by QtCreator 2016-08-29T18:16:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = errorPopup
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

linux-imx51-g++ {
    DEFINES += IMX_DEVICE
    target.path = /usr/local/avicon-31/errorMessage
    INSTALLS += target
}
