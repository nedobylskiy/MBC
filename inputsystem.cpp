#include "inputsystem.h"
#include "ui_inputsystem.h"
#include <QMessageBox>


BOOL CALLBACK RecordingCallback(HRECORD handle, const void *buffer, DWORD length, void *user)
{
    return TRUE; // continue recording
}



InputSystem::InputSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputSystem)
{
    ui->setupUi(this);
    ui->micoff->setDisabled(true);
    ui->micon->setDisabled(false);
    ui->pmicon->hide();
    ui->pmicoff->show();
    ui->listWidget->setDisabled(false);

    ui->left->hide();
    ui->right->hide();
connect(ui->micon,SIGNAL(clicked()),SLOT(OnMicOn()));
connect(ui->micoff,SIGNAL(clicked()),SLOT(OnMicOff()));
connect(ui->vol,SIGNAL(sliderMoved(int)),SLOT(OnVolSet(int)));



}


InputSystem::~InputSystem()
{
    delete ui;
}

void InputSystem::RefreshList()
{
ui->listWidget->clear();


//ui->listWidget->addItem("<b>asd</b>");

//ui->listWidget->item(1)->setToolTip();


int a, count=0;
BASS_DEVICEINFO info;
for (a=0; BASS_RecordGetDeviceInfo(a, &info); a++)
    if (info.flags&BASS_DEVICE_ENABLED) // device is enabled
    {
        count++; // count it
        ui->listWidget->addItem("(Device)"+QString::fromAscii(info.name));
        ui->listWidget->item(ui->listWidget->count()-1)->setToolTip(QString::number(a));

        BASS_RecordInit(a);
        BASS_RecordSetDevice(a);

        int c;
        const char *i;
        for (c=0;i=BASS_RecordGetInputName(c);c++)
        {
           // ui->listWidget->addItem("      (Input)"+QString::fromAscii(i));
            if (!(BASS_RecordGetInput(c,NULL)&BASS_INPUT_OFF)) // this 1 is currently "on"
            {
                ui->listWidget->addItem("      (Input)"+QString::fromAscii(i));
                ui->listWidget->item(ui->listWidget->count()-1)->setToolTip(QString::number(c));
            }
        }

        //BASS_RecordFree();


    }

//ui->listWidget->setCurrentIndex(ui->listWidget->rootIndex());

ui->listWidget->setCurrentRow(0,QItemSelectionModel::Select);
}

void InputSystem::OnMicOn()
{

QString devn;
int dev;


if(ui->listWidget->selectedItems().count()>0)
{

    devn=ui->listWidget->selectedItems().first()->text();


    if(devn.contains("Device",Qt::CaseInsensitive))
    {


        dev=ui->listWidget->selectedItems().first()->toolTip().toInt();
        BASS_ChannelStop(dev);


        if(!BASS_RecordSetDevice(dev))
        {

            QMessageBox::about(this,"Input Init Error","Error Code: "+QString::number(BASS_ErrorGetCode()));
            return;
        }

        BASS_RecordFree();
        BASS_RecordInit(dev);
        BASS_RecordSetDevice(dev);

    }

    RunRecord();
    ui->micoff->setDisabled(false);
    ui->micon->setDisabled(true);
    ui->listWidget->setDisabled(true);
    ui->pmicon->show();
    ui->pmicoff->hide();

}

}

void InputSystem::OnMicOff()
{
    StopRecord();
    ui->micoff->setDisabled(true);
    ui->micon->setDisabled(false);
    ui->listWidget->setDisabled(false);
    ui->pmicon->hide();
    ui->pmicoff->show();
}

void InputSystem::OnVolSet(int vol)
{
     BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,float(vol)/100);
}

void InputSystem::SetMainStream(HSTREAM mains)
{
    main=mains;
}

void InputSystem::RunRecord()
{
    stream = BASS_RecordStart(44100, 2, 0, NULL, NULL);
   // QMessageBox::about(this,"Record Start Error","Error Code: "+QString::number(BASS_ErrorGetCode()));
    BASS_Mixer_StreamAddChannel(main,stream,BASS_STREAM_AUTOFREE);

    BASS_ChannelSetAttribute(stream,BASS_ATTRIB_VOL,float(ui->vol->value())/100);

}

void InputSystem::StopRecord()
{
    BASS_Mixer_ChannelRemove(stream);


}

void InputSystem::Update()
{
    DWORD level, left, right;
    level=BASS_ChannelGetLevel(stream);
    left=LOWORD(level); // the left level
    right=HIWORD(level); // the right level

    ui->left->setValue(left);
    ui->right->setValue(right);
}

