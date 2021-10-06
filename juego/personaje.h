#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>

class personaje : public QGraphicsItem
{
private:
    int radio;
    int velocidad;
public:
    int posx;
    int posy;
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
