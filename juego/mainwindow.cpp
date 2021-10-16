#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapaEscena=new QGraphicsScene();
    ui->graphicsView->setScene(mapaEscena);
    mapaEscena->setSceneRect(0,0,700,450);
    //sesion=new sesionDialog(this);
    //sesion->show();

    tulio=new personaje(300,200,20);
    mapaEscena->addItem(tulio);

    hechiceros.push_back(new enemigo1(0,0,20));
    //hechicero=new enemigo1(0,0,20);
    mapaEscena->addItem(hechiceros.back());
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo1()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D)
    {
        tulio->moveRight();
    }
    else if(evento->key()==Qt::Key_A)
    {
       tulio->moveLeft();
    }
    else if(evento->key()==Qt::Key_W)
    {
       tulio->moveUp();
    }
    else if(evento->key()==Qt::Key_S)
    {
       tulio->moveDown();
    }
    else if(evento->key()==Qt::Key_E)
    {
        //creando proyectil
        balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,1));
        mapaEscena->addItem(balasPersonaje.back());
    }

}

void MainWindow::movEnemigo1()
{
    list<proyectil *>:: iterator it;
    list<enemigo1 *>::iterator itEnemigos1;
    enemigo1 * punteroEnemigos1;//para poder usar los metos de los elementos de la lista
    //Colisiones con Tulio---------------------------------------------------------------------
    for(it=balasEnemigo1.begin();it!=balasEnemigo1.end();it++){
        if(tulio->collidesWithItem(*it)){
            tulio->vida-=20;//daño de 10 las balas del enemigo1
            mapaEscena->removeItem(*it);
            balasEnemigo1.erase(it);
        }
    }
    if(tulio->vida<=0)
        QApplication::quit();
    //-----------------------------------------------------------------------------------------
    for(itEnemigos1=hechiceros.begin();itEnemigos1!=hechiceros.end();itEnemigos1++){
        timerProyectilEnemigo+=1;
        punteroEnemigos1=*itEnemigos1;
        punteroEnemigos1->moveRight();
        if(timerProyectilEnemigo==10){
            balasEnemigo1.push_back(new proyectil(hechiceros.back()->posx,hechiceros.back()->posy,2));
            mapaEscena->addItem(balasEnemigo1.back());
            timerProyectilEnemigo=0;
        }
        //Colisiones con Enemigo1------------------------------------------------------------------
        for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
            if(punteroEnemigos1->collidesWithItem(*it)){
                punteroEnemigos1->vida-=10;
                mapaEscena->removeItem(*it);
                balasPersonaje.erase(it);
            }
        }
        if(punteroEnemigos1->vida<=0){
            mapaEscena->removeItem(punteroEnemigos1);
            hechiceros.erase(itEnemigos1);
        }
        //-----------------------------------------------------------------------------------------
    }

}
