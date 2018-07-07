#ifndef ENCODER_H
#define ENCODER_H

#include <QWidget>
#include <QThread>
#include "bass.h"
#include "bassmix.h"
#include "bassenc.h"

namespace Ui {
class Encoder;
}
class BufferThreade;

class Encoder : public QWidget
{
    Q_OBJECT
    
public:
    explicit Encoder(QWidget *parent = 0);
    ~Encoder();
    int num;
    QString MyFile,lame,aac,currtag;
    HSTREAM main;
    HENCODE encoder;
    char *formatt;
    int buffering,bufferingerr;
    int working;

    void SetMainStream(HSTREAM hmain);
    void SetEncoderNum(int n);
    void SetEncoderFile(QString file);
    void SetEncoderTag(QString tag);
    void SaveSettings();
    void LoadSettings();
    void StartEncoder();
    void StopEncoder();
    void UpdateData();

    QString ExtractPParam(QString content,QString key);
    QString AddPParam(QString key,QString value);
    
private:
    Ui::Encoder *ui;
    BufferThreade *buffer;
public slots:
    void OnEncoderStartBut();
    void OnEncoderStopBut();
    void OnEncoderStartError();
    void OnQuaChange();
    void BufferComplete();


    void /*CALLBACK*/ EncodeNotifyProc(
        HENCODE handle,
        DWORD status,
        void *user
    );

signals:
    void OnEncoderStopped(int);
    void OnEncoderStarted(int);
    void OnEncoderError(int);

};


class BufferThreade : public QThread
{
    Q_OBJECT
public:
   QString file,tag;
   HENCODE encoder;
   HSTREAM main;
   int lasterror;
   int job;


   void SetJob(int j);


   void SetEncParams(QString cmdlinee, HENCODE handlee,HSTREAM maine,
                     QString servere,
                     QString passe,
                     QString contente,
                     QString namee,
                     QString urle,
                     QString genree,
                     QString desce,
                     DWORD bitratee, QString t);

private:
 /*  char *server;
   char *pass;
   char *content;
   char *name;
   char *url;
   char *genre;
   char *desc;
   char *headers;
   DWORD bitrate;
   char *cmdline;*/

   QString cmdline;
                        QString server;
                        QString pass;
                        QString content;
                        QString name;
                        QString url;
                        QString genre;
                        QString desc;
                        DWORD bitrate;
protected:
    void run();

signals:
    void OnEncoderError();
};
#endif // ENCODER_H
