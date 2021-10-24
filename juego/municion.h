#ifndef MUNICION_H
#define MUNICION_H
#include <muros.h>

class municion: public muros
{
public:
    municion(int x,int y,int w,int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);
};

#endif // MUNICION_H
