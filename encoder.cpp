#include "encoder.h"
#include "ui_encoder.h"
#include "bass.h"
#include "bassmix.h"
#include "bassenc.h"
#include <QFile>
#include <QMessageBox>
#include <QThread>

Encoder::Encoder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Encoder)
{
    ui->setupUi(this);

    lame="lame -r -s 44100 -b %i -";
    aac="";
connect(ui->StartEncoder,SIGNAL(clicked()),SLOT(OnEncoderStartBut()));
connect(ui->StopEncoder,SIGNAL(clicked()),SLOT(OnEncoderStopBut()));
connect(ui->quas,SIGNAL(sliderMoved(int)),SLOT(OnQuaChange()));

buffering=0;
buffer = new BufferThreade();
connect(buffer,SIGNAL(OnEncoderError()),SLOT(OnEncoderStartError()));
connect(buffer,SIGNAL(finished()),SLOT(BufferComplete()));

working=0;
}

Encoder::~Encoder()
{
    delete ui;
}

void Encoder::SetMainStream(HSTREAM hmain)
{
main = hmain;
}

void Encoder::SetEncoderNum(int n)
{
    num=n;
}

void Encoder::SetEncoderFile(QString file)
{
    MyFile=file;
}

void Encoder::SetEncoderTag(QString tag)
{

currtag=tag;
buffer->SetEncParams("none",encoder,0,"none","none","none","none","none","none","none",0,currtag);
//QMessageBox::about(this,"TAG","TAG: "+tag);
buffer->SetJob(1); //tag job
buffer->start();
}

void Encoder::SaveSettings()
{
    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

    if(ui->lame->isChecked())
        fil.write(AddPParam("encoder","LAME").toAscii());
   if(ui->aac->isChecked())
        fil.write(AddPParam("encoder","AAC").toAscii());
   if(ui->customr->isChecked())
      fil.write(AddPParam("encoder",ui->custom->text()).toAscii());

  fil.write(AddPParam("server",ui->server->text()).toAscii());
  fil.write(AddPParam("pass",ui->pass->text()).toAscii());
  fil.write(AddPParam("name",ui->name->text()).toAscii());
  fil.write(AddPParam("url",ui->url->text()).toAscii());
  fil.write(AddPParam("genre",ui->genre->text()).toAscii());
  fil.write(AddPParam("descr",ui->descr->text()).toAscii());
  fil.write(AddPParam("quality", QString::number(ui->quas->value())).toAscii());
    fil.close();
    }
}

void Encoder::LoadSettings()
{

    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QString content,tempn,tempp;
    int i=0,count=0;

    content = fil.readAll();

    tempp=ExtractPParam(content,"server");
    if(!tempp.isEmpty())
    {
        tempp=ExtractPParam(content,"encoder");
        if(tempp.contains("LAME"))
        {
            ui->lame->setChecked(true);
        }
        else
        {
            if(tempp.contains("AAC"))
            {
            ui->aac->setChecked(true);
            }
            else
            {
            ui->customr->setChecked(true);
            ui->custom->setText(tempp);
            }

        }

        ui->server->setText(ExtractPParam(content,"server"));
        ui->pass->setText(ExtractPParam(content,"pass"));
        ui->name->setText(ExtractPParam(content,"name"));
        ui->url->setText(ExtractPParam(content,"url"));
        ui->genre->setText(ExtractPParam(content,"genre"));
        ui->descr->setText(ExtractPParam(content,"descr"));
        ui->quas->setValue(ExtractPParam(content,"quality").toInt());
        OnQuaChange();
    }

    fil.close();
    }

}

/*
void Encoder::testbut()
{
    emit OnEncoderStarted(num);
}

void Encoder::testbut2()
{
    emit OnEncoderStopped(num);
    emit OnEncoderError(num);
}*/



void Encoder::StartEncoder()
{
    SaveSettings();
    QString encmd;
    if(ui->lame->isChecked())
    {
     //encmd=lame;
      encmd.sprintf(lame.toAscii(),ui->quas->value());
      formatt = BASS_ENCODE_TYPE_MP3;
    }
   if(ui->aac->isChecked())
    {

       encmd.sprintf(aac.toAscii(),ui->quas->value());
       formatt = BASS_ENCODE_TYPE_AAC;
   }
   if(ui->customr->isChecked())
   {
       encmd.sprintf(ui->custom->text().toAscii(),ui->quas->value());
       formatt = BASS_ENCODE_TYPE_MP3;
   }

buffering=1;
bufferingerr=0;
buffer->SetEncParams(encmd,encoder,main,ui->server->text(),ui->pass->text(),QString::fromAscii(formatt),ui->name->text(),ui->url->text(),ui->genre->text(),ui->descr->text(),(DWORD)ui->quas->value(),currtag);
buffer->SetJob(0); //encoder job
buffer->start();

    //QMessageBox::about(this,"MAIN","Stream: "+encmd);
 /*  encoder = BASS_Encode_Start(main,encmd.toAscii(),BASS_ENCODE_NOHEAD|BASS_ENCODE_FP_16BIT|BASS_ENCODE_QUEUE ,NULL, 0);
   if(encoder==0)
   {
       QMessageBox::about(this,"Start Encoder Error","Error Code: "+QString::number(BASS_ErrorGetCode()));
       emit OnEncoderError(num);
       return;
   }


   if(!BASS_Encode_CastInit(encoder,ui->server->text().toAscii(),ui->pass->text().toAscii(),formatt,ui->name->text().toAscii(),ui->url->text().toAscii(),ui->genre->text().toAscii(),ui->descr->text().toAscii(),"",ui->quas->value(),true))
{
    QMessageBox::about(this,"Cast Error","Error Code: "+QString::number(BASS_ErrorGetCode()));
    emit OnEncoderError(num);
    return;
}*/


ui->groupBox->setDisabled(true);
ui->groupBox_2->setDisabled(true);
ui->StartEncoder->setDisabled(true);
ui->StopEncoder->setDisabled(false);
}

void Encoder::StopEncoder()
{

    working=0;
    emit OnEncoderStopped(num);

    BASS_Encode_Stop(encoder);

    ui->groupBox->setDisabled(false);
    ui->groupBox_2->setDisabled(false);
    ui->StartEncoder->setDisabled(false);
    ui->StopEncoder->setDisabled(true);
}

QString Encoder::ExtractPParam(QString content, QString key)
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

QString Encoder::AddPParam(QString key, QString value)
{
    return "<!--!"+key+"!{"+value+"}-->";
}

void Encoder::OnEncoderStartBut()
{
    StartEncoder();
}

void Encoder::OnEncoderStopBut()
{
    StopEncoder();
}

void Encoder::OnEncoderStartError()
{
StopEncoder();
bufferingerr=1;
    emit OnEncoderError(num);
}

void Encoder::OnQuaChange()
{
    ui->qua->setText(QString::number(ui->quas->value()));
}

void Encoder::BufferComplete()
{
if(buffer->job==0)
{
encoder=buffer->encoder;
buffering=0;

if (bufferingerr==0)
{
    emit OnEncoderStarted(num);
working=1;
}
else
{

}
}
//BASS_Encode_SetNotify(encoder,&this->EncodeNotifyProc,NULL);

}

void Encoder::UpdateData()
{

    if(working==1)
    {

        if(BASS_Encode_IsActive(encoder)!=BASS_ACTIVE_PLAYING)
        {
 //QMessageBox::about(this,"Encoders","Not active "+QString::number(num));
            working=0;
            OnEncoderStartError();
        }
    }
}

void Encoder::EncodeNotifyProc(HENCODE handle, DWORD status, void *user) //NOT USED
{
    /*if(status==BASS_ENCODE_NOTIFY_ENCODER)
    {

         emit this->OnEncoderError(this->num);
    }

    if(status==BASS_ENCODE_NOTIFY_CAST)
    {
         OnEncoderStartError();
    }*/
}


 void BufferThreade::SetJob(int j)
 {
     job=j;
 }

void BufferThreade::SetEncParams(QString cmdlinee, HENCODE handlee,HSTREAM maine, QString servere, QString passe, QString contente, QString namee, QString urle, QString genree, QString desce, DWORD bitratee, QString t)
{

    cmdline=cmdlinee;
    encoder=handlee;
    server=servere;
    pass=passe;
    content=contente;
    name=namee;
    url=urle;
    genre=genree;
    desc=desce;
    bitrate=bitratee;
    main=maine;
    tag=t;

}

void BufferThreade::run()
{
    if(job==0)
    {
    encoder = BASS_Encode_Start(main,cmdline.toAscii(),BASS_ENCODE_NOHEAD|BASS_ENCODE_FP_16BIT|BASS_ENCODE_QUEUE ,NULL, 0);
    if(encoder==0)
    {

        lasterror=BASS_ErrorGetCode();
        emit OnEncoderError();
        return;
    }


  if(!BASS_Encode_CastInit(encoder,server.toAscii(),pass.toAscii(),content.toAscii(),name.toAscii(),url.toAscii(),genre.toAscii(),desc.toAscii(),"",bitrate,true))
 {

     lasterror=BASS_ErrorGetCode();
     emit OnEncoderError();
     return;
 }

  BASS_Encode_CastSetTitle(encoder,tag.toAscii(),NULL);

    }


    if(job==1)
    {
          BASS_Encode_CastSetTitle(encoder,tag.toAscii(),NULL);
    }



}


