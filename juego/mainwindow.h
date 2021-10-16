#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <personaje.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <sesiondialog.h>
#include <QKeyEvent>
#include <proyectil.h>
#include <enemigo1.h>
#include <list>

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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *mapaEscena;
    sesionDialog *sesion;
    personaje *tulio;
    list<proyectil *> balasPersonaje;
    list<proyectil *> balasEnemigo1;
    list<enemigo1 *> hechiceros;
    void keyPressEvent(QKeyEvent *evento);
    int timerProyectilEnemigo=0;
};
#endif // MAINWINDOW_H
