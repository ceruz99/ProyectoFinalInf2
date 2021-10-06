#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>

class proyectil : public QObject, public QGraphicsItem
{
    Q_OBJECT
private slots:
    void move();
    //void moveDown();

public:
    proyectil( int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
};

#endif // PROYECTIL_H
