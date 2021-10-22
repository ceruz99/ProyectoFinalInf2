#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <personaje.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <sesiondialog.h>
#include <QKeyEvent>
#include <proyectil.h>
#include <enemigo1.h>
#include <muros.h>
#include <string.h>
#include <enemigo3.h>
#include <cannon.h>
#include <bolacannon.h>
#include <pendulo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void movEnemigo1();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<muros*> paredes;

private:
    fstream leer;
    Ui::MainWindow *ui;
    QGraphicsScene *mapaEscena;
    sesionDialog *sesion;
    personaje *tulio;
    list<proyectil *> balasPersonaje;
    list<proyectil *> balasEnemigo1;
    list<enemigo1 *> hechiceros;
    list<bolaCannon *> bolasCannon;
    int timerProyectilEnemigo=0;
    int timerBolaCannon=0;
    int timerenemigo3=0;
    enemigo3 * jefe;
    cannon * cannon1;
    bolaCannon * bolaC;
    pendulo * trampa1;


    void keyPressEvent(QKeyEvent *evento);
    void crear_muros();
    template <typename tipo>
    bool EvaluarColision(tipo *objeto);
    void crearEnemigos1();

};
#endif // MAINWINDOW_H
