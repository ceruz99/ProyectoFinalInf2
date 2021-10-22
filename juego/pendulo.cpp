#include "pendulo.h"


pendulo::pendulo(double x, double y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->longitud=sqrt(pow(posy,2)+pow(posx,2));
    anguloi=asin(posx/longitud);
    vAngulari=0;
    aAngular=-g*sin(anguloi);

    setPos(posx+150,posy+100);

    QTimer *timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
}

void pendulo::calculo()
{
    vAngular=vAngulari+(aAngular*dt);
    angulo=anguloi+(vAngular*dt)+(aAngular*dt*dt)/2;
    aAngular=-g*sin(angulo);
}

void pendulo::actualizar()
{
    calculo();

    posx=longitud*sin(anguloi);
    posy=longitud*cos(anguloi);
    setPos(posx+150,posy+100);
    vAngulari=vAngular;
    anguloi=angulo;
}

QRectF pendulo::boundingRect() const
{
    return QRectF(-radio,-radio, 2*radio, 2*radio);
}

void pendulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void pendulo::move()
{
    actualizar();
}
