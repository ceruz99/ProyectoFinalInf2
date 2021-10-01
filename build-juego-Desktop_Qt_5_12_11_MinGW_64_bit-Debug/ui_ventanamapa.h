/********************************************************************************
** Form generated from reading UI file 'ventanamapa.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAMAPA_H
#define UI_VENTANAMAPA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaMapa
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaMapa)
    {
        if (VentanaMapa->objectName().isEmpty())
            VentanaMapa->setObjectName(QString::fromUtf8("VentanaMapa"));
        VentanaMapa->resize(1920, 1080);
        centralwidget = new QWidget(VentanaMapa);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1911, 1031));
        VentanaMapa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaMapa);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 20));
        VentanaMapa->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaMapa);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaMapa->setStatusBar(statusbar);

        retranslateUi(VentanaMapa);

        QMetaObject::connectSlotsByName(VentanaMapa);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaMapa)
    {
        VentanaMapa->setWindowTitle(QApplication::translate("VentanaMapa", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaMapa: public Ui_VentanaMapa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAMAPA_H
