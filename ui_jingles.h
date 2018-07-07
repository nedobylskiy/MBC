/********************************************************************************
** Form generated from reading UI file 'jingles.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JINGLES_H
#define UI_JINGLES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jingles
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QRadioButton *rand;
    QRadioButton *byo;
    QLabel *label;
    QSpinBox *every;
    QCheckBox *act1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addj;
    QPushButton *djin;
    QListWidget *jinglist1;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *act2;
    QHBoxLayout *horizontalLayout;
    QPushButton *add2;
    QPushButton *del2;
    QTreeWidget *jin2list;

    void setupUi(QWidget *Jingles)
    {
        if (Jingles->objectName().isEmpty())
            Jingles->setObjectName(QString::fromUtf8("Jingles"));
        Jingles->resize(374, 360);
        verticalLayout_2 = new QVBoxLayout(Jingles);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(Jingles);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        rand = new QRadioButton(groupBox);
        rand->setObjectName(QString::fromUtf8("rand"));
        rand->setChecked(true);

        formLayout->setWidget(1, QFormLayout::LabelRole, rand);

        byo = new QRadioButton(groupBox);
        byo->setObjectName(QString::fromUtf8("byo"));
        byo->setChecked(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, byo);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        every = new QSpinBox(groupBox);
        every->setObjectName(QString::fromUtf8("every"));
        every->setMinimum(1);
        every->setValue(4);

        formLayout->setWidget(3, QFormLayout::FieldRole, every);

        act1 = new QCheckBox(groupBox);
        act1->setObjectName(QString::fromUtf8("act1"));
        act1->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, act1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addj = new QPushButton(tab);
        addj->setObjectName(QString::fromUtf8("addj"));

        horizontalLayout_3->addWidget(addj);

        djin = new QPushButton(tab);
        djin->setObjectName(QString::fromUtf8("djin"));

        horizontalLayout_3->addWidget(djin);


        verticalLayout->addLayout(horizontalLayout_3);

        jinglist1 = new QListWidget(tab);
        jinglist1->setObjectName(QString::fromUtf8("jinglist1"));
        jinglist1->setDragDropMode(QAbstractItemView::InternalMove);
        jinglist1->setSelectionMode(QAbstractItemView::ExtendedSelection);
        jinglist1->setMovement(QListView::Snap);

        verticalLayout->addWidget(jinglist1);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 6);
        act2 = new QCheckBox(groupBox_2);
        act2->setObjectName(QString::fromUtf8("act2"));
        act2->setChecked(true);

        verticalLayout_4->addWidget(act2);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add2 = new QPushButton(tab_2);
        add2->setObjectName(QString::fromUtf8("add2"));

        horizontalLayout->addWidget(add2);

        del2 = new QPushButton(tab_2);
        del2->setObjectName(QString::fromUtf8("del2"));

        horizontalLayout->addWidget(del2);


        verticalLayout_3->addLayout(horizontalLayout);

        jin2list = new QTreeWidget(tab_2);
        jin2list->setObjectName(QString::fromUtf8("jin2list"));

        verticalLayout_3->addWidget(jin2list);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(Jingles);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Jingles);
    } // setupUi

    void retranslateUi(QWidget *Jingles)
    {
        Jingles->setWindowTitle(QApplication::translate("Jingles", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Jingles", "Jingle Patams", 0, QApplication::UnicodeUTF8));
        rand->setText(QApplication::translate("Jingles", "Random Jingle", 0, QApplication::UnicodeUTF8));
        byo->setText(QApplication::translate("Jingles", "By order", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Jingles", "Run track every X tracks:", 0, QApplication::UnicodeUTF8));
        act1->setText(QApplication::translate("Jingles", "Activate Playlist Jingles", 0, QApplication::UnicodeUTF8));
        addj->setText(QApplication::translate("Jingles", "Add Jingle", 0, QApplication::UnicodeUTF8));
        djin->setText(QApplication::translate("Jingles", "Remove Selected", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Jingles", "Playlist Jingles", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Jingles", "Jingle Patams", 0, QApplication::UnicodeUTF8));
        act2->setText(QApplication::translate("Jingles", "Activate Autonomous Jingles", 0, QApplication::UnicodeUTF8));
        add2->setText(QApplication::translate("Jingles", "Add Jingle", 0, QApplication::UnicodeUTF8));
        del2->setText(QApplication::translate("Jingles", "Delete Selected", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = jin2list->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("Jingles", "Path", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Jingles", "Condition", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Jingles", "Autonomous Jingles", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Jingles: public Ui_Jingles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JINGLES_H
