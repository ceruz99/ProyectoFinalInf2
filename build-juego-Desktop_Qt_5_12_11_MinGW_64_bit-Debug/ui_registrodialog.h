/********************************************************************************
** Form generated from reading UI file 'registrodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRODIALOG_H
#define UI_REGISTRODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistroDialog
{
public:
    QGraphicsView *graphicsView;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *RegistroDialog)
    {
        if (RegistroDialog->objectName().isEmpty())
            RegistroDialog->setObjectName(QString::fromUtf8("RegistroDialog"));
        RegistroDialog->resize(681, 487);
        graphicsView = new QGraphicsView(RegistroDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 681, 491));
        lineEdit = new QLineEdit(RegistroDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(290, 80, 211, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(RegistroDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(290, 160, 211, 51));
        lineEdit_2->setFont(font);
        label = new QLabel(RegistroDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 80, 201, 51));
        label->setFont(font);
        label_2 = new QLabel(RegistroDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 160, 251, 51));
        label_2->setFont(font);
        pushButton = new QPushButton(RegistroDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 260, 241, 81));
        pushButton->setFont(font);

        retranslateUi(RegistroDialog);

        QMetaObject::connectSlotsByName(RegistroDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistroDialog)
    {
        RegistroDialog->setWindowTitle(QApplication::translate("RegistroDialog", "Dialog", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label->setText(QApplication::translate("RegistroDialog", "Nuevo usuario:", nullptr));
        label_2->setText(QApplication::translate("RegistroDialog", "Nueva contrase\303\261a:", nullptr));
        pushButton->setText(QApplication::translate("RegistroDialog", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistroDialog: public Ui_RegistroDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRODIALOG_H
