/********************************************************************************
** Form generated from reading UI file 'inputsystem.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTSYSTEM_H
#define UI_INPUTSYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputSystem
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_2;
    QDial *vol;
    QLabel *pmicoff;
    QLabel *pmicon;
    QProgressBar *left;
    QProgressBar *right;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *micon;
    QPushButton *micoff;

    void setupUi(QWidget *InputSystem)
    {
        if (InputSystem->objectName().isEmpty())
            InputSystem->setObjectName(QString::fromUtf8("InputSystem"));
        InputSystem->resize(381, 226);
        verticalLayout = new QVBoxLayout(InputSystem);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget = new QListWidget(InputSystem);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout->addWidget(listWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        vol = new QDial(InputSystem);
        vol->setObjectName(QString::fromUtf8("vol"));
        vol->setMaximumSize(QSize(70, 70));
        vol->setMinimum(-1);
        vol->setMaximum(100);
        vol->setValue(100);

        verticalLayout_2->addWidget(vol);

        pmicoff = new QLabel(InputSystem);
        pmicoff->setObjectName(QString::fromUtf8("pmicoff"));
        pmicoff->setMaximumSize(QSize(50, 50));
        pmicoff->setPixmap(QPixmap(QString::fromUtf8(":/images/micoff.png")));
        pmicoff->setScaledContents(true);

        verticalLayout_2->addWidget(pmicoff);

        pmicon = new QLabel(InputSystem);
        pmicon->setObjectName(QString::fromUtf8("pmicon"));
        pmicon->setMaximumSize(QSize(50, 50));
        pmicon->setPixmap(QPixmap(QString::fromUtf8(":/images/micon.png")));
        pmicon->setScaledContents(true);

        verticalLayout_2->addWidget(pmicon);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        left = new QProgressBar(InputSystem);
        left->setObjectName(QString::fromUtf8("left"));
        left->setMinimumSize(QSize(0, 10));
        left->setMaximumSize(QSize(16777215, 5));
        left->setMaximum(32768);
        left->setValue(24);
        left->setTextVisible(false);

        verticalLayout->addWidget(left);

        right = new QProgressBar(InputSystem);
        right->setObjectName(QString::fromUtf8("right"));
        right->setMinimumSize(QSize(0, 10));
        right->setMaximumSize(QSize(16777215, 5));
        right->setMaximum(32768);
        right->setValue(24);
        right->setTextVisible(false);

        verticalLayout->addWidget(right);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        micon = new QPushButton(InputSystem);
        micon->setObjectName(QString::fromUtf8("micon"));

        horizontalLayout_2->addWidget(micon);

        micoff = new QPushButton(InputSystem);
        micoff->setObjectName(QString::fromUtf8("micoff"));

        horizontalLayout_2->addWidget(micoff);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(InputSystem);

        QMetaObject::connectSlotsByName(InputSystem);
    } // setupUi

    void retranslateUi(QWidget *InputSystem)
    {
        InputSystem->setWindowTitle(QApplication::translate("InputSystem", "Input", 0, QApplication::UnicodeUTF8));
        pmicoff->setText(QString());
        pmicon->setText(QString());
        micon->setText(QApplication::translate("InputSystem", "Microphone On", 0, QApplication::UnicodeUTF8));
        micoff->setText(QApplication::translate("InputSystem", "Microphone Off", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InputSystem: public Ui_InputSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTSYSTEM_H
