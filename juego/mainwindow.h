#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <sesion.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <ventanamapa.h>

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
    void on_pushButton_clicked();

private:
    QMainWindow *ventanamain;
    Ui::MainWindow *ui;
    QString user,password;
    QGraphicsScene *inicio;
};
#endif // MAINWINDOW_H
