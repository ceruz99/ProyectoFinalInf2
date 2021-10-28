/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *Nueva;
    QPushButton *Cargar;
    QPushButton *Salir;
    QLabel *L_usuario;
    QLineEdit *USER;
    QPushButton *REGISTER;
    QLabel *ocupado;
    QLabel *reintentar;
    QPushButton *Start;
    QLabel *ocupado_2;
    QLabel *reintentar_2;
    QPushButton *multi;
    QLabel *vidaT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 960);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 960, 960));
        Nueva = new QPushButton(centralwidget);
        Nueva->setObjectName(QString::fromUtf8("Nueva"));
        Nueva->setGeometry(QRect(410, 200, 80, 21));
        Cargar = new QPushButton(centralwidget);
        Cargar->setObjectName(QString::fromUtf8("Cargar"));
        Cargar->setGeometry(QRect(410, 240, 80, 21));
        Salir = new QPushButton(centralwidget);
        Salir->setObjectName(QString::fromUtf8("Salir"));
        Salir->setGeometry(QRect(410, 310, 80, 21));
        L_usuario = new QLabel(centralwidget);
        L_usuario->setObjectName(QString::fromUtf8("L_usuario"));
        L_usuario->setGeometry(QRect(410, 220, 81, 16));
        L_usuario->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Unispace\";"));
        USER = new QLineEdit(centralwidget);
        USER->setObjectName(QString::fromUtf8("USER"));
        USER->setGeometry(QRect(490, 220, 131, 21));
        REGISTER = new QPushButton(centralwidget);
        REGISTER->setObjectName(QString::fromUtf8("REGISTER"));
        REGISTER->setGeometry(QRect(510, 240, 80, 21));
        ocupado = new QLabel(centralwidget);
        ocupado->setObjectName(QString::fromUtf8("ocupado"));
        ocupado->setGeometry(QRect(620, 220, 161, 16));
        ocupado->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(170, 0, 0);"));
        reintentar = new QLabel(centralwidget);
        reintentar->setObjectName(QString::fromUtf8("reintentar"));
        reintentar->setGeometry(QRect(490, 200, 151, 16));
        reintentar->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";"));
        Start = new QPushButton(centralwidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(510, 240, 80, 21));
        ocupado_2 = new QLabel(centralwidget);
        ocupado_2->setObjectName(QString::fromUtf8("ocupado_2"));
        ocupado_2->setGeometry(QRect(620, 220, 161, 16));
        ocupado_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(170, 0, 0);"));
        reintentar_2 = new QLabel(centralwidget);
        reintentar_2->setObjectName(QString::fromUtf8("reintentar_2"));
        reintentar_2->setGeometry(QRect(490, 200, 171, 16));
        reintentar_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";"));
        multi = new QPushButton(centralwidget);
        multi->setObjectName(QString::fromUtf8("multi"));
        multi->setGeometry(QRect(410, 270, 81, 21));
        vidaT = new QLabel(centralwidget);
        vidaT->setObjectName(QString::fromUtf8("vidaT"));
        vidaT->setGeometry(QRect(30, 30, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font.setPointSize(28);
        font.setBold(true);
        vidaT->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Nueva->setText(QCoreApplication::translate("MainWindow", "Nueva Partida", nullptr));
        Cargar->setText(QCoreApplication::translate("MainWindow", "Cargar Partida", nullptr));
        Salir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        L_usuario->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        REGISTER->setText(QCoreApplication::translate("MainWindow", "Registrar", nullptr));
        ocupado->setText(QCoreApplication::translate("MainWindow", "Usuario Ocupado", nullptr));
        reintentar->setText(QCoreApplication::translate("MainWindow", "Ingrese nuevo usuario", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        ocupado_2->setText(QCoreApplication::translate("MainWindow", "Usuario no existe", nullptr));
        reintentar_2->setText(QCoreApplication::translate("MainWindow", "Intente con otro usuario", nullptr));
        multi->setText(QCoreApplication::translate("MainWindow", "Multijugador", nullptr));
        vidaT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
