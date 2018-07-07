#include "player2.h"
#include "ui_player2.h"
#include "bass.h"
#include "bassmix.h"
#include <QTimer>
#include <QThread>
#include <QMessageBox>


QString Sec2TimeStr(int sec)
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


void Player2::SetTransitionParams(int type,int time) //настройки плавного перехода. Скорость затухания и восстановления
{
    //type=1 - моментальный переход без затуханий
    //type=2 - плавный переход по времени
transtype=type;

if(type==2)
{
transtime=time;
}

}


void Player2::SetEndFlag(int type,int time) //настройки конца трека. имитирует окончание трека за несколько секунд до реального конца для плавного перехода
{
    //type=1 - использовать событие окончание трека, игнорировать время.
    //type=2 - генерировать событие окончания трека за time секунд до конца
endtype=type;

if(time<1) //если время слишком мало, то всё равно придется переключить на тип 1
    type=1;

if(type==2)
{
endtime=time;
}

}

void Player2::PlaybackCallback()
{
    if(endtype==1) //если обработка события включена
    {
    PlaybackEnded();
    }
}

int eofflag=0;
void CALLBACK Player2::EndOfFile(HSYNC handle, DWORD channel, DWORD data, void *user) //событие конца трека генерируемое BASS
{
   /*  Player2 pl;
    pl.PlaybackCallback();*/
eofflag=1;
    //QMessageBox::about(NULL, tr("OLOLO"),"Callback");
}

Player2::Player2(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Player2)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Tool);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint & ~Qt::WindowMaximizeButtonHint  & ~Qt::WindowMinimizeButtonHint);


    status=0;
    allowupdate=1;
    bufer=0;
    buferplayrequest=0;
    endtype=1;
    endtime=1;
    transtype=1;
    transtime=1;
    length=0;
    pos=0;

    ui->volume->setValue(100);
    ui->trackPos->setValue(100);
    ui->Name->setText("xxxxxxxx-xxxxxxxx");
    ui->web->hide();
    ui->cpu->hide();
    ui->stopped->show();
    ui->playing->hide();


    buffering=new BufferThread;
    connect(buffering, SIGNAL(finished()), SLOT(BufferComplete()));
    updatetmr = new QTimer(this);
    connect(updatetmr, SIGNAL(timeout()), SLOT(UpdateTimer()));
    updatetmr->start(60);
    connect(ui->trackPos, SIGNAL(sliderReleased()), SLOT(TrackPosChange()));
    connect(ui->trackPos, SIGNAL(sliderPressed()), SLOT(TrackPosPressed()));
    connect(ui->volume, SIGNAL(sliderMoved(int)), SLOT(VolumeChange()));
}

Player2::~Player2()
{
    delete ui;
}

void Player2::UpdateTimer()
{
    DWORD level, left, right;


    if(((status==2)||(status==4))&&(allowupdate==1))
    {
        length = (int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetLength(stream, BASS_POS_BYTE));
        pos=(int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetPosition(stream, BASS_POS_BYTE));
    ui->trackPos->setValue(pos);
    level=BASS_Mixer_ChannelGetLevel(stream);

    left=LOWORD(level); // the left level
    right=HIWORD(level); // the right level

    ui->v1->setValue(left);
    ui->v2->setValue(right);

    if((length>0)) //если это играет бесконечный поток
      {
        ui->Time->setText(Sec2TimeStr(pos)+"/"+Sec2TimeStr(length));
      }
       else
      {
        ui->Time->setText(Sec2TimeStr(pos)+"/"+"Radio");
      }

    //***CPU***
    /*float cpu;
    BASS_ChannelGetAttribute(stream,BASS_ATTRIB_CPU,&cpu);
    ui->cpu->setText("<html><head/><body><p><span style=\" font-size:6pt;\">CPU:"+QString::number((int)(cpu*100)-100)+"%</span></p></body></html>");
    */



    }

    //*******Обработка конца трека*******
    if((status==2))
    {

        if ((eofflag==1)&&(endtype==1))
        {
        eofflag=0;
        status=4;
        PlaybackCallback();
        }

        if(endtype==2)
        {
            if((length-pos<=endtime)&&(length>0))
            {
            status=4;
            eofflag=0;
            PlaybackEnded();
            }

        }

    }

  /*  if(status==4)
    {
    length = (int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetLength(stream, BASS_POS_BYTE));
    pos=(int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetPosition(stream, BASS_POS_BYTE));
     ui->Name->setText(Sec2TimeStr(pos)+"/"+Sec2TimeStr(length));
    }*/

    //ui->Name->setText(QString::number(status));
 emit TimerTick();
}

void Player2::LoadFile(QString file)
{


//BASS_ChannelStop(stream);
BASS_ChannelRemoveSync(stream,syn);
BASS_Mixer_ChannelRemove(stream);
BASS_StreamFree(stream);

currentfile = file;


if(bufer==1)
{
bufer=0;
buffering->terminate();
}

if((file.contains("http://"))||(file.contains("https://"))||(file.contains("ftp://")))
{
status = 3;
bufer=1;
ui->Time->setText("Buferring...");
ui->web->show();
buffering->file = file;
buffering->start();


//stream =  BASS_StreamCreateURL(file.toAscii(),0,BASS_SAMPLE_FLOAT,NULL,NULL);
//stream = BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,BASS_SAMPLE_FLOAT);
}
else
{
stream = BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,/*BASS_SAMPLE_FLOAT || BASS_MIXER_BUFFER ||*/ BASS_STREAM_DECODE);
ui->web->hide();
status = 1;
bufer=0;
}


length = (int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetLength(stream, BASS_POS_BYTE));
ui->trackPos->setMaximum(length);
}

void Player2::PlayLoadedFile()
{
if(status==1)
{
status=2;
ui->stopped->hide();
ui->playing->show();
//BASS_ChannelStop(stream);
//BASS_ChannelPlay(stream,false);
BASS_Mixer_StreamAddChannel(main,stream,BASS_STREAM_AUTOFREE | BASS_MIXER_BUFFER);
syn=BASS_ChannelSetSync(stream,BASS_SYNC_FREE,0,Player2::EndOfFile, NULL);

if(transtype==1)
  {
    BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,float(ui->volume->value())/100);
  }
if(transtype==2)
  {
   BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,0);
   BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL, float(ui->volume->value())/100, transtime);
  }
//QMessageBox::about(NULL, tr("Synced"),"Callback");
}
else
{
    if(status==3)
  buferplayrequest=1;
}


}

void Player2::StopPlaying()
{
BASS_ChannelRemoveSync(stream,syn);
BASS_Mixer_ChannelRemove(stream);
BASS_StreamFree(stream);
status=0;
}

void Player2::Reset()
{
    ui->stopped->show();
    ui->playing->hide();
    status=0;
    allowupdate=1;
    bufer=0;
    length=0;
    pos=0;
    buferplayrequest=0;
    ui->trackPos->setValue(0);
    ui->trackPos->setMaximum(2);
    ui->Name->setText("xxxxxxxx-xxxxxxxx");
    ui->Time->setText("00:00/00:00");
    ui->web->hide();

}

void Player2::TrackPosChange()
{
    allowupdate=1;
    BASS_ChannelSetPosition(stream,BASS_ChannelSeconds2Bytes(stream,ui->trackPos->value()),BASS_POS_BYTE);
}

void Player2::TrackPosPressed()
{
    allowupdate=0;
}

void Player2::VolumeChange()
{
    //BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,float(ui->volume->value())/100);
    BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL, float(ui->volume->value())/100, 100);
}

void Player2::SetTag(QString tagg)
{
tag=tagg;
ui->Name->setText(tag);
}


 void Player2::BufferComplete()
 {
    bufer=0;
    status=1;
    stream = buffering->stream;

    ui->Time->setText("Buffered.");
    length = (int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetLength(stream, BASS_POS_BYTE));
    ui->trackPos->setMaximum(length);
    if(buferplayrequest==1)
    {
        PlayLoadedFile();
    }
 }

void BufferThread::run()
{
stream =  BASS_StreamCreateURL(file.toAscii(),0,BASS_STREAM_DECODE ,NULL,NULL);
}

void Player2::PlaybackEnded()
{

    if(status==4)
    {
        emit OnPlaybackEnded();

     }
if(transtype==2)
  {
   BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL,0, transtime);
  }

Reset();
BASS_ChannelRemoveSync(stream,syn);
return;
}

void Player2::EndPlayback()
{

    ui->stopped->show();
    ui->playing->hide();

    BASS_ChannelRemoveSync(stream,syn);

if(transtype==2)
  {
   BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL,0, transtime);
  }
else
    StopPlaying();


Reset();



return;
}

void Player2::TransToVol(float vol, int time)
{
voldef=ui->volume->value();
BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL,vol, time);
ui->volume->setValue(int(vol*100));

if(status!=2)
{
    StopPlaying();
}

}

void Player2::TransToDef()
{
    //voldef=ui->volume->value();
    BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL,float(voldef/100), 1000);
    ui->volume->setValue(voldef);


    if(status!=2)
    {
        StopPlaying();
    }
}

void Player2::SetTittle(QString tittle)
{
setWindowTitle(tittle);
ui->title->setTitle(tittle);
}

void Player2::SetMainStream(HSTREAM mains)
{
main=mains;
}
