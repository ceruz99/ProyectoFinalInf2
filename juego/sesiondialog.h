#ifndef SESIONDIALOG_H
#define SESIONDIALOG_H

#include <QDialog>
#include <sesion.h>
#include <QGraphicsScene>
#include <registrodialog.h>

namespace Ui {
class sesionDialog;
}

class sesionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sesionDialog(QWidget *parent = nullptr);
    ~sesionDialog();
private slots:
    void on_pushButton_clicked();//Iniciar sesion
    void on_pushButton_2_clicked();//Registrarse
private:
    Ui::sesionDialog *ui;
    QString user,password;
    QGraphicsScene *inicio;
    RegistroDialog *registro;
};

#endif // SESIONDIALOG_H
