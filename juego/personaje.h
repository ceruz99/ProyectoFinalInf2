#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

class personaje:public QObject, public QGraphicsItem
{

    int posx,posy,velocidad=5;

public:
    personaje(int x, int y);
    QPixmap *pixmap;
    QTimer *timer;
    float filas, columnas,ancho, alto;

/*estas funciones es por si nos toca sacar la posicion
 * o alguna cosa de nuestro personaje para por ejemplo
 * cambiar de mapa..
 * las get son para sacar un valor que necesitemos
 * las set es para cambiar ese  valor
*/

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


public slots:
    void reload();

};

#endif // PERSONAJE_H
