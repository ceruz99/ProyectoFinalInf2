#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QPixmap>

class proyectil : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QPixmap pixmap;
    int direccion;
private slots:
    void move();
    //void moveDown();

public:
    proyectil( int x, int y, int direccion);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget = nullptr);
};

#endif // PROYECTIL_H
