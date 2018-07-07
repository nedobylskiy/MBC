#include "encoderslist.h"
#include "ui_encoderslist.h"
#include "bass.h"
#include "encoder.h"
#include <QFile>
#include <QMessageBox>

EncodersList::EncodersList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EncodersList)
{
    ui->setupUi(this);
    ui->encoders->removeItem(0);
    encoders=0;
   /* AddNewEncoder();
    AddNewEncoder();*/


    connect(ui->AddEncoder,SIGNAL(clicked()),SLOT(OnAddEncoder()));
    connect(ui->DeleteEncoder,SIGNAL(clicked()),SLOT(OnDeleteEncoder()));
    connect(ui->sall,SIGNAL(clicked()),SLOT(OnStartAll()));
    connect(ui->stall,SIGNAL(clicked()),SLOT(OnStopAll()));
}

EncodersList::~EncodersList()
{
    delete ui;
}

void EncodersList::SetMainStream(HSTREAM mains)
{
    main=mains;

}

int EncodersList::AddNewEncoder()
{
    if(encoders+1>=200)
    {
        return -1;
    }
    encoder[encoders] = new Encoder();
    encoder[encoders]->SetEncoderNum(encoders);
    encoder[encoders]->SetEncoderFile(QCoreApplication::applicationDirPath()+"/encoder"+QString::number(encoders+1));
    encoder[encoders]->LoadSettings();
    encoder[encoders]->SetMainStream(main);
   // QMessageBox::about(this,"MAIN","Stream: "+QString::number(main));

    connect(encoder[encoders],SIGNAL(OnEncoderStarted(int)),SLOT(EncoderStarted(int)));
    connect(encoder[encoders],SIGNAL(OnEncoderStopped(int)),SLOT(EncoderStopped(int)));
    connect(encoder[encoders],SIGNAL(OnEncoderError(int)),SLOT(EncoderError(int)));
    ui->encoders->addItem(encoder[encoders],QIcon(":/images/recordd.png"),"Encoder "+QString::number(encoders+1));
    encoders++;
    SaveConfig();
    return encoders;
}

int EncodersList::DeleteEncoder(int enc)
{
    if(encoders-1<0)
    {
       return -1;
    }
ui->encoders->removeItem(enc);
delete encoder[enc];
encoders--;
    SaveConfig();
return encoders;
}

void EncodersList::SetListFile(QString file)
{
    MyFile=file;
}

void EncodersList::LoadConfig()
{
    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QString content,tempn,tempp;
    int i=0,count=0;

    content = fil.readAll();

    count=ExtractPParam(content,"count").toInt();

    if (count>0)
    {
    while(1)
        {
        AddNewEncoder();
        if(i>=count-1) break;
        i++;
        }
    }

    fil.close();
    }
}

void EncodersList::SaveConfig()
{
    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
             return;
    fil.write(AddPParam("count",QString::number(encoders)).toAscii());
    fil.close();
    }
}

void EncodersList::UpdateInfo()
{
int i=0;



if (encoders>0)
{
while(1)
    {
     //QMessageBox::about(this,"Encoders","n "+QString::number(i));
    encoder[i]->UpdateData();
    if(i>=encoders-1) break;
    i++;
    }
}

}

void EncodersList::SetEncodersTag(QString tag)
{
    int i=0;
    if (encoders>0)
    {
    while(1)
        {
        encoder[i]->SetEncoderTag(tag);
        if(i>=encoders-1) break;
        i++;
        }
    }
}

void EncodersList::StartAll()
{
    int i=0;
    if (encoders>0)
    {
    while(1)
        {
        encoder[i]->StartEncoder();
        if(i>=encoders-1) break;
        i++;
        }
    }
}

void EncodersList::StopAll()
{
    int i=0;
    if (encoders>0)
    {
    while(1)
        {
        encoder[i]->StopEncoder();
        if(i>=encoders-1) break;
        i++;
        }
    }
}

bool EncodersList::EncodersWork()
{
    int i=0;
    if (encoders>0)
    {
    while(1)
        {
        if(encoder[i]->working==1)
            return true;
        if(i>=encoders-1) break;
        i++;
        }
    }
    return false;
}

QString EncodersList::ExtractPParam(QString content, QString key)
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

QString EncodersList::AddPParam(QString key, QString value)
{
    return "<!--!"+key+"!{"+value+"}-->";
}

void EncodersList::OnAddEncoder()
{
    AddNewEncoder();
}

void EncodersList::OnDeleteEncoder()
{

DeleteEncoder(ui->encoders->count()-1);

}

void EncodersList::EncoderStarted(int enc)
{
    ui->encoders->setItemIcon(enc,QIcon(":/images/record.png"));
}

void EncodersList::EncoderStopped(int enc)
{
    ui->encoders->setItemIcon(enc,QIcon(":/images/recordd.png"));
}

void EncodersList::EncoderError(int enc)
{
     ui->encoders->setItemIcon(enc,QIcon(":/images/error.png"));
     emit OnEncoderError();
}

void EncodersList::OnStartAll()
{
    StartAll();
}

void EncodersList::OnStopAll()
{
    StopAll();
}


