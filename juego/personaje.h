#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class personaje: public QGraphicsItem
{

    int r;
    int posx, posy;
    int velocidad = 5;

public:
    personaje(int r_, int x, int y);

/*estas funciones es por si nos toca sacar la posicion
 * o alguna cosa de nuestro personaje para por ejemplo
 * cambiar de mapa..
 * las get son para sacar un valor que necesitemos
 * las set es para cambiar ese  valor
*/
    int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

    //funcion para dibujar el personaje
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    //funciones de movimiento del personaje
    void moverArriba();
    void moverAbajo();
    void moverIzquierda();
    void moverDerecha();

};

#endif // PERSONAJE_H
