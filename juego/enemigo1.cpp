#include "enemigo1.h"

enemigo1::enemigo1(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=5;
}

QRectF enemigo1::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void enemigo1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void enemigo1::moveRight()
{
    posx+=velocidad;
    setPos(posx,posy);
}
