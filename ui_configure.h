/********************************************************************************
** Form generated from reading UI file 'configure.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURE_H
#define UI_CONFIGURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Configure
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QSpinBox *tt;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QSpinBox *st;
    QLabel *label_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *t1;
    QRadioButton *t2;
    QRadioButton *t3;
    QRadioButton *t4;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveb;
    QPushButton *reset;

    void setupUi(QWidget *Configure)
    {
        if (Configure->objectName().isEmpty())
            Configure->setObjectName(QString::fromUtf8("Configure"));
        Configure->resize(416, 221);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Configure->sizePolicy().hasHeightForWidth());
        Configure->setSizePolicy(sizePolicy);
        Configure->setMaximumSize(QSize(160000, 160000));
        verticalLayout = new QVBoxLayout(Configure);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(Configure);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -191, 382, 394));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        tt = new QSpinBox(tab_2);
        tt->setObjectName(QString::fromUtf8("tt"));
        tt->setMaximum(10000);
        tt->setValue(3000);

        verticalLayout_3->addWidget(tt);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        st = new QSpinBox(tab_2);
        st->setObjectName(QString::fromUtf8("st"));
        st->setMaximum(10);
        st->setValue(4);

        verticalLayout_5->addWidget(st);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);


        verticalLayout_4->addLayout(verticalLayout_5);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        t1 = new QRadioButton(groupBox);
        t1->setObjectName(QString::fromUtf8("t1"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/fade1.png"), QSize(), QIcon::Normal, QIcon::Off);
        t1->setIcon(icon);
        t1->setIconSize(QSize(300, 30));

        verticalLayout_6->addWidget(t1);

        t2 = new QRadioButton(groupBox);
        t2->setObjectName(QString::fromUtf8("t2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/fade2.png"), QSize(), QIcon::Normal, QIcon::Off);
        t2->setIcon(icon1);
        t2->setIconSize(QSize(300, 30));

        verticalLayout_6->addWidget(t2);

        t3 = new QRadioButton(groupBox);
        t3->setObjectName(QString::fromUtf8("t3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/fade3.png"), QSize(), QIcon::Normal, QIcon::Off);
        t3->setIcon(icon2);
        t3->setIconSize(QSize(300, 30));
        t3->setChecked(false);

        verticalLayout_6->addWidget(t3);

        t4 = new QRadioButton(groupBox);
        t4->setObjectName(QString::fromUtf8("t4"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/fade4.png"), QSize(), QIcon::Normal, QIcon::Off);
        t4->setIcon(icon3);
        t4->setIconSize(QSize(300, 30));
        t4->setChecked(true);

        verticalLayout_6->addWidget(t4);


        verticalLayout_4->addWidget(groupBox);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveb = new QPushButton(scrollAreaWidgetContents);
        saveb->setObjectName(QString::fromUtf8("saveb"));

        horizontalLayout->addWidget(saveb);

        reset = new QPushButton(scrollAreaWidgetContents);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);


        verticalLayout_2->addLayout(horizontalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(Configure);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Configure);
    } // setupUi

    void retranslateUi(QWidget *Configure)
    {
        Configure->setWindowTitle(QApplication::translate("Configure", "Form", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Configure", "Main", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Configure", "Time in milliseconds for transition:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Configure", "Start transition in ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Configure", "second before track end.", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Configure", "Transition type", 0, QApplication::UnicodeUTF8));
        t1->setText(QString());
        t2->setText(QString());
        t3->setText(QString());
        t4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Configure", "Transitions", 0, QApplication::UnicodeUTF8));
        saveb->setText(QApplication::translate("Configure", "Save", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("Configure", "Load again", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Configure: public Ui_Configure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURE_H
