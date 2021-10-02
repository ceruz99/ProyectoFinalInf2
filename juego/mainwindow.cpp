#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    inicio=new QGraphicsScene();
    ui->graphicsView->setScene(inicio);
    inicio->setSceneRect(0,0,700,450);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    user=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    sesion cuenta(user,password);
    cuenta.nuevoUsuario();
    if(cuenta.busquedaUsuario()==true)
        cout<<"funciona busqueda.."<<endl;
}
