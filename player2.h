#ifndef PLAYER2_H
#define PLAYER2_H

#include <QDialog>
#include "bass.h"
#include <QThread>


namespace Ui {



class Player2;

}



class BufferThread;

class Player2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit Player2(QDialog *parent = 0);
    ~Player2();
    void LoadFile(QString file);
    void PlayLoadedFile();
    void StopPlaying();
    void Reset();
    void SetTag(QString tagg);
    void SetTittle(QString tittle);
    void SetEndFlag(int type,int time);
    void SetTransitionParams(int type,int time);
    void SetMainStream(HSTREAM mains);
    void EndPlayback();
    void TransToVol(float vol,int time);
    void TransToDef();

    HSTREAM stream;
    HSTREAM main;
    QString currentfile,tag;
    int length,pos,allowupdate;
    int status; //0 = none,1=loaded,2=playing,3=buffering,4=transition,5=error
    int endtype,endtime;
    int transtype,transtime;
    int voldef;


private:
    Ui::Player2 *ui;
    QTimer* updatetmr;
    BufferThread* buffering;
    int bufer;
    int buferplayrequest;
    HSYNC syn;
    static void CALLBACK EndOfFile(HSYNC handle, DWORD channel, DWORD data, void *user);

private slots:
   void UpdateTimer();
   void TrackPosChange();
   void TrackPosPressed();
   void VolumeChange();
   void BufferComplete();
   void PlaybackEnded();
   void PlaybackCallback();

signals:
void OnPlaybackEnded();
void TimerTick();




};

class BufferThread : public QThread
{
    Q_OBJECT
public:
   QString file;
   HSTREAM stream;

protected:
    void run();
};

#endif // PLAYER2_H
