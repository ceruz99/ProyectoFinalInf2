#ifndef SESION_H
#define SESION_H
#include <fstream>
#include <QString>
#include <iostream>

using namespace std;

class sesion
{
private:

public:
    sesion(QString _nombre,QString _vida,QString _mun,QString _map);
    bool busquedaUsuario();
    QString usuario,vida="100",municion="15",mapa="0";
    ifstream leer;
    ofstream guardar;
    void setVida(const QString &newVida);
};

#endif // SESION_H
