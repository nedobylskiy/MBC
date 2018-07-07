#ifndef PREVIEWPLAYER_H
#define PREVIEWPLAYER_H

#include <QWidget>
#include <QTimer>
#include <QThread>


#include "bass.h"

namespace Ui {
class PreViewPlayer;
}

class BufferThreads;
class PreViewPlayer : public QWidget
{
    Q_OBJECT
    
public:
    explicit PreViewPlayer(QWidget *parent = 0);
    ~PreViewPlayer();
    
    QString currentfile,tag;
    int length,pos,allowupdate,bufer;
    void LoadFile(QString file);
    void PlayFile();
    void Stop();

private:
    Ui::PreViewPlayer *ui;
    HSTREAM stream;
    QTimer *updatetmr;
    int buferplayrequest;
    BufferThreads* buffering;
private slots:
    void UpdateTimer();
    void TrackPosChange();
    void TrackPosPressed();
    void VolumeChange();
    void BufferComplete();
    void PlayButton();
    void StopButton();
    void HideButton();
signals:
    void closed();


};

class BufferThreads : public QThread
{
    Q_OBJECT
public:
   QString file;
   HSTREAM stream;

protected:
    void run();
};

#endif // PREVIEWPLAYER_H
