#include "djpanel.h"
#include "ui_djpanel.h"
#include "bass.h"
#include "bassmix.h"
#include "sample.h"
#include <QFile>

DJPanel::DJPanel(HSTREAM mains) :
    QWidget(0),
    ui(new Ui::DJPanel)
{
    main=mains;
    ui->setupUi(this);
    connect(ui->silence, SIGNAL(stateChanged(int)), this, SLOT(OnSilenceCh()));
    connect(ui->mic, SIGNAL(stateChanged(int)), this, SLOT(OnMicCh()));
    connect(ui->aut, SIGNAL(stateChanged(int)), this, SLOT(OnAutCh()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(OnNotepadChanged()));


    QFile fil(QCoreApplication::applicationDirPath()+"/notepad.htm");
    if (fil.open(QIODevice::ReadOnly| QIODevice::Text))
    {

    ui->textEdit->setHtml(fil.readAll());
    fil.close();
    }


    sample[0] = new Sample(0);
    sample[0]->SetMainStream(main);
    sample[0]->SetN(0);
    ui->Sampless->addWidget(sample[0]);

    sample[1] = new Sample(1);
    sample[1]->SetMainStream(main);
    sample[1]->SetN(1);
    ui->Sampless->addWidget(sample[1]);

    sample[2] = new Sample(2);
    sample[2]->SetMainStream(main);
    sample[2]->SetN(2);
    ui->Sampless->addWidget(sample[2]);

    sample[3] = new Sample(3);
    sample[3]->SetMainStream(main);
    sample[3]->SetN(3);
    ui->Sampless->addWidget(sample[3]);

}

DJPanel::~DJPanel()
{
    delete ui;
}

void DJPanel::SetMainStream(HSTREAM mains)
{
    main=mains;
}

bool DJPanel::ListAuto()
{
    return ui->rndlist->isChecked();
}

void DJPanel::ToggleMicState(bool state)
{
    ui->mic->setChecked(state);
}

bool DJPanel::IsMicOn()
{
    return ui->mic->isChecked();
}

void DJPanel::OnSilenceCh()
{
    if (ui->silence->isChecked())
    {
        emit OnSilence(ui->svol->value(),true);
    }
    else
    {
        emit OnSilence(ui->svol->value(),false);
    }
}

void DJPanel::OnMicCh()
{
    if(ui->mic->isChecked())
    {
        emit OnMicStatus(1);
        if(ui->aut->isChecked())
        {
            ui->silence->setChecked(true);
        }

    }
    else
    {
        emit OnMicStatus(0);
        if(ui->aut->isChecked())
        {
            ui->silence->setChecked(false);
        }
    }
}

void DJPanel::OnAutCh()
{
    //  ui->silence->setChecked(ui->aut->isChecked());
}

void DJPanel::OnNotepadChanged()
{

QFile fil(QCoreApplication::applicationDirPath()+"/notepad.htm");

if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
         return;
fil.write(ui->textEdit->toHtml().toAscii());
fil.close();

}


