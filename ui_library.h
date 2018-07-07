/********************************************************************************
** Form generated from reading UI file 'library.ui'
**
** Created: Sat 13. Apr 15:45:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Library
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *folderbut;
    QPushButton *filebut;
    QPushButton *addurl;
    QPushButton *searchbut;
    QLineEdit *searchf;

    void setupUi(QWidget *Library)
    {
        if (Library->objectName().isEmpty())
            Library->setObjectName(QString::fromUtf8("Library"));
        Library->resize(440, 322);
        Library->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(Library);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        folderbut = new QPushButton(Library);
        folderbut->setObjectName(QString::fromUtf8("folderbut"));

        horizontalLayout->addWidget(folderbut);

        filebut = new QPushButton(Library);
        filebut->setObjectName(QString::fromUtf8("filebut"));

        horizontalLayout->addWidget(filebut);

        addurl = new QPushButton(Library);
        addurl->setObjectName(QString::fromUtf8("addurl"));

        horizontalLayout->addWidget(addurl);

        searchbut = new QPushButton(Library);
        searchbut->setObjectName(QString::fromUtf8("searchbut"));

        horizontalLayout->addWidget(searchbut);


        verticalLayout->addLayout(horizontalLayout);

        searchf = new QLineEdit(Library);
        searchf->setObjectName(QString::fromUtf8("searchf"));
        searchf->setAutoFillBackground(false);

        verticalLayout->addWidget(searchf);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Library);

        QMetaObject::connectSlotsByName(Library);
    } // setupUi

    void retranslateUi(QWidget *Library)
    {
        Library->setWindowTitle(QApplication::translate("Library", "Form", 0, QApplication::UnicodeUTF8));
        folderbut->setText(QApplication::translate("Library", "Add Folder", 0, QApplication::UnicodeUTF8));
        filebut->setText(QApplication::translate("Library", "Add Files", 0, QApplication::UnicodeUTF8));
        addurl->setText(QApplication::translate("Library", "Add Url", 0, QApplication::UnicodeUTF8));
        searchbut->setText(QApplication::translate("Library", "Search", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Library: public Ui_Library {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARY_H
