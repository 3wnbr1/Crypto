#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T22:06:42
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cryptor
TEMPLATE = app

RESOURCES += rsc/ressources.qrc

macx {
    ICON = rsc/logo.icns
}
else {
    RC_ICONS = rsc/logo.ico
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
        src/crypto.cpp

HEADERS += \
        src/mainwindow.h \
        src/crypto.h

FORMS += \
        ui/mainwindow.ui

TRANSLATIONS = rsc/cryptor_en.ts rsc/cryptor_fr.ts
