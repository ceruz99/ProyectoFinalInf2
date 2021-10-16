#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class personaje : public QGraphicsItem
{
protected:
    int radio;
    int velocidad;
public:
    int vida;
    int municion;
    int posx;
    int posy;
    personaje();
    personaje(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif // PERSONAJE_H
