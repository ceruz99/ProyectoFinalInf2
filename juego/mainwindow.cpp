#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapaEscena=new QGraphicsScene();
    ui->graphicsView->setScene(mapaEscena);
    mapaEscena->setSceneRect(0,0,950,950);
    //sesion=new sesionDialog(this);
    //sesion->show();

    //mapa
    mapaEscena->setBackgroundBrush(QBrush(QImage(":/mapa/imagenes/mapa.png")));


    tulio=new personaje(300,200,20);
    mapaEscena->addItem(tulio);

    hechicero=new enemigo1(0,0,20);
    mapaEscena->addItem(hechicero);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movEnemigo1()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D)
    {
        tulio->moveRight();
    }
    else if(evento->key()==Qt::Key_A)
    {
       tulio->moveLeft();
    }
    else if(evento->key()==Qt::Key_W)
    {
       tulio->moveUp();
    }
    else if(evento->key()==Qt::Key_S)
    {
       tulio->moveDown();
    }
    else if(evento->key()==Qt::Key_E)
    {
        //creando proyectil
        proyectil *bala=new proyectil(tulio->posx, tulio->posy,1);
        mapaEscena->addItem(bala);
    }
}

void MainWindow::crear_muros()
{
    {
        leer.open("../textos/muros.txt");
        try {
            if(!leer.is_open())
                throw '1';
            else
                throw '2';
        }  catch (char c) {
            if(c=='1')
                cout<<"No lo lee";
        }
        string linea;
        while(getline(leer, linea)){
            string pedazoLinea;
            short int valores[4];
            int tramo=0;

            for(int i=0;i<4;i++){
                if(i<3){
                    tramo=linea.find(',');
                    pedazoLinea=linea.substr(0,tramo);
                    valores[i]=atoi(pedazoLinea.c_str());
                    linea=linea.substr(tramo+1);
                }
                else
                    valores[i]=atoi(linea.c_str());
            }
            paredes.push_back(new muros(valores[0],valores[1],valores[2],valores[3]));
            mapaEscena->addItem(paredes.back());
        }
        leer.close();
    }
}


void MainWindow::movEnemigo1()
{
    timerProyectilEnemigo+=1;
    hechicero->moveRight();
    if(timerProyectilEnemigo==10){
        proyectil *balaEnemigo=new proyectil(hechicero->posx,hechicero->posy,2);
        mapaEscena->addItem(balaEnemigo);
        timerProyectilEnemigo=0;
    }

}


