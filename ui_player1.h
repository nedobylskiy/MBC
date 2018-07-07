/********************************************************************************
** Form generated from reading UI file 'player1.ui'
**
** Created: Sat 13. Apr 15:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER1_H
#define UI_PLAYER1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player1
{
public:
    QWidget *dockWidgetContents;

    void setupUi(QDockWidget *Player1)
    {
        if (Player1->objectName().isEmpty())
            Player1->setObjectName(QString::fromUtf8("Player1"));
        Player1->resize(146, 144);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        Player1->setWidget(dockWidgetContents);

        retranslateUi(Player1);

        QMetaObject::connectSlotsByName(Player1);
    } // setupUi

    void retranslateUi(QDockWidget *Player1)
    {
        Player1->setWindowTitle(QApplication::translate("Player1", "Player", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Player1: public Ui_Player1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER1_H
