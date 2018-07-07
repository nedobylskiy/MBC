/********************************************************************************
** Form generated from reading UI file 'wskype.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSKYPE_H
#define UI_WSKYPE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WSkype
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QCheckBox *rings;
    QCheckBox *sil;
    QCheckBox *mc;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *onair;
    QLabel *nonair;

    void setupUi(QWidget *WSkype)
    {
        if (WSkype->objectName().isEmpty())
            WSkype->setObjectName(QString::fromUtf8("WSkype"));
        WSkype->resize(487, 300);
        gridLayout = new QGridLayout(WSkype);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        rings = new QCheckBox(WSkype);
        rings->setObjectName(QString::fromUtf8("rings"));

        gridLayout_2->addWidget(rings, 0, 0, 1, 1);

        sil = new QCheckBox(WSkype);
        sil->setObjectName(QString::fromUtf8("sil"));
        sil->setChecked(true);

        gridLayout_2->addWidget(sil, 1, 0, 1, 1);

        mc = new QCheckBox(WSkype);
        mc->setObjectName(QString::fromUtf8("mc"));

        gridLayout_2->addWidget(mc, 2, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        onair = new QLabel(WSkype);
        onair->setObjectName(QString::fromUtf8("onair"));
        onair->setMinimumSize(QSize(128, 128));
        onair->setPixmap(QPixmap(QString::fromUtf8(":/images/onair.png")));

        horizontalLayout_2->addWidget(onair);

        nonair = new QLabel(WSkype);
        nonair->setObjectName(QString::fromUtf8("nonair"));
        nonair->setMinimumSize(QSize(128, 128));
        nonair->setPixmap(QPixmap(QString::fromUtf8(":/images/nonair.png")));

        horizontalLayout_2->addWidget(nonair);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        retranslateUi(WSkype);

        QMetaObject::connectSlotsByName(WSkype);
    } // setupUi

    void retranslateUi(QWidget *WSkype)
    {
        WSkype->setWindowTitle(QApplication::translate("WSkype", "Form", 0, QApplication::UnicodeUTF8));
        rings->setText(QApplication::translate("WSkype", "Redirect call to Air", 0, QApplication::UnicodeUTF8));
        sil->setText(QApplication::translate("WSkype", "Activate Auto Silencer", 0, QApplication::UnicodeUTF8));
        mc->setText(QApplication::translate("WSkype", "Mute Call", 0, QApplication::UnicodeUTF8));
        onair->setText(QString());
        nonair->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WSkype: public Ui_WSkype {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSKYPE_H
