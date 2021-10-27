#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    multiplayer=new QGraphicsScene();
    mapaEscena=new QGraphicsScene();
    //manipulacion de Menu
    menu=new QGraphicsScene();
    menu->setSceneRect(0,0,500,500);
    ui->graphicsView->setScene(menu);
    ui->graphicsView->hide();
    ui->USER->hide();
    ui->L_usuario->hide();
    ui->REGISTER->hide();
    ui->reintentar->hide();
    ui->ocupado->hide();
    ui->Start->hide();
    ui->reintentar_2->hide();
    ui->ocupado_2->hide();
    //ui->BarraVida->hide();
    ui->graphicsView->setScene(mapaEscena);
    mapaEscena->setSceneRect(0,0,960,960);

    tulio=new personaje(340,390,8);
    mapaEscena->addItem(tulio);

    crearEnemigos1(rutaEnemigos1_1);
    crear_muros();
    crearMuniciones();

    //mapa
    mapaEscena->setBackgroundBrush(QBrush(QImage(":/mapa/imagenes/mapa.png")));

    //tps
    pasar.append(new teletransportacion(16,10,450,17));
    mapaEscena->addItem(pasar.back());
    pasar.append(new teletransportacion(10,16,550,445));
    mapaEscena->addItem(pasar.back());

    cargarNivel1();

    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(nivel1()));
    timer1->start(100);
      
    timer2=new QTimer(this);
    timer2->stop();
    connect(timer2,SIGNAL(timeout()),this,SLOT(actualizar()));
    timerMultiPlayer=new QTimer(this);
    timerMultiPlayer->stop();
    connect(timerMultiPlayer,SIGNAL(timeout()),this,SLOT(colisionMultiplayer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(const QString &newUser)
{
    User = newUser;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(iniciaMulti==false){
        if(evento->key()==Qt::Key_D)
        {
            tulio->moveRight();
            if(EvaluarColision(tulio))tulio->moveLeft();
            moverMapa();
        }
        else if(evento->key()==Qt::Key_A)
        {
           tulio->moveLeft();
           if(EvaluarColision(tulio))tulio->moveRight();
           moverMapa();

        }
        else if(evento->key()==Qt::Key_W)
        {
           tulio->moveUp();
           if(EvaluarColision(tulio))tulio->moveDown();
           moverMapa();

        }
        else if(evento->key()==Qt::Key_S)
        {
           tulio->moveDown();
           if(EvaluarColision(tulio))tulio->moveUp();
           moverMapa();

        }
        else if(evento->key()==Qt::Key_I and tulio->municion>0)
        {
            //creando proyectil
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,1,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_K and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,2,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_J and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,3,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_L and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,4,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
    }
    else{
        //Jugador1 movimiento---------------------------------------------
        if(evento->key()==Qt::Key_W)
        {
           jugador1->moveUp();
        }
        else if(evento->key()==Qt::Key_S)
        {
           jugador1->moveDown();
        }
        else if(evento->key()==Qt::Key_A)
        {
           jugador1->moveLeft();
        }
        else if(evento->key()==Qt::Key_D)
        {
           jugador1->moveRight();
        }
        else if(evento->key()==Qt::Key_H){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,4,
                                                   15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_F){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,3,
                                                   15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_G){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,2,
                                                   15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_T){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,1,
                                                   15,8));
            multiplayer->addItem(balasJugador1.back());
        }


        //Jugador2 movimiento ---------------------------------------------------
        else if(evento->key()==Qt::Key_5)
        {
           jugador2->moveUp();
        }
        else if(evento->key()==Qt::Key_2)
        {
           jugador2->moveDown();
        }
        else if(evento->key()==Qt::Key_1)
        {
           jugador2->moveLeft();
        }
        else if(evento->key()==Qt::Key_3)
        {
           jugador2->moveRight();
        }
        else if(evento->key()==Qt::Key_L){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,4,
                                                   15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_J){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,3,
                                                   15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_K){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,2,
                                                   15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_I){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,1,
                                                   15,8));
            multiplayer->addItem(balasJugador2.back());
        }
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

void MainWindow::crearMuniciones()
{
    {
        leer.open("../textos/municiones.txt");
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
            recarga.push_back(new municion(valores[0],valores[1],valores[2],valores[3]));
            mapaEscena->addItem(recarga.back());
        }
        leer.close();
    }
}


void MainWindow::crearEnemigos1(string ruta)
{
    leer.open(ruta);
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

void MainWindow::crearEnemigoOrbital()
{
    leer.open("../textos/orbitas.txt");
    try {
        if(!leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No lo lee"<<endl;
    }
    string linea;
    while(getline(leer, linea)){
        string pedazoLinea;
        short int valores[6];
        int tramo=0;

        for(int i=0;i<6;i++){
            if(i<5){
                tramo=linea.find(',');
                pedazoLinea=linea.substr(0,tramo);
                valores[i]=atoi(pedazoLinea.c_str());
                linea=linea.substr(tramo+1);
            }
            else
                valores[i]=atoi(linea.c_str());

        }
        orbital.push_back(new enemigogiratorio(valores[0],valores[1],valores[2],valores[3],valores[4],valores[5]));
//        if(valores[0]){
//            orbital.back()->setPintura(0);
//        }
//        else{
//            orbital.back()->setPintura(1);
//        }
        orbital.back()->setPintura(1);
        mapaEscena->addItem(orbital.back());

    }
    leer.close();
}

void MainWindow::autoguardado()
{
    leer.open("../textos/usuarios.txt");
    Temp.open("../textos/Temp.txt");
    try {
        if(!Temp.is_open() || !leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No ha leido el archivo"<<endl;
    }
    string linea,cambio;
    while(getline(leer, linea)){
        string pedazoLinea,valores[4];
        int tramo=0;
        tramo=linea.find(',');
        if(User==linea.substr(0,tramo).c_str() ){
            cuenta=new sesion(User,QVariant(tulio->getVida()).toString(),QVariant(tulio->getMunicion()).toString(),QVariant(tulio->getMapa()).toString());
            Temp<<cuenta->usuario.toStdString()<<","<<cuenta->vida.toStdString()<<","<<cuenta->municion.toStdString()<<","<<cuenta->mapa.toStdString()<<endl;

        }
        else{
            Temp<<linea<<endl;
        }
    }
    leer.close();
    Temp.close();
    remove("../textos/usuarios.txt");
    rename("../textos/Temp.txt","../textos/usuarios.txt");
}

void MainWindow::cargarNivel1()
{
    nivelActual=1;
    trampa1= new pendulo(200,100,5);
    mapaEscena->addItem(trampa1);
}

void MainWindow::cargarNivel2()
{
    nivelActual=2;
    trampa1->timer->stop();
    for(itEnemigos1=hechiceros.begin();itEnemigos1!=hechiceros.end();itEnemigos1++){
        mapaEscena->removeItem(*itEnemigos1);
        hechiceros.erase(itEnemigos1);
    }
    timerProyectilEnemigo=0;
    //Creacion movimiento parabolico
    crearEnemigos1(rutaEnemigos1_2);
    cannon1=new cannon(650,350,10,6);
    mapaEscena->addItem(cannon1);
    bolasCannon.push_back(new bolaCannon(650,350,30,(45*3.141598)/180));
    mapaEscena->addItem(bolasCannon.back());
    zombies.push_back(new enemigo2(670,40,8));
    mapaEscena->addItem(zombies.back());
    zombies.push_back(new enemigo2(670,140,8));
    mapaEscena->addItem(zombies.back());
}

void MainWindow::cargarNivel3()
{
    nivelActual=3;
    for(itEnemigos1=hechiceros.begin();itEnemigos1!=hechiceros.end();itEnemigos1++){
        mapaEscena->removeItem(*itEnemigos1);
        hechiceros.erase(itEnemigos1);
    }
    timerProyectilEnemigo=0;
    //Creacion movimiento gravitacional
    orbital.append(new enemigogiratorio(9500,15500,0,0,70000,200));
    mapaEscena->addItem(orbital.back());
    orbital.append(new enemigogiratorio(4500,15500,0,-1,70,160));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(14500,15500,0,1,700,170));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(9500,20500,-1,0,70,180));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(9500,10500,1,0,70,190));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    dt=10;
    timer2->start(100);
    //Creacion Jefe
    jefe=new enemigo3(120,180,10);
    mapaEscena->addItem(jefe);
    //Creacion Escudo jefe
    for(int i=0;i<12;i++) {
        orbes.push_back(new escudo(50,i*30,10));
        escudo * punteroOrbes=orbes.back();
        punteroOrbes->setCentro(jefe->posx,jefe->posy);
        mapaEscena->addItem(orbes.back());
    }
}

void MainWindow::moverMapa()
{
           if(pasar[0]->collidesWithItem(tulio)){
               tulio->setPos(900,70);
               tulio->posx=900;
               tulio->posy=70;
               tulio->setMapa(1);
               autoguardado();
               cargarNivel2();
           }
           if(pasar[1]->collidesWithItem(tulio)){
               tulio->setPos(20,620);
               tulio->posx=20;
               tulio->posy=620;
               tulio->setMapa(2);
               autoguardado();
               cargarNivel3();
           }
}

void MainWindow::nivel1()
{
    if(nivelActual==1){
        if((trampa1)->collidesWithItem(tulio)){
            QApplication::quit();
        }

    }
    else if(nivelActual==2){
        //Funcionamiento tiro parabolico
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
        //Colision bola cannon
        if(bolasCannon.back()->collidesWithItem(tulio))
            QApplication::quit();
        //Colisiones zombies
        for(itEnemigos2=zombies.begin();itEnemigos2!=zombies.end();itEnemigos2++){
            if(tulio->collidesWithItem(*itEnemigos2))
                tulio->vida-=20;
            enemigo2 * punteroEnemigo2= *itEnemigos2;
            for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
                if(punteroEnemigo2->collidesWithItem(*it)){
                    punteroEnemigo2->vida-=10;
                    mapaEscena->removeItem(*it);
                    balasPersonaje.erase(it);
                }
            }
            if(punteroEnemigo2->vida<=0){
                mapaEscena->removeItem(*itEnemigos2);
                zombies.erase(itEnemigos2);
            }
        }
    }
    else if(nivelActual==3){
        for(itOrbital=orbital.begin();itOrbital!=orbital.end();itOrbital++){
            if(tulio->collidesWithItem(*itOrbital))
                QApplication::quit();
        }
        jefe->move(tulio->x(),tulio->y());
        //Colisiones orbes con personaje
        for(itOrbes=orbes.begin();itOrbes!=orbes.end();itOrbes++){
            if(jefe->vida<=70){
                mapaEscena->removeItem(*itOrbes);
                orbes.erase(itOrbes);
            }
            else{
                escudo * punteroOrbes=*itOrbes;
                punteroOrbes->setCentro(jefe->posx,jefe->posy);
                punteroOrbes->move();
                if(tulio->collidesWithItem(*itOrbes))
                    tulio->vida-=1;
            }
        }
        //colision balas con jefe
        for(it=balasPersonaje.begin();it!=balasPersonaje.end();it++){
            proyectil *punteroBalas=*it;
            if(punteroBalas->collidesWithItem(jefe)){
                mapaEscena->removeItem(*it);
                balasPersonaje.erase(it);
                jefe->vida-=10;
            }
        }
        if(jefe->collidesWithItem(tulio)){
            QApplication::quit();
        }
        if(jefe->vida<=0){
            QApplication::quit();
        }
    }

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
    //Finalizacion del juego
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
                                                  punteroEnemigos1->direccionDisp,5,4));
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
            try {
                mapaEscena->removeItem(*it);
                balasPersonaje.erase(it);
            }  catch (char c) {
            }
        }
    }
    //---------------------------------------------------------------------------------------------

    //Recoger municion-----------------------------------------------------------------
    list<municion *>:: iterator itMunicion;
    for(itMunicion=recarga.begin();itMunicion!=recarga.end();itMunicion++){
        if((*itMunicion)->collidesWithItem(tulio)){
            mapaEscena->removeItem(*itMunicion);
            recarga.erase(itMunicion);
            tulio->municion+=15;
        }
    }
    //----------------------------------------------------------------------------------


    //Colisiones enemigo2----------------------------------------------------------------
    //Con muros
    int enemigo2Parar=0;
    for(itEnemigos2=zombies.begin();itEnemigos2!=zombies.end();itEnemigos2++){
        enemigo2 * punteroEnemigo2=*itEnemigos2;
        if(EvaluarColision(*itEnemigos2))
            enemigo2Parar=1;
        else
            enemigo2Parar=2;
        switch (enemigo2Parar) {
        case 1:{
            punteroEnemigo2->move(tulio->posx,tulio->posy,true);
            break;
        }
        case 2:{
            punteroEnemigo2->move(tulio->posx,tulio->posy,false);
            break;
        }
        }
    }

    //-----------------------------------------------------------------------------------
}

template <typename tipo>
bool MainWindow::EvaluarColision(tipo *objeto)//Sirve para evaluar colisiones con los muros.
{

    for(itMuros=paredes.begin();itMuros!=paredes.end();itMuros++){
       if((*itMuros)->collidesWithItem(objeto)) return true;
    }
    return false;
}
void MainWindow::actualizar()
{
    for (int i=0;i<orbital.size() ;i++ ) {
        for (int j=0;j< orbital.size() ;j++ ) {
            if(i!=j){
                orbital.at(i)->acelerar(orbital.at(j)->PX,orbital.at(j)->PY,orbital.at(j)->masa);
                orbital.at(i)->actualizar(dt);
            }
        }
    }
}


void MainWindow::on_Nueva_clicked()
{
    ui->USER->show();
    ui->L_usuario->show();
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->REGISTER->show();
    ui->Salir->hide();
    ui->multi->hide();
}
void MainWindow::on_REGISTER_clicked()
{
    ui->USER->show();
    User=ui->USER->text();
    setUser(User);
    cuenta=new sesion(User,"100","15","0");
    if(cuenta->busquedaUsuario()==true){
        ui->reintentar->show();
        ui->ocupado->show();
        User=ui->USER->text();
        cuenta=new sesion(User,"100","15","0");
        setUser(User);
    }
    else{
        guardar.open("../textos/usuarios.txt",ios::app);
        try {
            if(!guardar.is_open())
                throw '1';
        }  catch (char c) {
            if(c=='1')
                cout<<"No ha leido el archivo"<<endl;
        }
            guardar<<cuenta->usuario.toStdString()<<","<<cuenta->vida.toStdString()<<","<<cuenta->municion.toStdString()<<","<<cuenta->mapa.toStdString()<<endl;
            guardar.close();
            ui->USER->hide();
            ui->REGISTER->hide();
            ui->reintentar->hide();
            ui->ocupado->hide();
            ui->REGISTER->hide();
            ui->L_usuario->hide();
            setUser(User);
            ui->graphicsView->show();
            //ui->BarraVida->setValue(tulio->getVida());
            //ui->BarraVida->show();

    }

}


void MainWindow::on_Cargar_clicked()
{
    ui->USER->show();
    ui->L_usuario->show();
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->Salir->hide();
    ui->Start->show();
}
void MainWindow::on_Start_clicked()
{
    ui->USER->show();
    User=ui->USER->text();
    cuenta=new sesion(User,"0","0","0");
    if(cuenta->busquedaUsuario()==false){
        ui->reintentar_2->show();
        ui->ocupado_2->show();
        User=ui->USER->text();
        cuenta=new sesion(User,"0","0","0");
        setUser(User);
    }
    else{
        leer.open("../textos/usuarios.txt",ios::in);
        try {
            if(!leer.is_open())
                throw '1';
        }  catch (char c) {
            if(c=='1')
                cout<<"No ha leido el archivo"<<endl;
        }
        string linea;
        while(getline(leer, linea)){
            string pedazoLinea;
            short int valores[4];
            int tramo=0;
            tramo=linea.find(',');
            if(User==linea.substr(0,tramo).c_str() ){
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
                tulio->setVida(valores[1]);
                tulio->setMunicion(valores[2]);
                tulio->setMapa(valores[3]);
                //ui->BarraVida->setValue(tulio->getVida());
                cout<<tulio->mapa;
                if(tulio->mapa==1){
                    tulio->setPos(900,70);
                    tulio->posx=900;
                    tulio->posy=70; //450,17  550,445
                    cargarNivel2();
                    crearEnemigos1(rutaEnemigos1_2);
                }
                if(tulio->mapa==2){
                    tulio->setPos(20,660);
                    tulio->posx=20;
                    tulio->posy=660;
                    cargarNivel3();
                    trampa1->timer->stop();
                }
            }
        }
        setUser(User);
        leer.close();
        ui->USER->hide();
        ui->REGISTER->hide();
        ui->reintentar_2->hide();
        ui->ocupado_2->hide();
        ui->L_usuario->hide();
        ui->Start->hide();
        ui->graphicsView->show();
        ui->graphicsView->setScene(mapaEscena);
        mapaEscena->setSceneRect(0,0,960,960);
    }
}


void MainWindow::on_Salir_clicked()
{
    QApplication::quit();
}

/*void MainWindow::on_BarraVida_valueChanged(int value)
{
    //ui->BarraVida->setValue(tulio->vida);
}*/

void MainWindow::on_multi_clicked()
{
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->Salir->hide();
    ui->multi->hide();
    ui->graphicsView->setScene(multiplayer);
    multiplayer->setSceneRect(0,0,500,500);
    ui->graphicsView->show();
    iniciaMulti=true;
    timer1->stop();
    jugador1=new personaje(40,20,30);
    jugador1->velocidad+=15;
    multiplayer->addItem(jugador1);
    jugador2=new personaje(460,20,30);
    jugador2->velocidad+=15;
    multiplayer->addItem(jugador2);
    timerMultiPlayer->start(100);
}

void MainWindow::colisionMultiplayer()
{
    for(itbalasJugador1=balasJugador1.begin();itbalasJugador1!=balasJugador1.end();
        itbalasJugador1++){
        if(jugador2->collidesWithItem(*itbalasJugador1)){
            multiplayer->removeItem(*itbalasJugador1);
            balasJugador1.erase(itbalasJugador1);
            jugador2->vida-=5;
        }
    }
    for(itbalasJugador2=balasJugador2.begin();itbalasJugador2!=balasJugador2.end();
        itbalasJugador2++){
        if(jugador1->collidesWithItem(*itbalasJugador2)){
            multiplayer->removeItem(*itbalasJugador2);
            balasJugador2.erase(itbalasJugador2);
            jugador1->vida-=5;
        }
    }
    if(jugador1->vida<=0){
        QApplication::quit();
    }
    else if(jugador2->vida<=0){
        QApplication::quit();
    }
}
