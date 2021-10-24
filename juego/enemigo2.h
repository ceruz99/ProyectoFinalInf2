#ifndef ENEMIGO2_H
#define ENEMIGO2_H
#include <personaje.h>

class enemigo2: public personaje
{
public:
    int posxInicial,posyInicial;
    enemigo2(int x, int y, int r);
    void move(int objetivox, int objetivoy, bool colision);
    //colisionx y colisiony hacen que deje de moverse si choca con una pared
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ENEMIGO2_H
