/********************************************************************************
** Form generated from reading UI file 'playlist.ui'
**
** Created: Sat 13. Apr 15:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLIST_H
#define UI_PLAYLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayList
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *PlayList)
    {
        if (PlayList->objectName().isEmpty())
            PlayList->setObjectName(QString::fromUtf8("PlayList"));
        PlayList->resize(424, 244);
        PlayList->setMinimumSize(QSize(424, 244));
        horizontalLayout = new QHBoxLayout(PlayList);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PlayList);

        QMetaObject::connectSlotsByName(PlayList);
    } // setupUi

    void retranslateUi(QWidget *PlayList)
    {
        PlayList->setWindowTitle(QApplication::translate("PlayList", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PlayList: public Ui_PlayList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLIST_H
