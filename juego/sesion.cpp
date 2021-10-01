#include "sesion.h"

sesion::sesion(QString _nombre, QString _contrasena)
{
    this->usuario=_nombre;
    this->contrasena=_contrasena;
}

bool sesion::busquedaUsuario()
{
    leer.open("../textos/usuarios.txt");
    try {
        if(!leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No ha leido el archivo"<<endl;
    }
    string linea;
    int separador;
    while(getline(leer,linea)){
        separador=linea.find(',');
        if(usuario==linea.substr(0,separador).c_str() and contrasena==linea.substr(separador+1).c_str()){
            leer.close();
            return true;
        }
    }
    leer.close();
    return false;
}

void sesion::nuevoUsuario()
{
    guardar.open("../textos/usuarios.txt",ios::app);
    try {
        if(!guardar.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No ha leido el archivo"<<endl;
    }
    guardar<<endl<<this->usuario.toStdString()<<","<<this->contrasena.toStdString();
    guardar.close();
}
