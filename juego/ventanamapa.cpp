#include "ventanamapa.h"
#include "ui_ventanamapa.h"


VentanaMapa::VentanaMapa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaMapa)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,400,400);
    persona=new personaje(220,250);
    scene->addItem(persona);
}

VentanaMapa::~VentanaMapa()
{
    delete ui;
}

void VentanaMapa::KeyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_W){
        persona->moverArriba();
    }
    else if(evento->key()==Qt::Key_S){
        persona->moverAbajo();
    }
    else if(evento->key()==Qt::Key_A){
        persona->moverIzquierda();
    }
    else if(evento->key()==Qt::Key_D){
        persona->moverDerecha();
    }
    else if(evento->key() == Qt::Key_Space){
        //create bala
        disparo * bala = new disparo();
        bala->setPos(x(),y());
        scene->addItem(bala);
    }
}
