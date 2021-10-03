#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <sesion.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <registrodialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();//Iniciar sesion
    void on_pushButton_2_clicked();//Registrarse

private:
    Ui::MainWindow *ui;
    QString user,password;
    QGraphicsScene *inicio;
    RegistroDialog *registro;
};
#endif // MAINWINDOW_H
