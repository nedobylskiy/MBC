/********************************************************************************
** Form generated from reading UI file 'djpanel.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DJPANEL_H
#define UI_DJPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DJPanel
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *Silencer;
    QHBoxLayout *horizontalLayout;
    QCheckBox *silence;
    QLabel *label;
    QSlider *svol;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *rndlist;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *mic;
    QCheckBox *aut;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *Samples;
    QVBoxLayout *Sampless;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *textEdit;

    void setupUi(QWidget *DJPanel)
    {
        if (DJPanel->objectName().isEmpty())
            DJPanel->setObjectName(QString::fromUtf8("DJPanel"));
        DJPanel->resize(529, 273);
        verticalLayout = new QVBoxLayout(DJPanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(DJPanel);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 529, 273));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        Silencer = new QGroupBox(scrollAreaWidgetContents);
        Silencer->setObjectName(QString::fromUtf8("Silencer"));
        horizontalLayout = new QHBoxLayout(Silencer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        silence = new QCheckBox(Silencer);
        silence->setObjectName(QString::fromUtf8("silence"));

        horizontalLayout->addWidget(silence);

        label = new QLabel(Silencer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/volume.png")));

        horizontalLayout->addWidget(label);

        svol = new QSlider(Silencer);
        svol->setObjectName(QString::fromUtf8("svol"));
        svol->setMaximum(100);
        svol->setPageStep(1);
        svol->setValue(15);
        svol->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(svol);


        verticalLayout_6->addWidget(Silencer);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rndlist = new QCheckBox(groupBox);
        rndlist->setObjectName(QString::fromUtf8("rndlist"));
        rndlist->setChecked(true);

        horizontalLayout_4->addWidget(rndlist);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        mic = new QCheckBox(groupBox);
        mic->setObjectName(QString::fromUtf8("mic"));

        horizontalLayout_2->addWidget(mic);

        aut = new QCheckBox(groupBox);
        aut->setObjectName(QString::fromUtf8("aut"));
        aut->setChecked(true);
        aut->setTristate(false);

        horizontalLayout_2->addWidget(aut);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addWidget(groupBox);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        Samples = new QGroupBox(scrollAreaWidgetContents);
        Samples->setObjectName(QString::fromUtf8("Samples"));
        Sampless = new QVBoxLayout(Samples);
        Sampless->setSpacing(0);
        Sampless->setContentsMargins(0, 0, 0, 0);
        Sampless->setObjectName(QString::fromUtf8("Sampless"));

        verticalLayout_4->addWidget(Samples);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 6, 6, 6);
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_7->addWidget(textEdit);


        verticalLayout_4->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(DJPanel);

        QMetaObject::connectSlotsByName(DJPanel);
    } // setupUi

    void retranslateUi(QWidget *DJPanel)
    {
        DJPanel->setWindowTitle(QApplication::translate("DJPanel", "Form", 0, QApplication::UnicodeUTF8));
        Silencer->setTitle(QApplication::translate("DJPanel", "Silencer", 0, QApplication::UnicodeUTF8));
        silence->setText(QApplication::translate("DJPanel", "Silence", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("DJPanel", "Other", 0, QApplication::UnicodeUTF8));
        rndlist->setText(QApplication::translate("DJPanel", "Auto Playlist Generation (Randomize)", 0, QApplication::UnicodeUTF8));
        mic->setText(QApplication::translate("DJPanel", "Activate Microphone", 0, QApplication::UnicodeUTF8));
        aut->setText(QApplication::translate("DJPanel", "Silence on activate", 0, QApplication::UnicodeUTF8));
        Samples->setTitle(QApplication::translate("DJPanel", "Samples", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DJPanel", "Notepad", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DJPanel: public Ui_DJPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DJPANEL_H
