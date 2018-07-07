/********************************************************************************
** Form generated from reading UI file 'sample.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLE_H
#define UI_SAMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sample
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *play;
    QPushButton *browse;

    void setupUi(QWidget *Sample)
    {
        if (Sample->objectName().isEmpty())
            Sample->setObjectName(QString::fromUtf8("Sample"));
        Sample->resize(133, 26);
        horizontalLayout = new QHBoxLayout(Sample);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        play = new QPushButton(Sample);
        play->setObjectName(QString::fromUtf8("play"));
        play->setMaximumSize(QSize(3000, 26));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/playing.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon);
        play->setIconSize(QSize(48, 48));

        horizontalLayout->addWidget(play);

        browse = new QPushButton(Sample);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setMaximumSize(QSize(67, 26));

        horizontalLayout->addWidget(browse);


        retranslateUi(Sample);

        QMetaObject::connectSlotsByName(Sample);
    } // setupUi

    void retranslateUi(QWidget *Sample)
    {
        Sample->setWindowTitle(QApplication::translate("Sample", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        play->setToolTip(QApplication::translate("Sample", "Play Sample", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        play->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        play->setText(QString());
#ifndef QT_NO_TOOLTIP
        browse->setToolTip(QApplication::translate("Sample", "Browse for sample", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        browse->setText(QApplication::translate("Sample", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sample: public Ui_Sample {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLE_H
