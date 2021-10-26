#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <personaje.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <proyectil.h>
#include <enemigo1.h>
#include <muros.h>
#include <string.h>
#include <enemigo3.h>
#include "enemigogiratorio.h"
#include <cannon.h>
#include <bolacannon.h>
#include <pendulo.h>
#include "teletransportacion.h"
#include "sesion.h"
#include <municion.h>
#include <enemigo2.h>

#define rutaEnemigos1_1 "../textos/enemigos1.txt"
#define rutaEnemigos1_2 "../textos/enemigos1_2.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void nivel1();
    void actualizar();
    void on_Nueva_clicked();

    void on_Cargar_clicked();

    void on_Salir_clicked();

    void on_REGISTER_clicked();

    void on_Start_clicked();

    void on_BarraVida_valueChanged(int value);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<muros*> paredes;
    QList<enemigogiratorio*>orbital;
    QList<teletransportacion*>pasar;

    void setUser(const QString &newUser);

private:

    //Menu
    QString User;
    sesion *cuenta;
    ofstream guardar,Temp;
    QTimer *timer1;

    fstream leer;
    Ui::MainWindow *ui;
    QGraphicsScene *mapaEscena,*menu;

    //objetos
    personaje *tulio;
    list<proyectil *> balasPersonaje;
    list<proyectil *> balasEnemigo1;
    list<enemigo1 *> hechiceros;
    list<bolaCannon *> bolasCannon;

    list<municion *> recarga;
    list<enemigo2 *> zombies;
    enemigo3 * jefe;
    cannon * cannon1;
    bolaCannon * bolaC;
    pendulo * trampa1;
    int nivelActual=1;

    list<proyectil *>:: iterator it;
    list<enemigo1 *>::iterator itEnemigos1;
    list<enemigo2 *>::iterator itEnemigos2;
    QList<muros*>::Iterator itMuros;

    int timerProyectilEnemigo=0,timerBolaCannon=0,timerenemigo3=0;





    void keyPressEvent(QKeyEvent *evento);
    void crear_muros();
    void crearMuniciones();
    template <typename tipo>
    bool EvaluarColision(tipo *objeto);
    void crearEnemigos1(string ruta);
    void crearEnemigoOrbital();
    void autoguardado();

    float dt;
    void moverMapa();


};
#endif // MAINWINDOW_H
