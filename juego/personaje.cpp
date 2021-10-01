#include "personaje.h"

personaje::personaje(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx,posy);
}
int personaje::getR() const
{
    return r;
}

void personaje::setR(int value)
{
    r = value;
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
    return QRectF(-r,-r,2*r,2*r);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());

}

void personaje::moverArriba()
{
    posy -= 2*velocidad;
    setPos(posx, posy);
}

void personaje::moverAbajo()
{
    posy += 2*velocidad;
    setPos(posx, posy);
}

void personaje::moverIzquierda()
{
    posx -= 2*velocidad;
    setPos(posx, posy);
}

void personaje::moverDerecha()
{
    posx += 2*velocidad;
    setPos(posx, posy);
}


