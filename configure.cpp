#include "configure.h"
#include "ui_configure.h"
#include <QFile>

Configure::Configure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Configure)
{
    ui->setupUi(this);
    MyFile = QCoreApplication::applicationDirPath()+"/config";
     connect(ui->saveb,SIGNAL(clicked()),SLOT(OnSaveBut()));
     connect(ui->reset,SIGNAL(clicked()),SLOT(OnResetBut()));
}

Configure::~Configure()
{
    delete ui;
}

void Configure::LoadConfig()
{
    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::ReadOnly | QIODevice::Text))
             return;

    QString content,tempn,tempp;
    int i=0,count=0;

    content = fil.readAll();

    tempp=ExtractPParam(content,"ttype");
    if(!tempp.isEmpty())
    {
        //tempp=ExtractPParam(content,"ttype");

        if(tempp.contains("1"))
            ui->t1->setChecked(true);
        if(tempp.contains("2"))
            ui->t2->setChecked(true);
        if(tempp.contains("3"))
            ui->t3->setChecked(true);
        if(tempp.contains("4"))
            ui->t4->setChecked(true);
        ui->tt->setValue(ExtractPParam(content,"tt").toInt());
        ui->st->setValue(ExtractPParam(content,"st").toInt());

    }

    fil.close();
    }
}

void Configure::SaveConfig()
{
    if(MyFile.length()>0)
    {
    QFile fil(MyFile);

    if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

  fil.write(AddPParam("tt", QString::number(ui->tt->value())).toAscii());
  fil.write(AddPParam("st", QString::number(ui->st->value())).toAscii());

  if(ui->t1->isChecked())
      fil.write(AddPParam("ttype","1").toAscii());
  if(ui->t2->isChecked())
      fil.write(AddPParam("ttype","2").toAscii());
  if(ui->t3->isChecked())
      fil.write(AddPParam("ttype","3").toAscii());
  if(ui->t4->isChecked())
      fil.write(AddPParam("ttype","4").toAscii());
    fil.close();
    }
}

int Configure::TransType()
{
    if(ui->t1->isChecked())
        return 1;
    if(ui->t2->isChecked())
        return 2;
    if(ui->t3->isChecked())
        return 3;
    if(ui->t4->isChecked())
        return 4;
}

int Configure::TT()
{
    return ui->tt->value();
}

int Configure::ST()
{
        return ui->st->value();
}

void Configure::OnSaveBut()
{
    SaveConfig();
}

void Configure::OnResetBut()
{
    LoadConfig();
}

QString Configure::ExtractPParam(QString content, QString key)
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

QString Configure::AddPParam(QString key, QString value)
{
      return "<!--!"+key+"!{"+value+"}-->";
}
