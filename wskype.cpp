#include "wskype.h"
#include "ui_wskype.h"
#include <QMessageBox>


#define SPort 37216

WSkype::WSkype(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WSkype)
{
    ui->setupUi(this);

    ui->onair->hide();
    ui->nonair->show();

 skpsock = new QTcpServer(this);
 connect(skpsock, SIGNAL(newConnection()), this, SLOT(OnSConnect()));

 SkpServ = new QProcess(parent);
 connect(SkpServ, SIGNAL(finished(int,QProcess::ExitStatus)),this, SLOT(SkpServFinished(int,QProcess::ExitStatus)));

 connect(ui->rings, SIGNAL(stateChanged(int)), this, SLOT(OnCallToAir()));
 connect(ui->mc, SIGNAL(stateChanged(int)), this, SLOT(OnMuteCall()));

}

WSkype::~WSkype()
{
    delete ui;
}

void WSkype::SetMainStream(HSTREAM mains)
{
    main=mains;
}

void WSkype::OnSConnect()
{
    skype= BASS_StreamCreate(16000,1,BASS_STREAM_DECODE ,STREAMPROC_PUSH,0);
    splitter = BASS_Split_StreamCreate(skype,BASS_STREAM_DECODE,0);
    BASS_Mixer_StreamAddChannel(main,splitter, BASS_MIXER_BUFFER | BASS_MIXER_LIMIT);
   // QMessageBox::about(NULL,"asd","Smb Connected");
    ui->onair->show();
    ui->nonair->hide();
    client = skpsock->nextPendingConnection();
    connect(client, SIGNAL(readyRead()), this, SLOT(OnSData()));
    connect(client, SIGNAL(disconnected()), this, SLOT(OnSDisconnect()));
    emit OnSilence(15,true);

}

void WSkype::OnSDisconnect()
{
    ui->onair->hide();
    ui->nonair->show();
    BASS_Mixer_ChannelRemove(splitter);
    emit OnSilence(100,false);
}

void WSkype::OnSData()
{
   QByteArray temp;
  // QTcpSocket *client = skpsock->nextPendingConnection();
   temp = client->readAll();
   BASS_StreamPutData(skype, temp, temp.length());
}

void WSkype::OnCallToAir()
{
    if(ui->rings->isChecked())
    {
        skpsock->listen(QHostAddress::Any,SPort);
        SkpServ->start("SkypeServ");
    }
    else
    {
        skpsock->close();
        SkpServ->kill();
    }
}

void WSkype::SkpServFinished(int,QProcess::ExitStatus)
{
    ui->rings->setChecked(false);
}

void WSkype::OnMuteCall()
{
    if(ui->mc->isChecked())
    {
    BASS_ChannelSetAttribute(splitter,BASS_ATTRIB_VOL,0);
    }
    else
    {
    BASS_ChannelSetAttribute(splitter,BASS_ATTRIB_VOL,1);
    }
}
