#include "sesiondialog.h"
#include "ui_sesiondialog.h"

sesionDialog::sesionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sesionDialog)
{
    ui->setupUi(this);
    inicio=new QGraphicsScene();
    ui->graphicsView->setScene(inicio);
    inicio->setSceneRect(0,0,700,450);
}

sesionDialog::~sesionDialog()
{
    delete ui;
}

void sesionDialog::on_pushButton_clicked()
{
    this->user=ui->lineEdit->text();
    this->password=ui->lineEdit_2->text();
    sesion cuenta(user,password);
    if(cuenta.busquedaUsuario()==true){
        cout<<"funciona busqueda.."<<endl;
        hide();
    }
}

void sesionDialog::on_pushButton_2_clicked()
{
    registro=new RegistroDialog(this);
    registro->show();
}
