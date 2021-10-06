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
    sesion=new sesionDialog(this);
    sesion->show();


    tulio=new personaje(0,0,20);
    mapaEscena->addItem(tulio);

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
    else if(evento->key()==Qt::Key_2){
        //creando proyectil
        proyectil *bala=new proyectil(tulio->posx, tulio->posy);
        mapaEscena->addItem(bala);
    }
}
