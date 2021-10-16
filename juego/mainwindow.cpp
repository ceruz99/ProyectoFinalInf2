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

    hechicero=new enemigo1(0,0,20);
    mapaEscena->addItem(hechicero);
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
        //proyectil *bala=new proyectil(tulio->posx, tulio->posy,1);
        mapaEscena->addItem(balasPersonaje.back());
    }

}

void MainWindow::movEnemigo1()
{
    list<proyectil *>:: iterator it;
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

    timerProyectilEnemigo+=1;
    hechicero->moveRight();
    if(timerProyectilEnemigo==10){
        balasEnemigo1.push_back(new proyectil(hechicero->posx,hechicero->posy,2));
        //proyectil *balaEnemigo=new proyectil(hechicero->posx,hechicero->posy,2);
        mapaEscena->addItem(balasEnemigo1.back());
        timerProyectilEnemigo=0;

    }

    //Colisiones con Enemigo1------------------------------------------------------------------
    for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
        if(hechicero->collidesWithItem(*it)){
            hechicero->vida-=10;
            mapaEscena->removeItem(*it);
            balasPersonaje.erase(it);
        }
    }
    /*if(hechicero->vida<=0){
        mapaEscena->removeItem(hechicero);
        delete hechicero;
    }*/
    //-----------------------------------------------------------------------------------------
}
