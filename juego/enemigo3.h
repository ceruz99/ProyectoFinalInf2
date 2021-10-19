#ifndef ENEMIGO3_H
#define ENEMIGO3_H
#include <personaje.h>

class enemigo3 : public personaje
{
public:
    enemigo3(int x, int y, int r);
    void move(int objetivox, int objetivoy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ENEMIGO3_H
