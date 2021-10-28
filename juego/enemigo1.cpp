#include "enemigo1.h"

enemigo1::enemigo1(int x, int y, int r,int _direccionMov, int _direccionDisp)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=1;
    vida=30;
    direccionMov=_direccionMov;
    direccionDisp=_direccionDisp;
}

QRectF enemigo1::boundingRect() const
{
    return QRectF(-radio,-radio,radio*2,radio*2);
}

void enemigo1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/hechicero.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void enemigo1::move()
{
    if(direccionMov==1){
        posx+=velocidad;
        setPos(posx,posy);
    }
    else if(direccionMov==2){
        posy+=velocidad;
        setPos(posx,posy);
    }
}
