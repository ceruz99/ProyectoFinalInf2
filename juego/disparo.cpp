#include "disparo.h"

disparo::disparo()
{
    //dibuja la bala
    setPixmap(QPixmap(":/images/imagenes/bala.png"));
    setScale(0.25);

    //conecta el movimiento de la bala con el cuerpo
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));
    timer->start(50);

}

void disparo::movimiento()
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    //for que identicia con quien choca la bala para eliminarlo
    for(int i=0;i<colliding_items.size();++i){
        if(typeid (*(colliding_items[i]))==typeid ("iria_enemigo")){
            //aqui irian los puntajes que se incrementa o vida que pierden

        }
    }
    setPos(x(),y()-10);
    if(pos().y() + 50 < 0){
        scene()->removeItem(this);
        delete this;
    }
}
