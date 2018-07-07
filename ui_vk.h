/********************************************************************************
** Form generated from reading UI file 'vk.ui'
**
** Created: Sat 13. Apr 15:45:46 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VK_H
#define UI_VK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_VK
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *browser;
    QVBoxLayout *verticalLayout_3;
    QWebView *webView;
    QHBoxLayout *horizontalLayout;
    QPushButton *auth;
    QPushButton *vkb;
    QWidget *srch;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *layout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *search;
    QPushButton *sbutton;
    QLabel *loading;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *add;
    QGroupBox *additional;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *uid;
    QLabel *label_3;
    QLineEdit *gid;
    QVBoxLayout *library;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *token;

    void setupUi(QWidget *VK)
    {
        if (VK->objectName().isEmpty())
            VK->setObjectName(QString::fromUtf8("VK"));
        VK->resize(400, 202);
        verticalLayout = new QVBoxLayout(VK);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(VK);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 396, 198));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(scrollAreaWidgetContents);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::North);
        browser = new QWidget();
        browser->setObjectName(QString::fromUtf8("browser"));
        verticalLayout_3 = new QVBoxLayout(browser);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        webView = new QWebView(browser);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("https://oauth.vk.com/authorize?client_id=2428502&scope=5128&redirect_uri=http://api.vk.com/blank.html&display=page&response_type=token")));
        webView->setZoomFactor(0.9);

        verticalLayout_3->addWidget(webView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        auth = new QPushButton(browser);
        auth->setObjectName(QString::fromUtf8("auth"));

        horizontalLayout->addWidget(auth);

        vkb = new QPushButton(browser);
        vkb->setObjectName(QString::fromUtf8("vkb"));

        horizontalLayout->addWidget(vkb);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget->addTab(browser, QString());
        srch = new QWidget();
        srch->setObjectName(QString::fromUtf8("srch"));
        verticalLayout_5 = new QVBoxLayout(srch);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        layout = new QHBoxLayout();
        layout->setObjectName(QString::fromUtf8("layout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        search = new QLineEdit(srch);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout_3->addWidget(search);

        sbutton = new QPushButton(srch);
        sbutton->setObjectName(QString::fromUtf8("sbutton"));

        horizontalLayout_3->addWidget(sbutton);

        loading = new QLabel(srch);
        loading->setObjectName(QString::fromUtf8("loading"));
        loading->setPixmap(QPixmap(QString::fromUtf8(":/images/loading.png")));
        loading->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(loading);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        add = new QCheckBox(srch);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_4->addWidget(add);


        verticalLayout_6->addLayout(horizontalLayout_4);

        additional = new QGroupBox(srch);
        additional->setObjectName(QString::fromUtf8("additional"));
        horizontalLayout_5 = new QHBoxLayout(additional);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(additional);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        uid = new QLineEdit(additional);
        uid->setObjectName(QString::fromUtf8("uid"));

        horizontalLayout_5->addWidget(uid);

        label_3 = new QLabel(additional);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        gid = new QLineEdit(additional);
        gid->setObjectName(QString::fromUtf8("gid"));

        horizontalLayout_5->addWidget(gid);


        verticalLayout_6->addWidget(additional);


        layout->addLayout(verticalLayout_6);


        verticalLayout_5->addLayout(layout);

        library = new QVBoxLayout();
        library->setObjectName(QString::fromUtf8("library"));

        verticalLayout_5->addLayout(library);

        tabWidget->addTab(srch, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_4->addWidget(label);

        token = new QLabel(tab);
        token->setObjectName(QString::fromUtf8("token"));

        verticalLayout_4->addWidget(token);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(VK);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(VK);
    } // setupUi

    void retranslateUi(QWidget *VK)
    {
        VK->setWindowTitle(QApplication::translate("VK", "Form", 0, QApplication::UnicodeUTF8));
        auth->setText(QApplication::translate("VK", "ReAuthorize", 0, QApplication::UnicodeUTF8));
        vkb->setText(QApplication::translate("VK", "VK.com", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(browser), QApplication::translate("VK", "VK.com browser", 0, QApplication::UnicodeUTF8));
        sbutton->setText(QApplication::translate("VK", "Search", 0, QApplication::UnicodeUTF8));
        loading->setText(QString());
        add->setText(QApplication::translate("VK", "Use additional fields", 0, QApplication::UnicodeUTF8));
        additional->setTitle(QApplication::translate("VK", "Additional", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VK", "User ID:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VK", "Group ID:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(srch), QApplication::translate("VK", "Search", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VK", "Auth token:", 0, QApplication::UnicodeUTF8));
        token->setText(QApplication::translate("VK", "000", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("VK", "Auth Info", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VK: public Ui_VK {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VK_H
