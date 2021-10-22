#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mapaEscena=new QGraphicsScene();
    ui->graphicsView->setScene(mapaEscena);
    mapaEscena->setSceneRect(0,0,960,960);
    //sesion=new sesionDialog(this);
    //sesion->show();

    //mapa
    mapaEscena->setBackgroundBrush(QBrush(QImage(":/mapa/imagenes/mapa.png")));

    tulio=new personaje(150,190,8);
    mapaEscena->addItem(tulio);
    crear_muros();
    //crearEnemigos1();

    jefe=new enemigo3(120,180,8);
    mapaEscena->addItem(jefe);

    cannon1=new cannon(650,350,10,6);
    mapaEscena->addItem(cannon1);

    //bolaC= new bolaCannon(650,350,30,(45*3.141598)/180);
    //mapaEscena->addItem(bolaC);

    bolasCannon.push_back(new bolaCannon(650,350,30,(45*3.141598)/180));
    mapaEscena->addItem(bolasCannon.back());

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
        if(EvaluarColision(tulio))tulio->moveLeft();
    }
    else if(evento->key()==Qt::Key_A)
    {
       tulio->moveLeft();
       if(EvaluarColision(tulio))tulio->moveRight();
    }
    else if(evento->key()==Qt::Key_W)
    {
       tulio->moveUp();
       if(EvaluarColision(tulio))tulio->moveDown();
    }
    else if(evento->key()==Qt::Key_S)
    {
       tulio->moveDown();
       if(EvaluarColision(tulio))tulio->moveUp();
    }
    else if(evento->key()==Qt::Key_I and tulio->municion>0)
    {
        //creando proyectil
        balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,1));
        mapaEscena->addItem(balasPersonaje.back());
        tulio->municion-=1;
    }
    else if(evento->key()==Qt::Key_K and tulio->municion>0)
    {
        balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,2));
        mapaEscena->addItem(balasPersonaje.back());
        tulio->municion-=1;
    }
    else if(evento->key()==Qt::Key_J and tulio->municion>0)
    {
        balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,3));
        mapaEscena->addItem(balasPersonaje.back());
        tulio->municion-=1;
    }
    else if(evento->key()==Qt::Key_L and tulio->municion>0)
    {
        balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,4));
        mapaEscena->addItem(balasPersonaje.back());
        tulio->municion-=1;
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

void MainWindow::crearEnemigos1()
{
    leer.open("../textos/enemigos1.txt");
    try {
        if(!leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No lo lee"<<endl;
    }
    string linea;
    while(getline(leer,linea)){
        string pedazoLinea;
        short int valores[5];
        int tramo=0;

        for(int i=0;i<5;i++){
            if(i<4){
                tramo=linea.find(',');
                pedazoLinea=linea.substr(0,tramo);
                valores[i]=atoi(pedazoLinea.c_str());
                linea=linea.substr(tramo+1);
            }
            else
                valores[i]=atoi(linea.c_str());
        }
        hechiceros.push_back(new enemigo1(valores[0],valores[1],valores[2],valores[3],valores[4]));
        mapaEscena->addItem(hechiceros.back());
    }
    leer.close();
}


void MainWindow::movEnemigo1()
{
    jefe->move(tulio->x(),tulio->y());

    for(int i=0;i<10;i++){
        bolasCannon.back()->CalcularVelocidad();
        bolasCannon.back()->CalcularPosicion();
        bolasCannon.back()->Mover();
        timerBolaCannon+=1;
        if(timerBolaCannon==500){
            mapaEscena->removeItem(bolasCannon.back());
            list<bolaCannon *>::iterator it;
            it=bolasCannon.begin();
            bolasCannon.erase(it);
            bolasCannon.push_back(new bolaCannon(650,350,30,(45*3.141598)/180));
            mapaEscena->addItem(bolasCannon.back());
            timerBolaCannon=0;
        }
    }

    /*list<proyectil *>:: iterator it;
    list<enemigo1 *>::iterator itEnemigos1;
    enemigo1 * punteroEnemigos1;//para poder usar los metodos de los elementos de la lista
    //Colisiones balas Enemigo1----------------------------------------------------------------
    for(it=balasEnemigo1.begin();it!=balasEnemigo1.end();it++){
        if(tulio->collidesWithItem(*it)){
            tulio->vida-=20;//daño de 10 las balas del enemigo1
            mapaEscena->removeItem(*it);
            balasEnemigo1.erase(it);
        }
        else if(EvaluarColision(*it)==true){
            mapaEscena->removeItem(*it);
            balasEnemigo1.erase(it);
        }
    }
    if(tulio->vida<=0)
        QApplication::quit();
    //-----------------------------------------------------------------------------------------
    timerProyectilEnemigo+=1;
    for(itEnemigos1=hechiceros.begin();itEnemigos1!=hechiceros.end();itEnemigos1++){
        punteroEnemigos1=*itEnemigos1;
        if(EvaluarColision(punteroEnemigos1)==true)
            punteroEnemigos1->velocidad*=-1;
        punteroEnemigos1->move();
        //los siguientes dos condicionales se hicieron para solucionar problema en el que solo
        //dispara uno de los enemigos a la vez, si el timer interno se reiniciara a 0 cada vez que
        //entrara a un solo condicional solo queda disparando un enemigo a la vez.
        if(timerProyectilEnemigo==9){
            balasEnemigo1.push_back(new proyectil(punteroEnemigos1->posx,punteroEnemigos1->posy,
                                                  punteroEnemigos1->direccionDisp));
            mapaEscena->addItem(balasEnemigo1.back());
        }
        else if(timerProyectilEnemigo==10){
            timerProyectilEnemigo=0;
        }
        //Colisiones balas personaje con Enemigo1--------------------------------------------------
        for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
            if(punteroEnemigos1->collidesWithItem(*it)){
                punteroEnemigos1->vida-=10;
                mapaEscena->removeItem(*it);
                balasPersonaje.erase(it);
            }
        }
        if(punteroEnemigos1->vida<=0){
            mapaEscena->removeItem(punteroEnemigos1);
            hechiceros.erase(itEnemigos1);
        }
        //-----------------------------------------------------------------------------------------
    }

    //Colisiones balas de personaje con los muros--------------------------------------------------
    for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
        if(EvaluarColision(*it)==true){
            mapaEscena->removeItem(*it);
            balasPersonaje.erase(it);
        }
    }*/
    //---------------------------------------------------------------------------------------------
}
template <typename tipo>
bool MainWindow::EvaluarColision(tipo *objeto)//Sirve para evaluar colisiones con los muros.
{
    QList<muros*>::Iterator it;
    for(it=paredes.begin();it!=paredes.end();it++){
       if((*it)->collidesWithItem(objeto)) return true;
    }
    return false;
}


