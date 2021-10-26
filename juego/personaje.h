#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class personaje : public QGraphicsItem
{
public:
    int radio,velocidad,vida,municion,mapa,posx,posy;
    personaje();
    personaje(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    int getVida() const;
    void setVida(int newVida);
    int getMunicion() const;
    void setMunicion(int newMunicion);
    int getMapa() const;
    void setMapa(int newMapa);
};

#endif // PERSONAJE_H
