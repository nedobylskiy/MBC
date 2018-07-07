#include "jingles.h"
#include "ui_jingles.h"
#include <QFileDialog>
#include <QFile>
#include <time.h>
#include <QInputDialog>
#include <QMessageBox>

int random(int a,int b)
{
    qsrand(time(NULL));
    if (a > 0) return a + qrand() % (b - a);
    else return a + qrand() % (abs(a) + b);
}

Jingles::Jingles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jingles)
{
    ui->setupUi(this);

    jinplayer = new Player2();
    connect(jinplayer, SIGNAL(OnPlaybackEnded()), this, SLOT(OnPlayerStops()));

    connect(ui->addj, SIGNAL(clicked()), this, SLOT(OnAddJingles()));
    connect(ui->djin, SIGNAL(clicked()), this, SLOT(OnDeleteJingles()));

    connect(ui->add2, SIGNAL(clicked()), this, SLOT(OnAddJingles2()));
    connect(ui->del2, SIGNAL(clicked()), this, SLOT(OnDeleteJingles2()));

    mcount=0;
    order=0;


    connect(ui->act1, SIGNAL(stateChanged(int)), this, SLOT(OnChanges()));
    connect(ui->rand, SIGNAL(toggled(bool)), this, SLOT(OnChanges()));
    connect(ui->every, SIGNAL(valueChanged(int)), this, SLOT(OnChanges()));

}

Jingles::~Jingles()
{
    delete ui;
}

void Jingles::SetMainStream(HSTREAM mains)
{
    main=mains;
    jinplayer->SetMainStream(main);
}

bool Jingles::CheckJingleTime()
{

    if(!ui->act1->isChecked())
    {
       return false;
    }

  if((ui->jinglist1->count()>0))
   {
    mcount++;
    if(mcount>=ui->every->value())
    {
        mcount=0;
        next=GenerateNewItem();
        return true;
    }

    /*else
    {
        mcount=0;
        next=GenerateNewItem();
        order++;
        if(order>ui->jinglist1->count()-1) order=0;
        return true;
    }*/
   }

  return false;
}

song Jingles::GenerateNewItem()
{
    song temp;
    if(ui->rand->isChecked())
    {
    int i;
    //qsrand(qrand());
    if(ui->jinglist1->count()==1)
    {
        i=0;
    }
    else
    {
    i=random(0,ui->jinglist1->count()-1);//qrand()%(ui->jinglist1->count()*2);// - 3;
    }
    temp.path=ui->jinglist1->item(i)->text();
    temp.name="***Jingle***";
    temp.duration=GetStreamSecLength(ui->jinglist1->item(i)->text());
    }
    else
    {

       // return true;
        temp.path=ui->jinglist1->item(order)->text();
        temp.name="***Jingle***";
        temp.duration=GetStreamSecLength(ui->jinglist1->item(order)->text());
        order++;
        if(order>ui->jinglist1->count()-1) order=0;
    }
    return temp;
}

void Jingles::AssignToFile(QString filef)
{
    file = filef;
    LoadConfig();
}

void Jingles::LoadConfig()
{
    if(file.length()>0)
    {
    QFile fil(file);

    if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QString content,tempn;
    int i=0,count=0;

    content = fil.readAll();

    ui->every->setValue(ExtractPParam(content,"l1every").toInt());

    count=ExtractPParam(content,"l1count").toInt();
    while(1)
        {

        tempn = ExtractPParam(content,QString::number(i)+"l1path");
        if(!tempn.isEmpty())
        {
            ui->jinglist1->addItem(tempn);
        }

        if(i>=count) break;

        i++;
        }

    if(ExtractPParam(content,"l1random")=="true")
    {
       ui->rand->setChecked(true);
       ui->byo->setChecked(false);
    }
    else
    {
        ui->rand->setChecked(false);
        ui->byo->setChecked(true);
    }


    if(ExtractPParam(content,"l1active")=="true")
       ui->act1->setChecked(true);
    else
       ui->act1->setChecked(false);


    //*********LIST2
    if(ExtractPParam(content,"l2active")=="true")
       ui->act2->setChecked(true);
    else
       ui->act2->setChecked(false);


     i=0;
     count=0;

    count=ExtractPParam(content,"l2count").toInt();
    while(1)
        {

        tempn = ExtractPParam(content,QString::number(i)+"l2path");
        if(!tempn.isEmpty())
        {
            QTreeWidgetItem *topLevelItem=new QTreeWidgetItem(ui->jin2list);
            topLevelItem->setText(0,ExtractPParam(content,QString::number(i)+"l2cond"));
            topLevelItem->setText(1,tempn);
            topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
            ui->jin2list->addTopLevelItem(topLevelItem);
        }

        if(i>=count) break;
        i++;
        }


    }
}


void Jingles::SaveConfig()
{
    if(file.length()>0)
    {
    QFile fil(file);

    if (!fil.open(QIODevice::WriteOnly | QIODevice::Text)) return;


    if(ui->rand->isChecked())
        fil.write(AddPParam("l1random","true").toAscii());
    else
        fil.write(AddPParam("l1random","false").toAscii());

   if(ui->act1->isChecked())
      fil.write(AddPParam("l1active","true").toAscii());
   else
      fil.write(AddPParam("l1active","false").toAscii());


   fil.write(AddPParam("l1every",QString::number(ui->every->value())).toAscii());

   fil.write(AddPParam("l1count",QString::number(ui->jinglist1->count())).toAscii());
    int i=0;
    while(i<ui->jinglist1->count())
    {
        fil.write(AddPParam(QString::number(i)+"l1path",ui->jinglist1->item(i)->text()).toAscii());
        i++;
    }

 //*********LIST2
    if(ui->act2->isChecked())
       fil.write(AddPParam("l2active","true").toAscii());
    else
       fil.write(AddPParam("l2active","false").toAscii());


    /*int*/ i=1;
    QTreeWidgetItemIterator it(ui->jin2list);
            while (*it)
            {

               fil.write(AddPParam(QString::number(i)+"l2cond", (*it)->text(0)).toAscii());
               fil.write(AddPParam(QString::number(i)+"l2path", (*it)->text(1)).toAscii());
                ++it;
                i++;
            }

    fil.write(AddPParam("l2count",QString::number(i)).toAscii());

    fil.close();
    }
}

int Jingles::CheckPatternActive(QString pattern)
{
    QString min,hours,days,month,dow,sec;

    QString temp=pattern;

    sec=temp.remove(temp.indexOf(" "),temp.length()); //minutes parse

    temp=pattern;
    temp.replace(sec+" ","");
    min=temp.remove(temp.indexOf(" "),temp.length());

    temp=pattern;
    temp.replace(sec+" "+min+" ","");
    hours=temp.remove(temp.indexOf(" "),temp.length());

    temp=pattern;
    temp.replace(sec+" "+min+" "+hours+" ","");
    days=temp.remove(temp.indexOf(" "),temp.length());

    temp=pattern;
    temp.replace(sec+" "+min+" "+hours+" "+days+" ","");
    month=temp.remove(temp.indexOf(" "),temp.length());

    temp=pattern;
    temp.replace(sec+" "+min+" "+hours+" "+days+" "+month+" ","");
    dow=temp;



   //  QMessageBox::about(NULL,"asd",sec+"|"+min+"|"+hours+"|"+days+"|"+month+"|"+dow+"");


    QDateTime dt;
    dt = dt.currentDateTime();


    if(PatContentsNum(dow,dt.date().dayOfWeek())) //if pattern contents current day of week
    {
        if(PatContentsNum(month,dt.date().month())) //if pattern contents current month
        {
            if(PatContentsNum(days,dt.date().day())) //if pattern contents current day of month
            {
                if(PatContentsNum(hours,dt.time().hour())) //if pattern contents current hour
                {
                    if(PatContentsNum(min,dt.time().minute())) //if pattern contents current min
                    {
                        if(PatContentsNum(sec,dt.time().second())) //if pattern contents current min
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    //dow=temp.remove(temp.indexOf(" "),temp.length());


    return 0;

}

void Jingles::CheckPatterns()
{
    int i=0;
    QTreeWidgetItemIterator it(ui->jin2list);
            while (*it)
            {
                if(CheckPatternActive((*it)->text(0))==1)
                {
                    if(ui->act2->isChecked())
                    {
                        emit OnSilence(15,true);
                        jinplayer->StopPlaying();
                        jinplayer->LoadFile((*it)->text(1));
                        jinplayer->PlayLoadedFile();
                    }
                    //QMessageBox::about(NULL,"asd",(*it)->text(1));
                }
                ++it;
                i++;
            }
}

QString Jingles::ExtractPParam(QString content, QString key)
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

QString Jingles::AddPParam(QString key, QString value)
{
        return "<!--!"+key+"!{"+value+"}-->";
}

void Jingles::OnAddJingles()
{
    QFileDialog *dlg = new QFileDialog(this,Qt::Dialog);
    dlg->setNameFilter(tr("Sound Files (*.mp3 *.wav *.ogg)"));
    dlg->setFileMode(QFileDialog::ExistingFiles);
    dlg->setWindowTitle("Add Files to Jingle Library 1");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);
    QStringList fileNames;
     if ( dlg->exec())
     {
     fileNames = dlg->selectedFiles();
     foreach (const QString &fil, fileNames)
         {
            ui->jinglist1->addItem(fil);
         }
     //SaveList();
      }

     SaveConfig();

}

void Jingles::OnDeleteJingles()
{
  //  int i=0;
    if(ui->jinglist1->count()>0)
    {
        qDeleteAll(ui->jinglist1->selectedItems());
    }

    SaveConfig();
}

void Jingles::OnAddJingles2()
{
    QFileDialog *dlg = new QFileDialog(this,Qt::Dialog);
    dlg->setNameFilter(tr("Sound Files (*.mp3 *.wav *.ogg)"));
    dlg->setFileMode(QFileDialog::ExistingFiles);
    dlg->setWindowTitle("Add Files to Jingle Library 1");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);
    QStringList fileNames;

    QString pattern;
    bool ok;

     if ( dlg->exec())
     {
     fileNames = dlg->selectedFiles();
     foreach (const QString &fil, fileNames)
         {
         pattern = QInputDialog::getText(this, tr("Edit Pattern"), tr("Pattern:"), QLineEdit::Normal,"0-59 * * * * *", &ok);
         if (ok && !pattern.isEmpty())
            {
         QTreeWidgetItem *topLevelItem=new QTreeWidgetItem(ui->jin2list);
         topLevelItem->setText(0,pattern);
         topLevelItem->setText(1,fil);
         topLevelItem->setFlags(topLevelItem->flags() & ~Qt::ItemIsDropEnabled);
         ui->jin2list->addTopLevelItem(topLevelItem);
            }
         }
      }

     SaveConfig();
}

void Jingles::OnDeleteJingles2()
{
    QList<QTreeWidgetItem*> selectedItems(ui->jin2list->selectedItems());
    foreach ( QTreeWidgetItem * item, selectedItems )
        delete item;
}

void Jingles::OnPlayerStops()
{
    emit OnSilence(15,false);
}

int Jingles::GetStreamSecLength(QString file)
{
    HSTREAM temp;
    temp= BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0, BASS_STREAM_DECODE);
    return (int)BASS_ChannelBytes2Seconds(temp,BASS_ChannelGetLength(temp, BASS_POS_BYTE));
}

void Jingles::OnChanges()
{
    SaveConfig();
}

bool Jingles::PatContentsNum(QString pat,int num)
{
    pat=pat.trimmed();
    if(!pat.contains("-")&&!pat.contains(",")&&!pat.contains("*")) //is a simple number
    {
        if(pat.toInt()==num) return true; else return false;
    }

    if(pat=="*") //universal number
    {
        return true;
    }

    if(pat.contains("-")&&!pat.contains(",")&&!pat.contains("*")) //is a range
    {
        QString temp=pat;
        int min,max;
        min=temp.remove(temp.indexOf("-"),temp.length()).toInt();
        max=pat.replace(temp+"-","").toInt();
        if((num<=max)&&(num>=min)) return true; else return false;
    }

    if(pat.contains(",")&&!pat.contains("*")) //is a list
    {
        QStringList list = pat.split(",");
        foreach (const QString &str, list)
        {
            if(PatContentsNum(str,num)) return true;
        }
        return false;
    }

   if(pat.contains("/")&&!pat.contains(",")&&!pat.contains("-")) //is a range
    {
        QString temp=pat;
        int del;
        temp.remove(temp.indexOf("/"),temp.length());
        del=pat.replace(temp+"/","").toInt();
        if(num%del==0) return true; else return false;

    }

    return false;
}


/* int i,count;
 i=0;
 QString temp=pat,del="";
 count=temp.count(",");

 while(i<=count)
 {
 temp.replace(del,"");
 min=temp.remove(temp.indexOf("-"),temp.length());

 if((num<=max)&&(num>=min)) return true; else return false;
 i++;
 }

 return false;*/
