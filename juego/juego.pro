QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    muros.cpp \
    personaje.cpp \
    proyectil.cpp \
    registrodialog.cpp \
    sesion.cpp \
    sesiondialog.cpp

HEADERS += \
    mainwindow.h \
    muros.h \
    personaje.h \
    proyectil.h \
    registrodialog.h \
    sesion.h \
    sesiondialog.h

FORMS += \
    mainwindow.ui \
    registrodialog.ui \
    sesiondialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
