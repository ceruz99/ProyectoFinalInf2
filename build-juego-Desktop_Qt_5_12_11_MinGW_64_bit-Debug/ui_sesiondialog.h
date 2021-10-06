/********************************************************************************
** Form generated from reading UI file 'sesiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SESIONDIALOG_H
#define UI_SESIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sesionDialog
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sesionDialog)
    {
        if (sesionDialog->objectName().isEmpty())
            sesionDialog->setObjectName(QString::fromUtf8("sesionDialog"));
        sesionDialog->resize(731, 479);
        graphicsView = new QGraphicsView(sesionDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 711, 471));
        label = new QLabel(sesionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 100, 111, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(sesionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 170, 161, 41));
        label_2->setFont(font);
        lineEdit = new QLineEdit(sesionDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(240, 100, 191, 41));
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(sesionDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(240, 170, 191, 41));
        lineEdit_2->setFont(font);
        pushButton = new QPushButton(sesionDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 250, 201, 51));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(sesionDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 320, 201, 51));
        pushButton_2->setFont(font);

        retranslateUi(sesionDialog);

        QMetaObject::connectSlotsByName(sesionDialog);
    } // setupUi

    void retranslateUi(QDialog *sesionDialog)
    {
        sesionDialog->setWindowTitle(QApplication::translate("sesionDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("sesionDialog", "Usuario:", nullptr));
        label_2->setText(QApplication::translate("sesionDialog", "Contrase\303\261a:", nullptr));
        pushButton->setText(QApplication::translate("sesionDialog", "Iniciar sesion", nullptr));
        pushButton_2->setText(QApplication::translate("sesionDialog", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sesionDialog: public Ui_sesionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SESIONDIALOG_H
