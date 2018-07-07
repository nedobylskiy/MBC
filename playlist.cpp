#include "playlist.h"
#include "ui_playlist.h"
#include <QMessageBox>
#include <QMenu>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QShortcut>
#include <QInputDialog>
#include <QDropEvent>

TreeWidgetPL::TreeWidgetPL(QWidget *parent) :
    QTreeWidget(parent)
{
    setMouseTracking(true);
}

void TreeWidgetPL::dropEvent(QDropEvent *event)
{
    QTreeWidget::dropEvent(event);
    emit OnDragDrop();
}

void TreeWidgetPL::keyPressEvent(QKeyEvent *event)
{
    QTreeWidget::keyPressEvent(event);
    emit OnKeyPress(event);
}

QString PlayList::Sec22TimeStr(int sec)
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


QString PlayList::ExtractPParam(QString content,QString key) //
{
    QString argpars,tempp;
    tempp="<!--!"+key+"!{";
    if(content.contains(tempp))
    {
    argpars=content;
    int indof = argpars.indexOf(tempp);
    argpars.remove(0,indof);
    argpars.remove(0,tempp.length());
    argpars.remove(argpars.indexOf("}-->"),argpars.length());
    return argpars;
    }
    else
        return "";
}

QString PlayList::AddPParam(QString key,QString value) //
{
    return "<!--!"+key+"!{"+value+"}-->";
}


PlayList::PlayList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayList)
{
    ui->setupUi(this);


    //***********TREE WIDGET*************
    treeWidget = new TreeWidgetPL();
    QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
    __qtreewidgetitem->setTextAlignment(1, Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
    treeWidget->setHeaderItem(__qtreewidgetitem);
    new QTreeWidgetItem(treeWidget);
    new QTreeWidgetItem(treeWidget);
    treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
    treeWidget->setDragDropMode(QAbstractItemView::DragDrop);
    treeWidget->setDefaultDropAction(Qt::MoveAction);
    treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeWidget->setTextElideMode(Qt::ElideNone);
    treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    treeWidget->setIndentation(0);
    treeWidget->setRootIsDecorated(false);
    treeWidget->setItemsExpandable(false);
    treeWidget->setAnimated(true);
    treeWidget->setExpandsOnDoubleClick(false);
    treeWidget->setColumnCount(5);
    //ui->verticalLayout_2->addWidget(treeWidget);
    ui->verticalLayout->addWidget(treeWidget);

    QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
    ___qtreewidgetitem->setText(4, QApplication::translate("PlayList", "Seconds", 0, QApplication::UnicodeUTF8));
    ___qtreewidgetitem->setText(3, QApplication::translate("PlayList", "Path", 0, QApplication::UnicodeUTF8));
    ___qtreewidgetitem->setText(2, QApplication::translate("PlayList", "Duration", 0, QApplication::UnicodeUTF8));
    ___qtreewidgetitem->setText(1, QApplication::translate("PlayList", "Name", 0, QApplication::UnicodeUTF8));
    ___qtreewidgetitem->setText(0, QApplication::translate("PlayList", "Start Time", 0, QApplication::UnicodeUTF8));

    //const bool __sortingEnabled = treeWidget->isSortingEnabled();
    treeWidget->setSortingEnabled(false);

        connect(treeWidget, SIGNAL(OnKeyPress(QKeyEvent*)), this, SLOT(OnTreeKeyPress(QKeyEvent*)));

    //***********************************



length=0;
spos=0;

    QAction *a;
    QShortcut *shortcut;

    a = new QAction(tr("Move To Top"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(MenuToTop()));
   treeWidget->addAction(a);


   // menu = new QMenu("Playlist");



  // shortcut = new QShortcut(QKeySequence(tr("Delete")), treeWidget);

    a = new QAction(tr("Rename"), this);
    //a->setShortcut(QKeySequence(tr("F2")));
    connect(a, SIGNAL(triggered()), this, SLOT(MenuRename()));
    treeWidget->addAction(a);

    a = new QAction(tr("Delete"), this);
    //a->setShortcut(QKeySequence(tr("Delete")));
    connect(a, SIGNAL(triggered()), this, SLOT(MenuDelete()));
   treeWidget->addAction(a);



    a = new QAction(tr("Clear"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(MenuClear()));
 treeWidget->addAction(a);



 treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
   // connect(treeWidget, SIGNAL(customContextMenuRequested(const QPoint &)),this, SLOT(MenuRun(const QPoint &)));

clear();

 treeWidget->setColumnWidth(1,300);
 treeWidget->setColumnWidth(2,80);
 treeWidget->setColumnWidth(4,0);

QTimer *updatetmr = new QTimer(this);
 connect(updatetmr, SIGNAL(timeout()), SLOT(UpdateTimer()));
 updatetmr->start(1000);

}

void PlayList::AddItem(QString name,QString path, int duration, int index)
{
    QTreeWidgetItem *topLevelItem=new QTreeWidgetItem();//QTreeWidgetItem(treeWidget);
    topLevelItem->setText(0,"00:00:00");
    topLevelItem->setText(1,name);

    if(duration>0)
        topLevelItem->setText(2,Sec22TimeStr(duration));
    else
        topLevelItem->setText(2,"Radio");

    topLevelItem->setText(3,path);
    topLevelItem->setText(4,QString::number(duration));

    topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
    //topLevelItem->setFlags(topLevelItem->flags() & Qt::Item);

    if(index==-1)
    treeWidget->addTopLevelItem(topLevelItem);
    else
    treeWidget->insertTopLevelItem(index,topLevelItem);
}


int PlayList::count()
{
    int i=0;
     QTreeWidgetItemIterator it(treeWidget);
         while (*it)
         {
             i++;
             ++it;
         }

return i;
}

void PlayList::DeleteTopItem()
{
 QTreeWidgetItemIterator it(treeWidget);
 delete (*it);
}


song PlayList::GetTopItem()
{
song so;

QTreeWidgetItemIterator it(treeWidget);
so.name = (*it)->text(1);
so.path = (*it)->text(3);
so.duration = (*it)->text(4).toInt();
so.started=(*it)->text(0);


return so;
}


void PlayList::Mirror()
{
int i=count(),z=0;
QTreeWidgetItemIterator it(treeWidget);
        while (*it)
        {

            treeWidget->addTopLevelItem((*it));
            delete (*it);
            if(z==i) break;

            ++it;
            z++;
        }
}

void PlayList::clear()
{
    treeWidget->clear();
}


void PlayList::DeleteSelected()
{

    QList<QTreeWidgetItem*> selectedItems(treeWidget->selectedItems());
    foreach ( QTreeWidgetItem * item, selectedItems )
        delete item;
}
void PlayList::MenuDelete()
{
    DeleteSelected();
}

void PlayList::MenuClear()
{
    clear();
}

void PlayList::MenuToTop()
{
    //QTreeWidgetItem*i;
    QList<QTreeWidgetItem*> selectedItems(treeWidget->selectedItems());
 for(int k = 0; k < (selectedItems.size()/2); k++) selectedItems.swap(k,selectedItems.size()-(1+k)); //listreverse
 foreach ( QTreeWidgetItem * item, selectedItems )
       {
        AddItem(item->text(1),item->text(3),item->text(4).toInt(),0);
        delete item;
       }
}

void PlayList::MenuRename()
{
    RenameItemDlg();
}

void PlayList::MenuRun(const QPoint &pos)
{
menu->move(pos);
menu->show();
}

void PlayList::UpdateTimer()
{
    if (length<1)
    {
        length=0;
        spos=0;
    }

    qint64 tim=QDateTime::currentMSecsSinceEpoch()+((length-spos)*1000);

    //mlen++;

   // QMessageBox::about(NULL,"asd",QString::number((spos))+" "+QString::number((length)));

    QTreeWidgetItemIterator it(treeWidget);
            while (*it)
            {
                (*it)->setFlags((*it)->flags() & ~Qt::ItemIsDropEnabled);

                //QTreeWidgetItem *s;
                (*it)->setText(0,QDateTime::fromMSecsSinceEpoch(tim).toString("hh:mm:ss"));
                tim=tim+((*it)->text(4).toInt()*1000);


                ++it;
            }


            emit OnTimerTick();
}

void PlayList::OnTreeKeyPress(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete)
    {
     DeleteSelected();
     }

  /*  if(event->key() == Qt::Key_Space)
    {
         player->LoadFile(treeWidget->selectedItems().first()->text(3));
         player->PlayFile();
         player->show();

    }*/


    if(event->key() == Qt::Key_F2)
    {
     RenameItemDlg();
    }
}


void PlayList::SetLen(int dlen,int dpos)
{
length=dlen;
spos=dpos;
}


void PlayList::AssignToFile(QString filef)
{
    file = filef;
}

void PlayList::RenameItemDlg()
{
    if(treeWidget->selectedItems().count()>0)
    {

    bool ok;
    QString name = QInputDialog::getText(this, tr("Rename Item"), tr("Item Name:"), QLineEdit::Normal,treeWidget->selectedItems().first()->text(1), &ok);
    if (ok && !name.isEmpty())
       {
    treeWidget->selectedItems().first()->setText(1,name);
    SaveList();
       }
    }
}


void PlayList::SaveList()
{
    if(file.length()>0)
    {
    QFile fil(file);

    if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
             return;
    fil.write(AddPParam("count",QString::number(count())).toAscii());

    int i=0;



    QTreeWidgetItemIterator it(treeWidget);
            while (*it)
            {
                (*it)->setFlags((*it)->flags() & ~Qt::ItemIsDropEnabled);
                        fil.write(AddPParam(QString::number(i)+"name",(*it)->text(1)).toAscii());
                        fil.write(AddPParam(QString::number(i)+"path",(*it)->text(3)).toAscii());

                ++it;
                i++;
            }


    fil.close();
    }
}
void PlayList::LoadList()
{

}

song PlayList::GetRandomItem(int from)
{
    int i=0;
    while(1)
    {
    QTreeWidgetItemIterator it(treeWidget);
            while (*it)
            {
                i++;
                if(i>from)
                {
               /* (*it)->setFlags((*it)->flags() & ~Qt::ItemIsDropEnabled);
                (*it)->setText(0,QDateTime::fromMSecsSinceEpoch(tim).toString("hh:mm:ss"));
                tim=tim+((*it)->text(4).toInt()*1000);*/
                  //  QDateTime tim();
                //int temp=tim.toLocalTime().toMSecsSinceEpoch();
                    srand(QDateTime::currentMSecsSinceEpoch());
                    int z=rand();

                    if(z==0)
                    {
                        song so;
                        so.name = (*it)->text(1);
                        so.path = (*it)->text(3);
                        so.duration = (*it)->text(4).toInt();
                        so.started=(*it)->text(0);
                        return so;
                    }
                }

                ++it;
            }
    }
}

bool PlayList::ListHaveIt(QString path)
{
    QTreeWidgetItemIterator it(treeWidget);
            while (*it)
            {
                if((*it)->text(3).contains(path,Qt::CaseInsensitive))
                {
                    return true;
                }

                ++it;

            }

return false;
}

PlayList::~PlayList()
{
    delete ui;
}

