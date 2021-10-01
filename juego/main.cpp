#include "mainwindow.h"
#include "ventanamapa.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //crea nuevo objeto del main window
    VentanaMapa mapa;
    //oculto la clase mainwindow
    w.show();
    //muestro la clase ventanamapa
    //mapa.show();
    return a.exec();
}
