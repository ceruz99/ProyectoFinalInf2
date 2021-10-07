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
    //para agregar el fondo
    mapaEscena->setBackgroundBrush(QBrush(QImage(":/mapas/recursos/descarga.png")));
    sesion=new sesionDialog(this);
    sesion->show();

    //agrega muros
    crear_muros();

    tulio=new personaje(50,90,15);
    mapaEscena->addItem(tulio);

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
        if(EvaluarColision())tulio->moveLeft();
    }
    else if(evento->key()==Qt::Key_A)
    {
       tulio->moveLeft();
       if(EvaluarColision())tulio->moveRight();
    }
    else if(evento->key()==Qt::Key_W)
    {
       tulio->moveUp();
       if(EvaluarColision())tulio->moveDown();
    }
    else if(evento->key()==Qt::Key_S)
    {
       tulio->moveDown();
       if(EvaluarColision())tulio->moveUp();
    }
    else if(evento->key()==Qt::Key_2){
        //creando proyectil
        proyectil *bala=new proyectil(tulio->posx, tulio->posy);
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
bool MainWindow::EvaluarColision()
{
    QList<muros*>::Iterator it;
    for(it=paredes.begin();it!=paredes.end();it++){
       if((*it)->collidesWithItem(tulio)) return true;

    }
    return false;
}
