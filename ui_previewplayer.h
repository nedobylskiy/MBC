/********************************************************************************
** Form generated from reading UI file 'previewplayer.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWPLAYER_H
#define UI_PREVIEWPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreViewPlayer
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *vol;
    QLabel *buff;
    QSlider *position;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *hide;

    void setupUi(QWidget *PreViewPlayer)
    {
        if (PreViewPlayer->objectName().isEmpty())
            PreViewPlayer->setObjectName(QString::fromUtf8("PreViewPlayer"));
        PreViewPlayer->resize(400, 25);
        horizontalLayout = new QHBoxLayout(PreViewPlayer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(PreViewPlayer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/volume.png")));

        horizontalLayout->addWidget(label);

        vol = new QSlider(PreViewPlayer);
        vol->setObjectName(QString::fromUtf8("vol"));
        vol->setMaximumSize(QSize(100, 16777215));
        vol->setMaximum(100);
        vol->setValue(100);
        vol->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(vol);

        buff = new QLabel(PreViewPlayer);
        buff->setObjectName(QString::fromUtf8("buff"));

        horizontalLayout->addWidget(buff);

        position = new QSlider(PreViewPlayer);
        position->setObjectName(QString::fromUtf8("position"));
        position->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(position);

        play = new QPushButton(PreViewPlayer);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/playing.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon);
        play->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(play);

        stop = new QPushButton(PreViewPlayer);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/stopped.png"), QSize(), QIcon::Normal, QIcon::Off);
        stop->setIcon(icon1);

        horizontalLayout->addWidget(stop);

        hide = new QPushButton(PreViewPlayer);
        hide->setObjectName(QString::fromUtf8("hide"));
        hide->setMaximumSize(QSize(32, 32));
        QFont font;
        font.setPointSize(14);
        hide->setFont(font);

        horizontalLayout->addWidget(hide);


        retranslateUi(PreViewPlayer);

        QMetaObject::connectSlotsByName(PreViewPlayer);
    } // setupUi

    void retranslateUi(QWidget *PreViewPlayer)
    {
        PreViewPlayer->setWindowTitle(QApplication::translate("PreViewPlayer", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        buff->setText(QApplication::translate("PreViewPlayer", "Buffering...", 0, QApplication::UnicodeUTF8));
        play->setText(QString());
        stop->setText(QString());
        hide->setText(QApplication::translate("PreViewPlayer", "X", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreViewPlayer: public Ui_PreViewPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWPLAYER_H
