/********************************************************************************
** Form generated from reading UI file 'encoderslist.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODERSLIST_H
#define UI_ENCODERSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncodersList
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QToolBox *encoders;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddEncoder;
    QPushButton *DeleteEncoder;
    QPushButton *sall;
    QPushButton *stall;

    void setupUi(QWidget *EncodersList)
    {
        if (EncodersList->objectName().isEmpty())
            EncodersList->setObjectName(QString::fromUtf8("EncodersList"));
        EncodersList->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(EncodersList);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(EncodersList);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 383, 267));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        encoders = new QToolBox(scrollAreaWidgetContents);
        encoders->setObjectName(QString::fromUtf8("encoders"));
        encoders->setFrameShape(QFrame::WinPanel);
        encoders->setFrameShadow(QFrame::Raised);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 379, 234));
        encoders->addItem(page_2, QString::fromUtf8("Page 2"));

        verticalLayout_3->addWidget(encoders);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AddEncoder = new QPushButton(EncodersList);
        AddEncoder->setObjectName(QString::fromUtf8("AddEncoder"));

        horizontalLayout->addWidget(AddEncoder);

        DeleteEncoder = new QPushButton(EncodersList);
        DeleteEncoder->setObjectName(QString::fromUtf8("DeleteEncoder"));

        horizontalLayout->addWidget(DeleteEncoder);

        sall = new QPushButton(EncodersList);
        sall->setObjectName(QString::fromUtf8("sall"));

        horizontalLayout->addWidget(sall);

        stall = new QPushButton(EncodersList);
        stall->setObjectName(QString::fromUtf8("stall"));

        horizontalLayout->addWidget(stall);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(EncodersList);

        encoders->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EncodersList);
    } // setupUi

    void retranslateUi(QWidget *EncodersList)
    {
        EncodersList->setWindowTitle(QApplication::translate("EncodersList", "Form", 0, QApplication::UnicodeUTF8));
        encoders->setItemText(encoders->indexOf(page_2), QApplication::translate("EncodersList", "Page 2", 0, QApplication::UnicodeUTF8));
        AddEncoder->setText(QApplication::translate("EncodersList", "Add Encoder", 0, QApplication::UnicodeUTF8));
        DeleteEncoder->setText(QApplication::translate("EncodersList", "Delete Last Encoder", 0, QApplication::UnicodeUTF8));
        sall->setText(QApplication::translate("EncodersList", "Start All", 0, QApplication::UnicodeUTF8));
        stall->setText(QApplication::translate("EncodersList", "Stop All", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EncodersList: public Ui_EncodersList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODERSLIST_H
