QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bolacannon.cpp \
    cannon.cpp \
    enemigo1.cpp \
    enemigo2.cpp \
    enemigo3.cpp \
    enemigogiratorio.cpp \
    escudo.cpp \
    main.cpp \
    mainwindow.cpp \
    municion.cpp \
    muros.cpp \
    pendulo.cpp \
    personaje.cpp \
    proyectil.cpp \
    sesion.cpp \
    teletransportacion.cpp

HEADERS += \
    bolacannon.h \
    cannon.h \
    enemigo1.h \
    enemigo2.h \
    enemigo3.h \
    enemigogiratorio.h \
    escudo.h \
    mainwindow.h \
    municion.h \
    muros.h \
    pendulo.h \
    personaje.h \
    proyectil.h \
    sesion.h \
    teletransportacion.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
