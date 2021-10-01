#ifndef VENTANAMAPA_H
#define VENTANAMAPA_H
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "personaje.h"
#include <QMainWindow>
#include "disparo.h"

namespace Ui {
class VentanaMapa;
}

class VentanaMapa : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaMapa(QWidget *parent = nullptr);
    ~VentanaMapa();

private:
    Ui::VentanaMapa *ui;
    personaje *persona;
    QGraphicsScene *scene;
    void KeyPressEvent(QKeyEvent *evento);
};

#endif // VENTANAMAPA_H
