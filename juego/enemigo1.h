#ifndef ENEMIGO1_H
#define ENEMIGO1_H

#include <QGraphicsItem>
#include <QPainter>

class enemigo1 : public QGraphicsItem
{
private:
    int posx, posy;
    int radio;
    int velocidad;
public:
    enemigo1(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
    void moveRight();
};

#endif // ENEMIGO1_H
