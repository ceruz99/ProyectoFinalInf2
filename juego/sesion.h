#ifndef SESION_H
#define SESION_H
#include <fstream>
#include <QString>
#include <iostream>

using namespace std;

class sesion
{
private:
    QString usuario;
    QString contrasena;
    ifstream leer;
    ofstream guardar;
public:
    sesion(QString _nombre,QString _contrasena);
    bool busquedaUsuario();
    void nuevoUsuario();
};

#endif // SESION_H
