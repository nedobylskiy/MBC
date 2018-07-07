#include "vk.h"
#include "ui_vk.h"
#include <QMessageBox>
#include <QUrl>
#include <QtNetwork>
#include <QFile>
#include <QDropEvent>
#include <QMenu>
#include <QDesktopServices>
#include "library.h"
#include "previewplayer.h"


VK::VK(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VK)
{
    ui->setupUi(this);


    //*********Настройка листа
        treeWidget = new TreeWidget();
        //treeWidget = new TreeWidget(Library);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setDragEnabled(false);
        treeWidget->setDragDropMode(QAbstractItemView::DragDrop);
        treeWidget->setDefaultDropAction(Qt::LinkAction);
        treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeWidget->setRootIsDecorated(false);
        treeWidget->setItemsExpandable(false);
        treeWidget->setExpandsOnDoubleClick(false);

        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->headerItem();
        ___qtreewidgetitem1->setText(4, QApplication::translate("Library", "Sec", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("Library", "Path", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("Library", "Duration", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("Library", "Name", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Library", "Start Time", 0, QApplication::UnicodeUTF8));

        treeWidget->setColumnWidth(0,0);
        treeWidget->setColumnWidth(1,300);
        treeWidget->setColumnWidth(2,80);
        treeWidget->setColumnWidth(4,0);
    //*********Настройка листа

 connect(treeWidget,SIGNAL(OnKeyPress(QKeyEvent*)),SLOT(OnTreeKeyPress(QKeyEvent*)));


        player = new PreViewPlayer();
        ui->library->addWidget(player);
        player->hide();

        ui->library->addWidget(treeWidget);

    connect(ui->webView,SIGNAL(urlChanged(QUrl)),SLOT(urllChanged(QUrl)));
    logined=false;



    ui->loading->hide();
    ui->additional->hide();

   // http = new QHttp("api.vkontakte.ru",QHttp::ConnectionModeHttps);
    //connect(http,SIGNAL(done(bool)),SLOT(reqFinished(bool)));


    connect(ui->sbutton,SIGNAL(clicked()),SLOT(SerFild()));

     connect(ui->auth,SIGNAL(clicked()),SLOT(AuthBut()));
 connect(ui->vkb,SIGNAL(clicked()),SLOT(VKBut()));
  connect(ui->add,SIGNAL(stateChanged(int)),SLOT(Additional()));
  connect(ui->search,SIGNAL(returnPressed()),SLOT(SerFild()));
    //http->setHost("api.vkontakte.ru");
   // http->get("/index.php");



  QAction *a;


  a = new QAction(tr("Download"), this);
  connect(a, SIGNAL(triggered()), this, SLOT(Download()));
  treeWidget->addAction(a);

  treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

}

VK::~VK()
{
    delete ui;
}


QString VK::Sec22TimeStr(int sec)
{
QString resulti;
int seconds = sec % 60;
int minutes = (sec - seconds) / 60;
//char TimeString[20];

if (seconds <10) resulti.sprintf( "%d:0%d", minutes,seconds);
else
resulti.sprintf( "%d:%d", minutes,seconds);

//resulti.append(TimeString);


return resulti;
}

void VK::Athorized()
{
  logined=true;
}




void VK::urllChanged(QUrl url)
{
    QString temp = url.toString();

    if(temp.contains("access_token"))
    {
    access_token = temp;
    access_token.remove(0,access_token.indexOf("#"));
    access_token.remove(access_token.indexOf("&"),access_token.length());
    access_token.remove(0,access_token.indexOf("=")+1);
    ui->token->setText(access_token);
    ui->webView->load(QUrl::fromUserInput("https://m.vk.com"));
    logined=true;
    Athorized();
    }
}

void VK::AddItem(QString name,QString path, int duration)
{
    QTreeWidgetItem *topLevelItem=new QTreeWidgetItem(treeWidget);
    topLevelItem->setText(0,"N/A");
    topLevelItem->setText(1,name);

    if(duration>0)
        topLevelItem->setText(2,Sec22TimeStr(duration));
    else
        topLevelItem->setText(2,"Radio");

    topLevelItem->setText(3,path);
    topLevelItem->setText(4,QString::number(duration));

    topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
    //topLevelItem->setFlags(topLevelItem->flags() & Qt::Item);
    treeWidget->addTopLevelItem(topLevelItem);

}

void VK::VKSearch(QString q)
{
//http->abort();

if(!ui->add->isChecked())
{
//http->get("/method/audio.search?access_token="+access_token+"&auto_complete=1&sort=2&count=200&q="+QUrl::toPercentEncoding(q));
}
else
{
//http->get("/method/audio.get?access_token="+access_token+"&gid="+ui->gid->text()+"&uid="+ui->uid->text()+"&q="+QUrl::toPercentEncoding(q));
}

}

void VK::reqFinished(bool err)
{
    if(!err)
    {
    QString data;
    //data= http->readAll();
    //data = data.fromUtf8(http->readAll());
    lastjsonrequest=data;

    if(!data.contains("error_code\":"))
    {
    QStringList list;

    data.replace("{\"response\":[","");
    data.replace("\"},{\"","\n");
    data.replace("\",\"","\n");

    data.replace("\"artist\":\"","\n");

    data.replace("\"}]}","");
    data.replace("\\/","/");

    data.replace("artist\":\"","");
    data.replace("title\":\"","");
    data.replace("duration\":","");
    data.replace(",\"","\n");
    data.replace("url\":\"","");

    data.replace("aid\"","deleteditem");
    data.replace("album\"","deleteditem");
    data.replace("owner_id\"","deleteditem");
    data.replace("lyrics_id\"","deleteditem");
    data.replace("count\"","deleteditem");

    data.replace("\\\"","\"");

    list = data.split("\n");
    list.removeAll("deleteditem");

    QStringList result;
    result = list.filter("deleteditem");

    foreach (const QString &str, result)
    {
        list.removeOne(str);
    }

    int i=0;

    treeWidget->clear();

    while(i!=list.count())
    {
    AddItem(list.value(i)+"-"+ list.value(i+1),list.value(i+3),list.value(i+2).toInt());
    i+=4;

    if(i>list.count()) break;
    }

 }
 else
 {
        QMessageBox::about(NULL,"VK Search Error",lastjsonrequest);
 }

   //
    }
    else
    {

        //if(http->error()!=QHttp::Aborted)
        //QMessageBox::about(NULL,"VK Search Error",http->errorString());
    }

 treeWidget->setEnabled(true);
  ui->loading->hide();
}

void VK::SerFild()
{
 treeWidget->setEnabled(false);
  ui->loading->show();
  VKSearch(ui->search->text());
}

void VK::AuthBut()
{
    ui->webView->load(QUrl::fromUserInput("https://oauth.vk.com/authorize?client_id=2428502&scope=5128&redirect_uri=http://oauth.vk.com/blank.html&display=page&response_type=token"));
}

void VK::Additional()
{
    if(ui->add->isChecked())
    {
        ui->additional->show();
    }
    else
    {
        ui->additional->hide();
    }
}

void VK::VKBut()
{
    ui->webView->load(QUrl::fromUserInput("https://m.vk.com"));
}

void VK::OnTreeKeyPress(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete)
    {
    // DeleteSelected();
    // SaveList();
     }

    if(event->key() == Qt::Key_Space)
    {
         player->LoadFile(treeWidget->selectedItems().first()->text(3));
         player->PlayFile();
         player->show();

    }
}

void VK::Download()
{
    QList<QTreeWidgetItem*> selectedItems(treeWidget->selectedItems());
    foreach ( QTreeWidgetItem * item, selectedItems )
    {
     //QMessageBox::about(NULL,"Test",item->text(3));
       QDesktopServices::openUrl(QUrl(item->text(3), QUrl::TolerantMode));
        // ui->webView->load(QUrl::fromUserInput(item->text(3)));
        //delete item;
    }
}
