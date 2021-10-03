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
    this->user=ui->lineEdit->text();
    this->password=ui->lineEdit_2->text();
    sesion cuenta(user,password);
    if(cuenta.busquedaUsuario()==true)
        cout<<"funciona busqueda.."<<endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    registro=new RegistroDialog(this);
    registro->show();
}
