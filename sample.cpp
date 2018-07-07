#include "sample.h"
#include "ui_sample.h"
#include "bass.h"
#include "bassmix.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

Sample::Sample(int num) :
    QWidget(0),
    ui(new Ui::Sample)
{
    n=num;
    ui->setupUi(this);
    //ui->stop->hide();

    QFile fil(QCoreApplication::applicationDirPath()+"/sample"+QString::number(n));
    if (fil.open(QIODevice::ReadOnly| QIODevice::Text))
    {
    file=fil.readAll();
    fil.close();
    }

   connect(ui->browse, SIGNAL(clicked()), this, SLOT(OnBrowse()));
    connect(ui->play, SIGNAL(clicked()), this, SLOT(OnPlay()));
}

Sample::~Sample()
{
    delete ui;
}

void Sample::SetN(int ns)
{
    n=ns;
}

void Sample::SetMainStream(HSTREAM mains)
{
    main=mains;
    //QMessageBox::about(NULL,"asd",QString::number(main));
}

void Sample::PlayLoadedFile()
{
    HSTREAM stream = BASS_StreamCreateFile(FALSE,file.toAscii(), 0, 0,/*BASS_SAMPLE_FLOAT || BASS_MIXER_BUFFER ||*/ BASS_STREAM_DECODE);

    BASS_Mixer_StreamAddChannel(main,stream,BASS_STREAM_AUTOFREE | BASS_MIXER_BUFFER);

}

void Sample::LoadFile()
{
    QFileDialog *dlg = new QFileDialog(this,Qt::Dialog);
    dlg->setNameFilter(tr("Sound Files (*.mp3 *.wav *.ogg)"));
    dlg->setFileMode(QFileDialog::ExistingFile);
    dlg->setWindowTitle("Load Sample");
    dlg->setAcceptMode(QFileDialog::AcceptOpen);


    QStringList fileNames;
     if ( dlg->exec())
     {
         fileNames = dlg->selectedFiles();

         file=fileNames.first();

     }


     QFile fil(QCoreApplication::applicationDirPath()+"/sample"+QString::number(n));

     if (!fil.open(QIODevice::WriteOnly | QIODevice::Text))
              return;
     fil.write(file.toAscii());
     fil.close();
}

void Sample::OnBrowse()
{
    LoadFile();
}

void Sample::OnPlay()
{
    PlayLoadedFile();
}
