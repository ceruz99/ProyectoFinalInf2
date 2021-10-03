#ifndef REGISTRODIALOG_H
#define REGISTRODIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include <sesion.h>

namespace Ui {
class RegistroDialog;
}

class RegistroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistroDialog(QWidget *parent = nullptr);
    ~RegistroDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::RegistroDialog *ui;
    QGraphicsScene *registroEscena;
    QString newUser,newPassword;
};

#endif // REGISTRODIALOG_H
