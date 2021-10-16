#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include <QGraphicsItem>
#include <QPainter>
#include <personaje.h>
class enemigo1 : public personaje
{
private:
    int radio;
    int velocidad;
public:
    int posx, posy;
    enemigo1(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
};

#endif // ENEMIGO1_H
