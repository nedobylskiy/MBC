/********************************************************************************
** Form generated from reading UI file 'playlisthistory.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTHISTORY_H
#define UI_PLAYLISTHISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistHistory
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *PlaylistHistory)
    {
        if (PlaylistHistory->objectName().isEmpty())
            PlaylistHistory->setObjectName(QString::fromUtf8("PlaylistHistory"));
        PlaylistHistory->resize(400, 300);
        horizontalLayout = new QHBoxLayout(PlaylistHistory);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PlaylistHistory);

        QMetaObject::connectSlotsByName(PlaylistHistory);
    } // setupUi

    void retranslateUi(QWidget *PlaylistHistory)
    {
        PlaylistHistory->setWindowTitle(QApplication::translate("PlaylistHistory", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlaylistHistory: public Ui_PlaylistHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTHISTORY_H
