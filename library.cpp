#include "library.h"
#include "ui_library.h"
#include "playlist.h"
#include "bass.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QMenu>
#include <QTimer>
#include <QDropEvent>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QShortcut>
#include <QProgressDialog>
#include "previewplayer.h"


//ID3
 #ifdef _WIN32
#include <fileref.h>
#include <tag.h>
//ALTERNATE TAGS (win only)
#include "tags.h"

#define _USEALTTAGS

#else
#include <taglib/fileref.h>
#include <taglib/tag.h>
#endif
//ID3


QString Library::ExtractPParam(QString content,QString key) //
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

QString Library::AddPParam(QString key,QString value) //
{
    return "<!--!"+key+"!{"+value+"}-->";
}


 QString Library::ExtractTags(QString file)
 {

#ifdef _USEALTTAGS

     HSTREAM temp;
     QString result;
     temp= BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0, BASS_STREAM_DECODE);
     result=TAGS_Read(temp, "%ARTI-%TITL");
     return result;
#else

     QString result;
     //********************************************
     TagLib::FileRef f(file.toStdString().c_str());


        if(!f.isNull() && f.tag())
        {
          TagLib::Tag *tag = f.tag();
        result =  QString::fromStdWString(tag->artist().toWString())+"-"+QString::fromStdWString(tag->title().toWString());
            result = result.fromUtf8(result.toAscii());
        }
     //********************************************
 return result;
#endif
 }

 int Library::GetStreamSecLength(QString file)
 {
 HSTREAM temp;
 temp= BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,/*BASS_SAMPLE_FLOAT || BASS_MIXER_BUFFER ||*/ BASS_STREAM_DECODE);
return (int)BASS_ChannelBytes2Seconds(temp,BASS_ChannelGetLength(temp, BASS_POS_BYTE));
 }

QString Library::Sec22TimeStr(int sec)
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


TreeWidget::TreeWidget(QWidget *parent) :
    QTreeWidget(parent)//,
    //ui(new Ui::TreeWidget)
{
setMouseTracking(true);
}

Library::Library(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Library)
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


    //*********ПОИСКОВЫЙ ЛИСТ
        sresult = new TreeWidget();
        //treeWidget = new TreeWidget(Library);
        sresult->setObjectName(QString::fromUtf8("sresult"));
        sresult->setDragEnabled(false);
        sresult->setDragDropMode(QAbstractItemView::DragDrop);
        sresult->setDefaultDropAction(Qt::IgnoreAction);
        sresult->setSelectionMode(QAbstractItemView::ExtendedSelection);
        sresult->setRootIsDecorated(false);
        sresult->setItemsExpandable(false);
        sresult->setExpandsOnDoubleClick(false);

        QTreeWidgetItem *___qtreewidgetitem = sresult->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("Library", "Sec", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("Library", "Path", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("Library", "Duration", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("Library", "Name", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Library", "Start Time", 0, QApplication::UnicodeUTF8));

        sresult->setColumnWidth(0,0);
        sresult->setColumnWidth(1,300);
        sresult->setColumnWidth(2,80);
        sresult->setColumnWidth(4,0);
    //*********ПОИСКОВЫЙ ЛИСТ

        player = new PreViewPlayer();
        ui->verticalLayout->addWidget(player);
        player->hide();

 ui->verticalLayout->addWidget(treeWidget);
 ui->verticalLayout->addWidget(sresult);

 //ui->searchf->hide();
 sresult->hide();
 ui->searchbut->hide();




    QAction *a;
    QShortcut *shortcut;
 /*shortcut = new QShortcut(QKeySequence(tr("Delete")),treeWidget);
    connect(shortcut, SIGNAL(activated()), this, SLOT(MenuDelete()));*/



    a = new QAction(tr("Delete"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(MenuDelete()));
    treeWidget->addAction(a);

   /* a->setShortcut(QKeySequence(tr("Delete")));
    a->setShortcutContext(Qt::WidgetWithChildrenShortcut);*/


    a = new QAction(tr("Clear"), this);
    connect(a, SIGNAL(triggered()), this, SLOT(MenuClear()));
    treeWidget->addAction(a);
    treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);


//ui->treeWidget->hideColumn(0);


    //ui->treeWidget->mouseGrabber()


   QTimer *updatetmr = new QTimer(this);
    connect(updatetmr, SIGNAL(timeout()), SLOT(UpdateTimer()));
    updatetmr->start(60);

     //connect(ui->treeWidget, SIGNAL()), this, SLOT(MenuDelete()));

   clear();
   FFFStop=false;

    connect(treeWidget, SIGNAL(OnDragDrop()), this, SLOT(OnTreeDragDrop()));
    connect(treeWidget, SIGNAL(OnKeyPress(QKeyEvent*)), this, SLOT(OnTreeKeyPress(QKeyEvent*)));
    connect(sresult, SIGNAL(OnKeyPress(QKeyEvent*)), this, SLOT(OnSearchTreeKeyPress(QKeyEvent*)));

   //****Buttons
   connect(ui->filebut, SIGNAL(clicked()), this, SLOT(AddFilesButton()));
   connect(ui->addurl, SIGNAL(clicked()), this, SLOT(AddUrlButton()));
   connect(ui->folderbut, SIGNAL(clicked()), this, SLOT(AddFolderButton()));
   connect(ui->searchbut, SIGNAL(clicked()), this, SLOT(SearchButton()));
   connect(ui->searchf, SIGNAL(textChanged(QString)), this, SLOT(OnSearchText()));
}



void Library::AddItem(QString name,QString path, int duration)
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

//->model()->
}


int Library::count()
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

void Library::DeleteTopItem()
{
 QTreeWidgetItemIterator it(treeWidget);
 delete (*it);
}


song Library::GetTopItem()
{
song so;

QTreeWidgetItemIterator it(treeWidget);
so.name = (*it)->text(1);
so.path = (*it)->text(3);
so.duration = (*it)->text(4).toInt();


return so;
}


void Library::Mirror()
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

void Library::clear()
{
    treeWidget->clear();
}


void Library::DeleteSelected()
{

    QList<QTreeWidgetItem*> selectedItems(treeWidget->selectedItems());
    foreach ( QTreeWidgetItem * item, selectedItems )
        delete item;
}

void Library::RenameItem(int i)
{

}

void Library::RenameItemDlg()
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
void Library::MenuDelete()
{
    DeleteSelected();
}

void Library::MenuClear()
{
    clear();
}

void Library::MenuToTop()
{
    QTreeWidgetItem*i;
    QList<QTreeWidgetItem*> selectedItems(treeWidget->selectedItems());
    foreach ( QTreeWidgetItem * item, selectedItems )
       {
        //ui->treeWidget->insertTopLevelItem(0,item);
        //ui->treeWidget->
        //ui->treeWidget->insertTopLevelItem();
        i=item;
        //ui->treeWidget->removeItemWidget(item,0);
        //delete item;
        treeWidget->insertTopLevelItem(1,item);
       }


}

void Library::MenuRun(const QPoint &pos)
{
menu->move(pos);
menu->show();
}

void TreeWidget::dropEvent(QDropEvent *event)
{

    if(event->source()==this)
    {
        event->setDropAction(Qt::MoveAction);
       // event->acceptProposedAction();

        //event->dropAction();
        QTreeWidget::dropEvent(event);
         //model()->insertRow()
        event->accept();
        //QMessageBox::about(NULL,"123","OK");
    }

emit OnDragDrop();
}

void TreeWidget::keyPressEvent(QKeyEvent *event)
{
QTreeWidget::keyPressEvent(event);
emit OnKeyPress(event);
}


void Library::UpdateTimer()
{
//QWidget(ui->treeWidget).x;


    bool inf=false;
/*
    if((ui->treeWidget->cursor().pos().x()>=ui->treeWidget->x())&&(ui->treeWidget->cursor().pos().x()<=ui->treeWidget->x()+ui->treeWidget->width()))
    {
        if((ui->treeWidget->cursor().pos().y()>=ui->treeWidget->y())&&(ui->treeWidget->cursor().pos().y()<=ui->treeWidget->y()+ui->treeWidget->height()))
        {
            inf=true;
            QMessageBox::about(NULL,"123",QString::number(ui->treeWidget->cursor().pos().x())+" "+QString::number( pos().x()));
        }

    }

QMessageBox::about(NULL,"123",QString::number(ui->treeWidget->cursor().pos().x())+" "+QString::number(ui->treeWidget->pos().x()));

    if(inf)
    {
    ui->treeWidget->setDefaultDropAction(Qt::MoveAction);
    }
    else
    {
    ui->treeWidget->setDefaultDropAction(Qt::LinkAction);
    }*/
}

void Library::AddFilesButton()
{




    QFileDialog *dlg = new QFileDialog(this,Qt::Dialog);
    dlg->setNameFilter(tr("Sound Files (*.mp3 *.wav *.ogg)"));
    dlg->setFileMode(QFileDialog::ExistingFiles);
    dlg->setWindowTitle("Add Files to Library");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);


    QStringList fileNames;
     if ( dlg->exec())
     {
         fileNames = dlg->selectedFiles();

     foreach (const QString &fil, fileNames)
         {

            AddItem(ExtractTags(fil),fil,GetStreamSecLength(fil));
         }
     SaveList();
      }


}

void Library::AddUrlButton()
{

    bool ok;
    QString name = QInputDialog::getText(this, tr("Add Url"), tr("Url Name:"), QLineEdit::Normal,"", &ok);
    if (ok && !name.isEmpty())
       {
        QString url = QInputDialog::getText(this, tr("Add Url"), tr("Url:"), QLineEdit::Normal,"http://", &ok);
        if (ok && !url.isEmpty())
           {
            AddItem(name,url,0);
           }

    SaveList();
    }


}

void Library::AddFolderButton()
{



    QFileDialog *dlg = new QFileDialog(this,Qt::Dialog);
    //dlg->setNameFilter(tr("Sound Files (*.mp3 *.wav *.ogg)"));
    dlg->setFileMode(QFileDialog::Directory);
    dlg->setWindowTitle("Add Directory to Library");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);


    //QStringList fileNames;
     if ( dlg->exec())
     {

     FFFStop=false;
     ui->folderbut->setEnabled(false);

     progress= new QProgressDialog("Searching files...", "Abort", 0, 0, this);

     progress->setWindowModality(Qt::NonModal);
     progress->show();
     fff1=0;
     fff2=0;

     connect(progress, SIGNAL(canceled ()), this, SLOT(OnFFFCancel()));

     FileFolderFind(dlg->selectedFiles().first());
     ui->folderbut->setEnabled(true);
     SaveList();
      }

}

void Library::SearchButton()
{
    if(ui->searchf->isVisible())
    {
        ui->searchf->hide();
        sresult->hide();
        treeWidget->show();
    }
    else
    {
        ui->searchf->show();
        sresult->show();
        treeWidget->hide();
    }
}

 void Library::OnSearchText()
 {
    QTreeWidgetItem *topLevelItem;
    QString pr=ui->searchf->text();

    sresult->clear();
    if(!pr.isEmpty())
    {

    sresult->show();
    treeWidget->hide();

        QTreeWidgetItemIterator it(treeWidget);
                while (*it)
                {


                if(((*it)->text(1).contains(pr,Qt::CaseInsensitive))||((*it)->text(3).contains(pr,Qt::CaseInsensitive)))
                    {

                    //QMessageBox::about(NULL,"123","Founded");

                    topLevelItem =new QTreeWidgetItem(sresult);
                    topLevelItem->setText(0,"N/A");
                    topLevelItem->setText(1,(*it)->text(1));
                    topLevelItem->setText(2,(*it)->text(2));
                    topLevelItem->setText(3,(*it)->text(3));
                    topLevelItem->setText(4,(*it)->text(4));

                    topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
                    //topLevelItem->setFlags(topLevelItem->flags() & Qt::Item);
                    sresult->addTopLevelItem(topLevelItem);
                    //QMessageBox::about(NULL,"123","added");
                    }

                 ++it;

                }
    }
    else
    {
         sresult->hide();
          treeWidget->show();
    }

 }

 void Library::OnFFFCancel()
 {
     FFFStop=true;
 }


void Library::AssignToFile(QString filef)
{
file = filef;
}

void Library::SaveList()
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
                //(*it)->setFlags((*it)->flags() & ~Qt::ItemIsDropEnabled);

              // (*it)->
                        fil.write(AddPParam(QString::number(i)+"name",(*it)->text(1)).toAscii());
                        fil.write(AddPParam(QString::number(i)+"path",(*it)->text(3)).toAscii());

                ++it;
                i++;
            }


    fil.close();
    }
}
void Library::LoadList()
{
    if(file.length()>0)
    {
    QFile fil(file);

    if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QString content,tempn,tempp;
    int i=0,count=0;

    content = fil.readAll();

    count=ExtractPParam(content,"count").toInt();

    while(1)
        {

        tempn = ExtractPParam(content,QString::number(i)+"path");
        if(!tempn.isEmpty())
        {
            tempp = ExtractPParam(content,QString::number(i)+"name");
            AddItem(tempp,tempn,GetStreamSecLength(tempn));
        }

        if(i>=count) break;

        i++;
        }

    }
}

void Library::FileFolderFind(const QString &sDir)
{
        QDir dir(sDir);

        if(FFFStop) return;

        QFileInfoList list = dir.entryInfoList();
        fff1 = fff1+list.count();
        for (int iList=0;iList<list.count();iList++)
        {
            fff2++;
        progress->setMaximum(fff1);
        progress->setValue(fff2);
             if(FFFStop) return;

         QApplication::processEvents();

        QFileInfo info = list[iList];
        QString sFilePath = info.filePath();
            if (info.isDir())
            {
                // recursive
                if (info.fileName()!=".." && info.fileName()!=".")
                {
                    FileFolderFind(sFilePath);
                }
            }
            else
            {

                if((info.fileName().contains(".mp3",Qt::CaseInsensitive))||(info.fileName().contains(".wav",Qt::CaseInsensitive))||(info.fileName().contains(".ogg",Qt::CaseInsensitive)))
                {

                     AddItem(ExtractTags(info.filePath()),info.filePath(),GetStreamSecLength(info.filePath()));
                    //QMessageBox::about(NULL,"123",info.fileName()+"\n"+info.filePath());
                }

            }
        }

}

song Library::GetRandomItem(int from)
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
                    srand(QDateTime::currentMSecsSinceEpoch()-i);
                    int z=rand();
                    srand(i);
                    int s=rand()%10;
                    z+=s;
                    /*song so;
                    so.path=QString::number(z%10);
                    return so;*/

                    if((z%10>7)&&(z%10<9))
                    {
                        song so;
                        so.name = (*it)->text(1);
                        so.path = (*it)->text(3);
                        so.duration = (*it)->text(4).toInt();
                        return so;
                    }
                }

                ++it;
            }
    }
  return GetTopItem();
}





void Library::OnTreeDragDrop()
{
SaveList();
}

void Library::OnTreeKeyPress(QKeyEvent *event)
{
//QMessageBox::about(NULL,"123","Event");
    if(event->key() == Qt::Key_Delete)
    {
     DeleteSelected();
     SaveList();
     }

    if(event->key() == Qt::Key_Space)
    {
         player->LoadFile(treeWidget->selectedItems().first()->text(3));
         player->PlayFile();
         player->show();

    }


    if(event->key() == Qt::Key_F2)
    {
     RenameItemDlg();
     SaveList();
    }
}

void Library::OnSearchTreeKeyPress(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
    {

         player->LoadFile(sresult->selectedItems().first()->text(3));
         player->PlayFile();
         player->show();

    }
}


Library::~Library()
{
    delete ui;
}
