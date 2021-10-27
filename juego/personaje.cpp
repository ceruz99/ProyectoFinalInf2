#include "personaje.h"


int personaje::getMapa() const
{
    return mapa;
}

void personaje::setMapa(int newMapa)
{
    mapa = newMapa;
}

int personaje::getMunicion() const
{
    return municion;
}

void personaje::setMunicion(int newMunicion)
{
    municion = newMunicion;
}

int personaje::getVida() const
{
    return vida;
}

void personaje::setVida(int newVida)
{
    vida = newVida;
}

personaje::personaje()
{

}

personaje::personaje(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=3;
    setPos(posx,posy);
    this->vida=100;
    this->municion=15;
    this->mapa=0;
}

QRectF personaje::boundingRect() const
{
    return QRectF(-radio,-radio,radio*2,radio*2);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void personaje::moveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void personaje::moveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void personaje::moveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);
}

void personaje::moveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}
