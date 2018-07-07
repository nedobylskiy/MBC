/********************************************************************************
** Form generated from reading UI file 'mbcwindow.ui'
**
** Created: Sat 13. Apr 15:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MBCWINDOW_H
#define UI_MBCWINDOW_H

#include <QtCore/QVariant>
//#include <QtGui/QAction>
#include <QAction>
//#include <QtGui/QApplication>
#include <QApplication>
/*#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>*/
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QTabWidget>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>


QT_BEGIN_NAMESPACE

class Ui_MBCWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *playerslayout;
    QHBoxLayout *players;
    QHBoxLayout *pageslayout;
    QTabWidget *pages;
    QPushButton *TestButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *toolBar;
    QToolBar *volcontrol;
    QToolBar *TimeBar;

    void setupUi(QMainWindow *MBCWindow)
    {
        if (MBCWindow->objectName().isEmpty())
            MBCWindow->setObjectName(QString::fromUtf8("MBCWindow"));
        MBCWindow->resize(578, 297);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MBCWindow->setWindowIcon(icon);
        MBCWindow->setDocumentMode(true);
        MBCWindow->setDockNestingEnabled(true);
        MBCWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MBCWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerslayout = new QHBoxLayout();
        playerslayout->setSpacing(0);
        playerslayout->setObjectName(QString::fromUtf8("playerslayout"));
        playerslayout->setSizeConstraint(QLayout::SetFixedSize);
        players = new QHBoxLayout();
        players->setSpacing(0);
        players->setObjectName(QString::fromUtf8("players"));

        playerslayout->addLayout(players);


        verticalLayout->addLayout(playerslayout);

        pageslayout = new QHBoxLayout();
        pageslayout->setSpacing(0);
        pageslayout->setObjectName(QString::fromUtf8("pageslayout"));
        pages = new QTabWidget(centralWidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        pages->setTabPosition(QTabWidget::South);
        pages->setTabShape(QTabWidget::Rounded);
        pages->setElideMode(Qt::ElideNone);
        pages->setDocumentMode(true);
        pages->setMovable(true);

        pageslayout->addWidget(pages);


        verticalLayout->addLayout(pageslayout);

        TestButton = new QPushButton(centralWidget);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        TestButton->setMaximumSize(QSize(16777215, 10));
        TestButton->setAutoRepeat(false);
        TestButton->setAutoDefault(false);
        TestButton->setDefault(false);
        TestButton->setFlat(false);

        verticalLayout->addWidget(TestButton);

        MBCWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MBCWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 578, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MBCWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MBCWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MBCWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        volcontrol = new QToolBar(MBCWindow);
        volcontrol->setObjectName(QString::fromUtf8("volcontrol"));
        MBCWindow->addToolBar(Qt::TopToolBarArea, volcontrol);
        TimeBar = new QToolBar(MBCWindow);
        TimeBar->setObjectName(QString::fromUtf8("TimeBar"));
        TimeBar->setLayoutDirection(Qt::LeftToRight);
        MBCWindow->addToolBar(Qt::TopToolBarArea, TimeBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MBCWindow);

        QMetaObject::connectSlotsByName(MBCWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MBCWindow)
    {
        MBCWindow->setWindowTitle(QApplication::translate("MBCWindow", "Mixer Broadcaster 3", 0, QApplication::UnicodeUTF8));
        TestButton->setText(QApplication::translate("MBCWindow", "TestButton", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MBCWindow", "Main", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MBCWindow", "Playback", 0, QApplication::UnicodeUTF8));
        volcontrol->setWindowTitle(QApplication::translate("MBCWindow", "VolumeControl", 0, QApplication::UnicodeUTF8));
        TimeBar->setWindowTitle(QApplication::translate("MBCWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MBCWindow: public Ui_MBCWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MBCWINDOW_H
