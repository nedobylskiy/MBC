#include "mbcwindow.h"
#include "ui_mbcwindow.h"
#include "player2.h"
#include "playlist.h"
#include "library.h"
#include "vk.h"
#include "inputsystem.h"
#include "encoderslist.h"
#include "configure.h"
#include "djpanel.h"

#include "bass.h"
#include "bassmix.h"
#include <QMessageBox>
#include <QSlider>
#include <QSplitter>
#include <QLabel>
#include <QFrame>
#include <QToolBar>
#include <QDateTime>
#include <QSystemTrayIcon>
 #include <QCloseEvent>

//ID3
 #ifdef _WIN32
//#include <fileref.h>
//#include <tag.h>
#include <taglib/fileref.h>
#include <taglib/tag.h>

//ALTERNATE TAGS (win only)
#include "tags.h"
#define _USEALTTAGS

#else
#include <taglib/fileref.h>
#include <taglib/tag.h>
#endif



//ID3


 QString MBCWindow::ExtractTags(QString file)
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
        //  result.sprintf( "%s - %s",tag->artist().toCString() ,tag->title().toCString());
result =  QString::fromStdWString(tag->artist().toWString())+"-"+QString::fromStdWString(tag->title().toWString());
        }
     //********************************************
 return result;

 #endif

 }

 int GetStreamSecLength(QString file)
 {
 HSTREAM temp;
 temp= BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,/*BASS_SAMPLE_FLOAT || BASS_MIXER_BUFFER ||*/ BASS_STREAM_DECODE);
return (int)BASS_ChannelBytes2Seconds(temp,BASS_ChannelGetLength(temp, BASS_POS_BYTE));
 }

MBCWindow::MBCWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MBCWindow)
{
//*****BASS CONFIG*****
main=BASS_Mixer_StreamCreate(44100,2,BASS_MIXER_NONSTOP | BASS_SAMPLE_FLOAT|BASS_SAMPLE_SOFTWARE /*&& BASS_MIXER_BUFFER*/);
//BASS_SetConfig(BASS_CONFIG_BUFFER, 1); //буфер воспроизведения
BASS_ChannelPlay(main, FALSE); //основной поток создан и запщуен
//*****BASS CONFIG*****


//ИКОНКА В Т� ЕЕ

QMenu *menu = new QMenu(tr("Tray Menu"), this);

QAction *a;
a = new QAction( QIcon(":/images/icon.png"),tr("Show"), this);
connect(a, SIGNAL(triggered()), this, SLOT(ShowM()));
menu->addAction(a);
a = new QAction(tr("Hide"), this);
connect(a, SIGNAL(triggered()), this, SLOT(HideM()));
menu->addAction(a);
a = new QAction( QIcon(":/images/play.png"),tr("Play"), this);
connect(a, SIGNAL(triggered()), this, SLOT(PlayButton()));
menu->addAction(a);
a = new QAction( QIcon(":/images/next.png"),tr("Next Track"), this);
connect(a, SIGNAL(triggered()), this, SLOT(NextButton()));
menu->addAction(a);
a = new QAction( QIcon(":/images/stop.png"),tr("Stop"), this);
connect(a, SIGNAL(triggered()), this, SLOT(StopButton()));
menu->addAction(a);

menu->addSeparator();
a = new QAction( QIcon(":/images/exit.png"),tr("Exit"), this);
connect(a, SIGNAL(triggered()), this, SLOT(ExitM()));
menu->addAction(a);



tray = new QSystemTrayIcon(QIcon(":/images/icon.png"),this);
tray->setToolTip("Mixer Broadcaster 3");
tray->setContextMenu(menu);
tray->show();
tray->showMessage("Mixer Broadcaster 3","Loading...",QSystemTrayIcon::Information,5000);
//ИКОНКА В Т� ЕЕ





    splitter = new QSplitter(Qt::Horizontal);




    config = new Configure();
    config->LoadConfig();



    playing=false;

    ui->setupUi(this);

    player1 = new Player2();
    player2 = new Player2();

    player1->SetTittle("Player 1");
    player2->SetTittle("Player 2");

    player1->SetMainStream(main);
    player2->SetMainStream(main);

    /*
    player1->SetTransitionParams(2,3000);
    player1->SetEndFlag(2,4);
    player2->SetTransitionParams(2,3000);
    player2->SetEndFlag(2,4);
    */
    SetUpTransition();

   /* player1->setWindowFlags(Qt::Tool);//|!
    player1->setWindowFlags(player1->windowFlags() & ~Qt::WindowCloseButtonHint & ~Qt::WindowMaximizeButtonHint  & ~Qt::WindowMinimizeButtonHint);
*/

    playlist = new PlayList();


//ui->toolBar->addWidget(player1);
  //  ui->players->addWidget(player1);

    //ui->Playlist->addWidget(playlist);
    //ui->players->addWidget(playlist);

    //ui->players->addWidget(player2);


    splitter->addWidget(player1);
   splitter->addWidget(playlist);
   splitter->addWidget(player2);


   ui->players->addWidget(splitter);

    player1->show();
    player2->show();

    library = new Library();
    ui->pages->insertTab(1,library,QIcon(":/images/library.png"),"Library");
    library->AssignToFile(QCoreApplication::applicationDirPath()+"/library");
    library->LoadList();



    showlist = new Library();
    ui->pages->insertTab(2,showlist,QIcon(":/images/library.png"),"Show List");
    showlist->AssignToFile(QCoreApplication::applicationDirPath()+"/showlist");
    showlist->LoadList();


    micpanel = new InputSystem();
    ui->pages->insertTab(3,micpanel,QIcon(":/images/micwait.png"),"Input");
    micpanel->RefreshList();
    micpanel->SetMainStream(main);


    enclist = new EncodersList();
    ui->pages->insertTab(4,enclist,QIcon(":/images/record.png"),"Encoders");
    enclist->SetMainStream(main);
    enclist->SetListFile(QCoreApplication::applicationDirPath()+"/encoderlist");
    enclist->LoadConfig();



    vk = new VK();
    ui->pages->insertTab(5,vk,QIcon(":/images/vk.png"),"VKontakte");

    djpanel = new DJPanel(main);
    djpanel->SetMainStream(main);
    ui->pages->insertTab(6,djpanel,QIcon(":/images/DJ.png"),"DJ Panel");
    connect(djpanel, SIGNAL(OnSilence(int,bool)), this, SLOT(OnSlienceCh(int,bool)));
    connect(djpanel, SIGNAL(OnMicStatus(int)), this, SLOT(OnMicState(int)));

    #ifdef _WIN32 //Win Only Skype Page
    skype = new WSkype();
    skype->SetMainStream(main);
    ui->pages->insertTab(7,skype,QIcon(":/images/skype.png"),"Skype");
    connect(skype, SIGNAL(OnSilence(int,bool)), this, SLOT(OnSlienceCh(int,bool)));
    #endif

    jingles = new Jingles();
    jingles->SetMainStream(main);
    jingles->AssignToFile(QCoreApplication::applicationDirPath()+"/jinglesconf");
    connect(jingles, SIGNAL(OnSilence(int,bool)), this, SLOT(OnSlienceCh(int,bool)));
    ui->pages->insertTab(7,jingles,QIcon(":/images/jingle.png"),"Jingles");

    plhist = new PlaylistHistory();
    ui->pages->insertTab(8,plhist,QIcon(":/images/clock.png"),"History");




    ui->pages->insertTab(ui->pages->count(),config,QIcon(":/images/configure.png"),"Configure");




    //ui->mdiArea->addSubWindow(player1);

connect(ui->TestButton,SIGNAL(clicked()),SLOT(TestButton()));
connect(player1,SIGNAL(OnPlaybackEnded()),SLOT(PlaybackEnded()));
connect(player2,SIGNAL(OnPlaybackEnded()),SLOT(PlaybackEnded()));

connect(player1,SIGNAL(TimerTick()),SLOT(PlayerTimerTick()));
connect(player2,SIGNAL(TimerTick()),SLOT(PlayerTimerTick()));

connect(playlist,SIGNAL(OnTimerTick()),SLOT(PlaylistTimerTick()));
tim = new QDateTime();


/*QMenu **/menu = new QMenu(tr("Playback"), this);
ui->menuBar->addMenu(menu);

//QAction *a;
a = new QAction( QIcon(":/images/play.png"),tr("Play"), this);
a->setShortcut(QKeySequence(tr("Ctrl+P")));
connect(a, SIGNAL(triggered()), this, SLOT(PlayButton()));
ui->toolBar->addAction(a);
menu->addAction(a);

a = new QAction( QIcon(":/images/next.png"),tr("Next Track"), this);
a->setShortcut(QKeySequence(tr("Ctrl+N")));
connect(a, SIGNAL(triggered()), this, SLOT(NextButton()));
ui->toolBar->addAction(a);
menu->addAction(a);

a = new QAction( QIcon(":/images/stop.png"),tr("Stop"), this);
a->setShortcut(QKeySequence(tr("Ctrl+S")));
connect(a, SIGNAL(triggered()), this, SLOT(StopButton()));
ui->toolBar->addAction(a);
menu->addAction(a);

menu->addSeparator();
ui->toolBar->addSeparator();

a = new QAction( QIcon(":/images/random.png"),tr("Random List"), this);
a->setShortcut(QKeySequence(tr("Ctrl+R")));
connect(a, SIGNAL(triggered()), this, SLOT(RandButton()));
ui->toolBar->addAction(a);
menu->addAction(a);

a = new QAction( QIcon(":/images/microphone.png"),tr("Mic On/Off"), this);
a->setShortcut(QKeySequence(tr("Ctrl+M")));
connect(a, SIGNAL(triggered()), this, SLOT(MicButton()));
ui->toolBar->addAction(a);
menu->addAction(a);



QLabel *volpic= new QLabel();
volpic->setPixmap(QPixmap(":/images/volume.png"));
vol = new QSlider();
connect(vol, SIGNAL(sliderMoved(int)), this, SLOT(MainVol(int)));
vol->setMaximum(100);
vol->setMinimum(-1);
vol->setValue(100);
vol->setMaximumWidth(200);
vol->setMinimumWidth(150);
vol->setMaximumHeight(200);
//vol->setMinimumWidth(150);
vol->setOrientation(Qt::Horizontal);
ui->volcontrol->addWidget(volpic);
ui->volcontrol->addWidget(vol);
//ui->volcontrol->setMinimumWidth(150);
connect(ui->volcontrol, SIGNAL(orientationChanged(Qt::Orientation)), this, SLOT(SpOrientation(Qt::Orientation)));




time = new QLabel(this);
ui->TimeBar->addWidget(time);
time->setText("<html><head/><body><p><span style=\" font-size:12pt; color:#19a6fe;\">00:00:00</span></p></body></html>");
//ui->TimeBar->
ui->TimeBar->move(ui->TimeBar->pos().x()+150,ui->TimeBar->pos().y());


ui->TestButton->hide();



window()->showMaximized();
}

MBCWindow::~MBCWindow()
{
    delete ui;
}

void MBCWindow::TestButton()
{
//playlist->DeleteSelected();
library->LoadList();
}

void MBCWindow::PlaybackEnded()
{
    if(playing)
    {

        Next();
    }
}

 int MBCWindow::GetPlayerActive()
 {
     if((player1->status==4)||(player1->status==2)||(player1->status==3))
     {
        return 1;
     }
     else
         if((player2->status==4)||(player2->status==2)||(player2->status==3))
         {
            return 2;
         }
            else
             return 2; //если первый плеер свободен и второй, то воспроизведение начнется с первого //return 0;
 }

 void MBCWindow::Next() //переход на след трек
 {
   song so;


 if((djpanel->ListAuto())&&(playlist->count()<1)) Random10Playlist();

     SetUpTransition();


     if(playlist->count()>0)
     {
     playing=true;

     so=playlist->GetTopItem();
     playlist->DeleteTopItem();

     if(so.name=="***Jingle***") //if jingle - is next element
     {
         SetFastTransition();
     }

     if (GetPlayerActive()==1)
     {
         player1->EndPlayback();
         player2->LoadFile(so.path);
         player2->SetTag(so.name);
         enclist->SetEncodersTag(so.name);
         player2->PlayLoadedFile();
         playlist->SetLen(player2->length,player2->pos);
     }
     else
     {
         player2->EndPlayback();
         player1->LoadFile(so.path);
         player1->SetTag(so.name);
         enclist->SetEncodersTag(so.name);
         player1->PlayLoadedFile();
         playlist->SetLen(player1->length,player1->pos);
     }

     }
     else
     {
         playing=false;
     }


     if(jingles->CheckJingleTime())
     {
         song res=jingles->next;
         playlist->AddItem(res.name,res.path,res.duration,0);
     }


plhist->AddItem(so.name,so.path,so.duration,tim->currentDateTime().toString("hh:mm:ss"));

 }

 void MBCWindow::NextButton()
 {
     Next();
 }

 void MBCWindow::PlayButton()
 {
    Play();
 }

 void MBCWindow::StopButton()
 {
     Stop();
 }

 void MBCWindow::RandButton()
 {
     Random10Playlist();
 }

 void MBCWindow::MicButton()
 {
    djpanel->ToggleMicState(!djpanel->IsMicOn());
 }

 void MBCWindow::Play() //начать воспроизведение
 {

     SetUpTransition();
     song so;
     if(playlist->count()>0)
     {
     playing=true;

     so=playlist->GetTopItem();
     playlist->DeleteTopItem();
     playlist->SetLen(player1->length,player1->pos);
         player1->StopPlaying();
         player1->Reset();
         player2->StopPlaying();
         player2->Reset();
         player1->LoadFile(so.path);
         player1->SetTag(so.name);
         enclist->SetEncodersTag(so.name);
         player1->PlayLoadedFile();
     }
     else
     {
         playing=false;
     }
     plhist->AddItem(so.name,so.path,so.duration,tim->currentDateTime().toString("hh:mm:ss"));

 }

 void MBCWindow::Stop() //Остановка воспроизведения
 {
     player1->StopPlaying();
     player1->Reset();
     player2->StopPlaying();
     player2->Reset();
     playing=false;
 }

 void MBCWindow::SetUpTransition()
 {
     if(config->TransType() == 1) //простой переход трек-трек
     {
         player1->SetTransitionParams(1,0);
         player1->SetEndFlag(2,config->ST());
         player2->SetTransitionParams(1,0);
         player2->SetEndFlag(2,config->ST());
     }

     if(config->TransType() == 2) //переход трек-возрастающий
     {
         if(GetPlayerActive()==1)
         {
             player1->SetTransitionParams(1,0);
             player1->SetEndFlag(2,config->ST());
             player2->SetTransitionParams(2,config->TT());
             player2->SetEndFlag(2,config->ST());
         }
         else
         {
             player2->SetTransitionParams(1,0);
             player2->SetEndFlag(2,config->ST());
             player1->SetTransitionParams(2,config->TT());
             player1->SetEndFlag(2,config->ST());
         }
     }

     if(config->TransType() == 3) //переход убывающий-трек
     {
         if(GetPlayerActive()==1)
         {
             player2->SetTransitionParams(1,0);
             player2->SetEndFlag(2,config->ST());
             player1->SetTransitionParams(2,config->TT());
             player1->SetEndFlag(2,config->ST());
         }
         else
         {
             player1->SetTransitionParams(1,0);
             player1->SetEndFlag(2,config->ST());
             player2->SetTransitionParams(2,config->TT());
             player2->SetEndFlag(2,config->ST());
         }
     }

     if(config->TransType() == 4) //переход убывающий-возрастающий
     {
             player1->SetTransitionParams(2,config->TT());
             player1->SetEndFlag(2,config->ST());
             player2->SetTransitionParams(2,config->TT());
             player2->SetEndFlag(2,config->ST());
     }


 }

 void MBCWindow::SetFastTransition()
 {
     player1->SetTransitionParams(2,1000);
     player1->SetEndFlag(2,1);
     player2->SetTransitionParams(2,1000);
     player2->SetEndFlag(2,1);
 }


 void MBCWindow::Random10Playlist()
 {
     if(library->count()>0)
     {
     int i=0;
     int x=0;
     while(1)
     {
         if(i>15) break;


     song so;
     so=library->GetRandomItem();
     if(!playlist->ListHaveIt(so.path))
      {
         if(i!=1)
       playlist->AddItem(so.name,so.path,so.duration);
       i++;
      }
     x++;

     if((x>library->count())&&(library->count()<=15)) break;

     if(x>500) break;

     }
     }



 }

 bool MBCWindow::RunEntity(QString entity)
 {
     if(!IsAEntity(entity)) return false;
     entity=entity.remove(0,entity.indexOf(":"));

     if(entity=="stop")
     {
        Stop();
        return true;
     }

     if(entity=="random")
     {
        RandButton();
        return true;
     }

     if(entity=="stop")
     {
        Stop();
        return true;
     }

     return false;
 }

 bool MBCWindow::IsAEntity(QString entity)
 {
     if(entity.contains("entity:"))
         return true;

     return false;
 }


 void MBCWindow::SpOrientation(Qt::Orientation orientation)
 {
vol->setOrientation(orientation);

if (orientation== Qt::Vertical)
{
 vol->setMinimumWidth(0);
}
else
{
vol->setMinimumWidth(150);
}
 }

 void MBCWindow::MainVol(int vol)
 {
BASS_ChannelSetAttribute(main,BASS_ATTRIB_VOL,float(vol)/100);
 }

 void MBCWindow::PlayerTimerTick()
 {
     if (GetPlayerActive()==1)
     {
         playlist->SetLen(player1->length,player1->pos);
         // QMessageBox::about(NULL,"asd",QString::number((player1->pos))+" "+QString::number((player1->length)));
     }
     else
     {
        playlist->SetLen(player2->length,player2->pos);
     }

// micpanel->Update();

 }


 void MBCWindow::PlaylistTimerTick()
 {

    // qint64 tim= QDateTime::toLocalTime ().toMSecsSinceEpoch();
     enclist->UpdateInfo();

   // ui->pages->find(enclist->winId())->
     if(enclist->EncodersWork())
     {
         if(encicons==1)
         {
         ui->pages->setTabIcon(ui->pages->indexOf(enclist),QIcon(":/images/recorda.png"));
         }

         if(encicons>=2)
         {
         ui->pages->setTabIcon(ui->pages->indexOf(enclist),QIcon(":/images/recordd.png"));
         encicons=0;
         }
         encicons++;
     }
    else
     {
    ui->pages->setTabIcon(ui->pages->indexOf(enclist),QIcon(":/images/recordd.png"));
     }
     time->setText("<html><head/><body><p><span style=\" font-size:12pt; color:#19a6fe;\">"+tim->currentDateTime().toString("hh:mm:ss") +"</span></p></body></html>");
     //delete tim;


     jingles->CheckPatterns();

 }



 void MBCWindow::OnSlienceCh(int vol,bool state)
 {
     if(state)
     {
        player1->TransToVol(float(float(vol)/float(100)),1000);
        player2->TransToVol(float(float(vol)/float(100)),1000);

        //QMessageBox::about(NULL,"asd",QString::number());

     }
     else
     {
         player1->TransToDef();
         player2->TransToDef();
     }
 }


 void MBCWindow::OnMicState(int state)
 {
     if(state==1)
     {
        micpanel->OnMicOn();
     }
     else
     {
        micpanel->OnMicOff();
     }
 }

 void MBCWindow::ShowM()
 {
     show();
 }

 void MBCWindow::HideM()
 {
     hide();
 }

 void MBCWindow::ExitM()
 {
     QApplication::exit();
 }

 void MBCWindow::closeEvent(QCloseEvent *event)
 {

     hide();
     event->ignore();
     tray->showMessage("Mixer Broadcaster 3","Application minimized to tray.",QSystemTrayIcon::Information,1000);

 }
