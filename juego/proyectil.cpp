#include "proyectil.h"

proyectil::proyectil(int x, int y, int _direccion)
{
    this->direccion=_direccion;
    setPos(x,y);
    QTimer *timer=new QTimer(this);
    //if(direccion==true)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //else
        //connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
    timer->start(50);
}

QRectF proyectil::boundingRect() const
{
    return QRectF(0,0,5,5);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}

void proyectil::move()
{
    switch (direccion) {
    case 1:{
        setPos(x(),y()-4);
        break;
    }
    case 2:{
        setPos(x(),y()+4);
        break;
    }
    case 3:{
        setPos(x()-4,y());
        break;
    }
    case 4:{
        setPos(x()+4,y());
        break;
    }
    }
}
