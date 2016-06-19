/********************************************************************************
** Form generated from reading UI file 'win.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN_H
#define UI_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Win
{
public:
    QLabel *label;

    void setupUi(QDialog *Win)
    {
        if (Win->objectName().isEmpty())
            Win->setObjectName(QStringLiteral("Win"));
        Win->resize(400, 300);
        label = new QLabel(Win);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 281, 191));

        retranslateUi(Win);

        QMetaObject::connectSlotsByName(Win);
    } // setupUi

    void retranslateUi(QDialog *Win)
    {
        Win->setWindowTitle(QApplication::translate("Win", "Dialog", 0));
        label->setText(QApplication::translate("Win", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Result</span></p><p align=\"center\"><span style=\" font-size:72pt; font-weight:600; color:#ffff00;\">WIN!!</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Win: public Ui_Win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN_H
