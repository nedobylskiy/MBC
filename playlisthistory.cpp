#include "playlisthistory.h"
#include "ui_playlisthistory.h"

PlaylistHistory::PlaylistHistory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistHistory)
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
        ___qtreewidgetitem1->setText(0, QApplication::translate("Library", "Started at", 0, QApplication::UnicodeUTF8));

        treeWidget->setColumnWidth(0,60);
        treeWidget->setColumnWidth(1,300);
        treeWidget->setColumnWidth(2,80);
        treeWidget->setColumnWidth(4,0);
    //*********Настройка листа

        ui->verticalLayout->addWidget(treeWidget);

}

PlaylistHistory::~PlaylistHistory()
{
    delete ui;
}

void PlaylistHistory::AddItem(QString name, QString path, int duration, QString started)
{
    QTreeWidgetItem *topLevelItem=new QTreeWidgetItem();//QTreeWidgetItem(treeWidget);
    topLevelItem->setText(0,started);
    topLevelItem->setText(1,name);

    if(duration>0)
        topLevelItem->setText(2,Sec22TimeStr(duration));
    else
        topLevelItem->setText(2,"Radio");

    topLevelItem->setText(3,path);
    topLevelItem->setText(4,QString::number(duration));

    topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
    //topLevelItem->setFlags(topLevelItem->flags() & Qt::Item);

  /*  if(index==-1)
    treeWidget->addTopLevelItem(topLevelItem);
    else*/
    treeWidget->insertTopLevelItem(0,topLevelItem);
}

QString PlaylistHistory::Sec22TimeStr(int sec)
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

