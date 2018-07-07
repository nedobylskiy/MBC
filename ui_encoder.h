/********************************************************************************
** Form generated from reading UI file 'encoder.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODER_H
#define UI_ENCODER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Encoder
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *lame;
    QRadioButton *aac;
    QRadioButton *customr;
    QLineEdit *custom;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *server;
    QLabel *label_2;
    QLineEdit *pass;
    QLabel *label_3;
    QLineEdit *name;
    QLabel *label_4;
    QLineEdit *url;
    QLabel *label_5;
    QLineEdit *genre;
    QLabel *label_6;
    QLineEdit *descr;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QSlider *quas;
    QLabel *qua;
    QPushButton *StartEncoder;
    QPushButton *StopEncoder;

    void setupUi(QWidget *Encoder)
    {
        if (Encoder->objectName().isEmpty())
            Encoder->setObjectName(QString::fromUtf8("Encoder"));
        Encoder->resize(397, 559);
        Encoder->setMinimumSize(QSize(397, 559));
        verticalLayout = new QVBoxLayout(Encoder);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Encoder);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(396, 549));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 395, 557));
        scrollAreaWidgetContents->setMinimumSize(QSize(394, 547));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, 9, 0);
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(377, 184));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lame = new QRadioButton(groupBox);
        lame->setObjectName(QString::fromUtf8("lame"));
        lame->setChecked(true);

        verticalLayout_3->addWidget(lame);

        aac = new QRadioButton(groupBox);
        aac->setObjectName(QString::fromUtf8("aac"));

        verticalLayout_3->addWidget(aac);

        customr = new QRadioButton(groupBox);
        customr->setObjectName(QString::fromUtf8("customr"));

        verticalLayout_3->addWidget(customr);

        custom = new QLineEdit(groupBox);
        custom->setObjectName(QString::fromUtf8("custom"));

        verticalLayout_3->addWidget(custom);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(377, 319));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 3);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        server = new QLineEdit(groupBox_2);
        server->setObjectName(QString::fromUtf8("server"));

        verticalLayout_4->addWidget(server);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        pass = new QLineEdit(groupBox_2);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_4->addWidget(pass);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        name = new QLineEdit(groupBox_2);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout_4->addWidget(name);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        url = new QLineEdit(groupBox_2);
        url->setObjectName(QString::fromUtf8("url"));

        verticalLayout_4->addWidget(url);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        genre = new QLineEdit(groupBox_2);
        genre->setObjectName(QString::fromUtf8("genre"));

        verticalLayout_4->addWidget(genre);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        descr = new QLineEdit(groupBox_2);
        descr->setObjectName(QString::fromUtf8("descr"));

        verticalLayout_4->addWidget(descr);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_4->addWidget(label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        quas = new QSlider(groupBox_2);
        quas->setObjectName(QString::fromUtf8("quas"));
        quas->setMinimum(8);
        quas->setMaximum(320);
        quas->setSingleStep(8);
        quas->setValue(128);
        quas->setOrientation(Qt::Horizontal);
        quas->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(quas);

        qua = new QLabel(groupBox_2);
        qua->setObjectName(QString::fromUtf8("qua"));

        horizontalLayout->addWidget(qua);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox_2);

        StartEncoder = new QPushButton(scrollAreaWidgetContents);
        StartEncoder->setObjectName(QString::fromUtf8("StartEncoder"));

        verticalLayout_2->addWidget(StartEncoder);

        StopEncoder = new QPushButton(scrollAreaWidgetContents);
        StopEncoder->setObjectName(QString::fromUtf8("StopEncoder"));

        verticalLayout_2->addWidget(StopEncoder);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Encoder);

        QMetaObject::connectSlotsByName(Encoder);
    } // setupUi

    void retranslateUi(QWidget *Encoder)
    {
        Encoder->setWindowTitle(QApplication::translate("Encoder", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Encoder", "Cast Encoder", 0, QApplication::UnicodeUTF8));
        lame->setText(QApplication::translate("Encoder", "LAME (MP3)", 0, QApplication::UnicodeUTF8));
        aac->setText(QApplication::translate("Encoder", "AAC (FAAC)", 0, QApplication::UnicodeUTF8));
        customr->setText(QApplication::translate("Encoder", "Custom:", 0, QApplication::UnicodeUTF8));
        custom->setText(QApplication::translate("Encoder", "lame -r -s 44100 -b %i -", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Encoder", "Cast Config", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Encoder", "Mountpoint/Server:", 0, QApplication::UnicodeUTF8));
        server->setText(QApplication::translate("Encoder", "listen.superb-radio:8000/mount", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Encoder", "Password:", 0, QApplication::UnicodeUTF8));
        pass->setText(QApplication::translate("Encoder", "password", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Encoder", "Station Name:", 0, QApplication::UnicodeUTF8));
        name->setText(QApplication::translate("Encoder", "Superb Radio", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Encoder", "Station URL:", 0, QApplication::UnicodeUTF8));
        url->setText(QApplication::translate("Encoder", "http://example.org", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Encoder", "Genre:", 0, QApplication::UnicodeUTF8));
        genre->setText(QApplication::translate("Encoder", "Generic", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Encoder", "Description:", 0, QApplication::UnicodeUTF8));
        descr->setText(QApplication::translate("Encoder", "Superb Station", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Encoder", "Quality (Kb/sec):", 0, QApplication::UnicodeUTF8));
        qua->setText(QApplication::translate("Encoder", "128", 0, QApplication::UnicodeUTF8));
        StartEncoder->setText(QApplication::translate("Encoder", "Start", 0, QApplication::UnicodeUTF8));
        StopEncoder->setText(QApplication::translate("Encoder", "Stop", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Encoder: public Ui_Encoder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODER_H
