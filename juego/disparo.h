#ifndef DISPARO_H
#define DISPARO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class disparo:public QObject, public QGraphicsPixmapItem
{
public:
    disparo();
public slots:
    void movimiento();
};

#endif // DISPARO_H
