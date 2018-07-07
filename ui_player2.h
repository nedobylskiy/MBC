/********************************************************************************
** Form generated from reading UI file 'player2.ui'
**
** Created: Sat 13. Apr 15:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER2_H
#define UI_PLAYER2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Player2
{
public:
    QLabel *Name;
    QProgressBar *v1;
    QProgressBar *v2;
    QLabel *Time;
    QSlider *trackPos;
    QSlider *volume;
    QLabel *label;
    QLabel *web;
    QGroupBox *title;
    QFrame *frame;
    QLabel *cpu;
    QLabel *playing;
    QLabel *stopped;

    void setupUi(QDialog *Player2)
    {
        if (Player2->objectName().isEmpty())
            Player2->setObjectName(QString::fromUtf8("Player2"));
        Player2->resize(210, 200);
        Player2->setMinimumSize(QSize(210, 189));
        Player2->setMaximumSize(QSize(210, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/player.png"), QSize(), QIcon::Normal, QIcon::Off);
        Player2->setWindowIcon(icon);
        Player2->setWindowOpacity(1);
        Player2->setSizeGripEnabled(false);
        Name = new QLabel(Player2);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(10, 10, 191, 91));
        Name->setAlignment(Qt::AlignCenter);
        Name->setWordWrap(true);
        v1 = new QProgressBar(Player2);
        v1->setObjectName(QString::fromUtf8("v1"));
        v1->setGeometry(QRect(3, 175, 201, 10));
        v1->setMaximumSize(QSize(16777215, 10));
        v1->setMaximum(32769);
        v1->setValue(0);
        v1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        v1->setTextVisible(false);
        v1->setOrientation(Qt::Horizontal);
        v2 = new QProgressBar(Player2);
        v2->setObjectName(QString::fromUtf8("v2"));
        v2->setGeometry(QRect(3, 186, 201, 10));
        v2->setMaximumSize(QSize(16777215, 10));
        v2->setMaximum(32768);
        v2->setValue(24);
        v2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        v2->setTextVisible(false);
        v2->setOrientation(Qt::Horizontal);
        Time = new QLabel(Player2);
        Time->setObjectName(QString::fromUtf8("Time"));
        Time->setGeometry(QRect(10, 130, 191, 20));
        Time->setTextFormat(Qt::PlainText);
        Time->setAlignment(Qt::AlignCenter);
        trackPos = new QSlider(Player2);
        trackPos->setObjectName(QString::fromUtf8("trackPos"));
        trackPos->setGeometry(QRect(3, 105, 201, 25));
        trackPos->setValue(24);
        trackPos->setTracking(true);
        trackPos->setOrientation(Qt::Horizontal);
        trackPos->setInvertedAppearance(false);
        trackPos->setInvertedControls(true);
        trackPos->setTickPosition(QSlider::TicksBothSides);
        trackPos->setTickInterval(30);
        volume = new QSlider(Player2);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(22, 150, 181, 25));
        volume->setMinimum(-2);
        volume->setMaximum(100);
        volume->setOrientation(Qt::Horizontal);
        volume->setTickPosition(QSlider::NoTicks);
        label = new QLabel(Player2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 155, 16, 16));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/volume.png")));
        web = new QLabel(Player2);
        web->setObjectName(QString::fromUtf8("web"));
        web->setGeometry(QRect(94, 143, 21, 16));
        title = new QGroupBox(Player2);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(0, 0, 210, 201));
        title->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        frame = new QFrame(title);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 210, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cpu = new QLabel(Player2);
        cpu->setObjectName(QString::fromUtf8("cpu"));
        cpu->setGeometry(QRect(10, 140, 41, 16));
        playing = new QLabel(Player2);
        playing->setObjectName(QString::fromUtf8("playing"));
        playing->setGeometry(QRect(165, 17, 31, 21));
        playing->setPixmap(QPixmap(QString::fromUtf8(":/images/playing.png")));
        stopped = new QLabel(Player2);
        stopped->setObjectName(QString::fromUtf8("stopped"));
        stopped->setGeometry(QRect(180, 17, 16, 16));
        stopped->setPixmap(QPixmap(QString::fromUtf8(":/images/stopped.png")));
        title->raise();
        Name->raise();
        v1->raise();
        v2->raise();
        Time->raise();
        trackPos->raise();
        volume->raise();
        label->raise();
        web->raise();
        cpu->raise();
        playing->raise();
        stopped->raise();

        retranslateUi(Player2);

        QMetaObject::connectSlotsByName(Player2);
    } // setupUi

    void retranslateUi(QDialog *Player2)
    {
        Player2->setWindowTitle(QApplication::translate("Player2", "Player", 0, QApplication::UnicodeUTF8));
        Name->setText(QApplication::translate("Player2", "<html><head/><body><p align=\"center\">Track Name Label</p></body></html>", 0, QApplication::UnicodeUTF8));
        Time->setText(QApplication::translate("Player2", "00:00/00:00", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        web->setText(QApplication::translate("Player2", "<html><head/><body><p><span style=\" font-size:6pt; color:#088bc3;\">Web</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        title->setTitle(QApplication::translate("Player2", "Player", 0, QApplication::UnicodeUTF8));
        cpu->setText(QApplication::translate("Player2", "<html><head/><body><p><span style=\" font-size:6pt;\">CPU:100%</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        playing->setText(QString());
        stopped->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Player2: public Ui_Player2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER2_H
