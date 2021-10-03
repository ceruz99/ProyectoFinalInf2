#include "registrodialog.h"
#include "ui_registrodialog.h"

RegistroDialog::RegistroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistroDialog)
{
    ui->setupUi(this);
    registroEscena=new QGraphicsScene();
    ui->graphicsView->setScene(registroEscena);
    registroEscena->setSceneRect(0,0,650,450);
}

RegistroDialog::~RegistroDialog()
{
    delete ui;
}

void RegistroDialog::on_pushButton_clicked()
{
    this->newUser=ui->lineEdit->text();
    this->newPassword=ui->lineEdit_2->text();
    sesion cuenta(newUser,newPassword);
    cuenta.nuevoUsuario();
    hide();
}
