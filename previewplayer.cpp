#include "previewplayer.h"
#include "ui_previewplayer.h"
#include "bass.h"
#include <QTimer>
#include <QThread>
#include <QMessageBox>


PreViewPlayer::PreViewPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreViewPlayer)
{
    ui->setupUi(this);
    updatetmr = new QTimer(this);
    connect(updatetmr, SIGNAL(timeout()), SLOT(UpdateTimer()));
    updatetmr->start(1000);
    buferplayrequest=false;
    allowupdate=1;
    ui->buff->hide();


    buffering=new BufferThreads;
    connect(buffering, SIGNAL(finished()), SLOT(BufferComplete()));

    connect(ui->position, SIGNAL(sliderReleased()), SLOT(TrackPosChange()));
    connect(ui->position, SIGNAL(sliderPressed()), SLOT(TrackPosPressed()));
    connect(ui->vol, SIGNAL(sliderMoved(int)), SLOT(VolumeChange()));

    connect(ui->play, SIGNAL(clicked()), SLOT(PlayButton()));
    connect(ui->stop, SIGNAL(clicked()), SLOT(StopButton()));
    connect(ui->hide, SIGNAL(clicked()), SLOT(HideButton()));
}

void PreViewPlayer::UpdateTimer()
{
    if(allowupdate==1)
    {
    length = (int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetLength(stream, BASS_POS_BYTE));
    pos=(int)BASS_ChannelBytes2Seconds(stream,BASS_ChannelGetPosition(stream, BASS_POS_BYTE));
    ui->position->setValue(pos);
    ui->position->setMaximum(length);
    }
}

void PreViewPlayer::TrackPosChange()
{
    allowupdate=1;
    BASS_ChannelSetPosition(stream,BASS_ChannelSeconds2Bytes(stream,ui->position->value()),BASS_POS_BYTE);

}

void PreViewPlayer::TrackPosPressed()
{
    allowupdate=0;
}

void PreViewPlayer::VolumeChange()
{
    BASS_ChannelSlideAttribute(stream, BASS_ATTRIB_VOL, float(ui->vol->value())/100, 100);
}

void PreViewPlayer::BufferComplete()
{
    if(buferplayrequest==true)
    {
    bufer=0;
    stream = buffering->stream;
    ui->buff->hide();
       PlayFile();
    }
      ui->buff->hide();
}

void PreViewPlayer::PlayButton()
{
    PlayFile();
}

void PreViewPlayer::StopButton()
{
    Stop();
}

void PreViewPlayer::HideButton()
{
    Stop();
    emit closed();
    hide();
}

PreViewPlayer::~PreViewPlayer()
{
    delete ui;
}

void PreViewPlayer::LoadFile(QString file)
{
currentfile=file;
BASS_ChannelStop(stream);
BASS_StreamFree(stream);


if(buferplayrequest==true)
{
    buferplayrequest=false;
    buffering->terminate();

}

if((file.contains("http://"))||(file.contains("https://"))||(file.contains("ftp://")))
{
/*
status = 3;
bufer=1;
ui->Time->setText("Buferring...");
ui->web->show();
buffering->file = file;
buffering->start();*/

    ui->buff->show();
 buffering->file = file;
 buffering->start();
bufer=1;
}
else
{
stream = BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,0);
bufer=0;
}

}

void BufferThreads::run()
{
stream =  BASS_StreamCreateURL(file.toAscii(),0,0 ,NULL,NULL);
}

void PreViewPlayer::PlayFile()
{
allowupdate=1;
BASS_ChannelPlay(stream,false);
BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,float(ui->vol->value())/100);

if(bufer==1)
{
    buferplayrequest=true;
}

}

void PreViewPlayer::Stop()
{
    BASS_ChannelStop(stream);
  //  BASS_StreamFree(stream);
}
