#ifndef CANNON_H
#define CANNON_H
#include <muros.h>

class cannon : public muros
{
public:
    cannon(int x,int y,int w,int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);
};

#endif // CANNON_H
