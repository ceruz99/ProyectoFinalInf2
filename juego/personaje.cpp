#include "personaje.h"

personaje::personaje(int x, int y)
{
    timer=new QTimer();
    posx = x;
    posy = y;
    setPos(posx,posy);

    filas=640;
    columnas=0;

    pixmap=new QPixmap(":/images/imagenes/personaje.png");

    ancho=64;
    alto=64;

    timer->start(100);
    connect(timer,&QTimer::timeout,this,&personaje::reload);

}


int personaje::getPosx() const
{
    return posx;
}

void personaje::setPosx(int value)
{
    posx = value;
}

int personaje::getPosy() const
{
    return posy;
}

void personaje::setPosy(int value)
{
    posy = value;
}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);
}

void personaje::moverArriba()
{
    posy-=2*velocidad;
    columnas+=64;
    filas=512;

    if(columnas>=576) columnas=0;
    setPos(posx,posy);
}

void personaje::moverAbajo()
{
    posy+=2*velocidad;
    columnas+=64;
    filas=640;

    if(columnas>=576) columnas=0;
    setPos(posx,posy);
}

void personaje::moverIzquierda()
{
    posx-=2*velocidad;
    setPos(posx,posy);
    filas=576;
    columnas+=64;
    if(columnas>=576) columnas=0;
}

void personaje::moverDerecha()
{
    posx+=2*velocidad;
    setPos(posx,posy);
    filas=704;
    columnas+=64;
    if(columnas>=576) columnas=0;
}

void personaje::reload()
{
    columnas += 64;

    if(columnas >= 576){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}


