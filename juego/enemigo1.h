#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include <QGraphicsItem>
#include <QPainter>
#include <personaje.h>
class enemigo1 : public personaje
{
private:
    int radio;
public:
    int direccionMov;
    int direccionDisp;
    int posx, posy;
    int velocidad;
    enemigo1(int x, int y, int r, int _direccionMov,int _direccionDisp);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
    void move();
};

#endif // ENEMIGO1_H
