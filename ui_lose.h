/********************************************************************************
** Form generated from reading UI file 'lose.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSE_H
#define UI_LOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Lose
{
public:
    QLabel *label;

    void setupUi(QDialog *Lose)
    {
        if (Lose->objectName().isEmpty())
            Lose->setObjectName(QStringLiteral("Lose"));
        Lose->resize(400, 300);
        label = new QLabel(Lose);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 351, 151));

        retranslateUi(Lose);

        QMetaObject::connectSlotsByName(Lose);
    } // setupUi

    void retranslateUi(QDialog *Lose)
    {
        Lose->setWindowTitle(QApplication::translate("Lose", "Dialog", 0));
        label->setText(QApplication::translate("Lose", "<html><head/><body><p><span style=\" font-size:72pt; font-weight:600;\">LOSE !!</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Lose: public Ui_Lose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSE_H
