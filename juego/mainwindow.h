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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void movEnemigo1();
    void actualizar();
    void on_Nueva_clicked();

    void on_Cargar_clicked();

    void on_Salir_clicked();

    void on_REGISTER_clicked();

    void on_Start_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<muros*> paredes;
    QList<enemigogiratorio*>orbital;
    QList<teletransportacion*>pasar;

private:
    //Menu
    QString User;
    sesion *cuenta;
    ofstream guardar;
    fstream leer;
    Ui::MainWindow *ui;
    QGraphicsScene *mapaEscena,*menu;

    //objetos
    personaje *tulio;
    list<proyectil *> balasPersonaje;
    list<proyectil *> balasEnemigo1;
    list<enemigo1 *> hechiceros;
    list<bolaCannon *> bolasCannon;
    cannon * cannon1;
    enemigo3 * jefe;
    bolaCannon * bolaC;
    pendulo * trampa1;

    int timerProyectilEnemigo=0,timerBolaCannon=0,timerenemigo3=0;





    void keyPressEvent(QKeyEvent *evento);
    void crear_muros();
    template <typename tipo>
    bool EvaluarColision(tipo *objeto);
    void crearEnemigos1();

    float dt;
    void moverMapa();


};
#endif // MAINWINDOW_H
