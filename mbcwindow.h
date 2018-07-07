#ifndef MBCWINDOW_H
#define MBCWINDOW_H

#include <QMainWindow>
#include "bass.h"
#include "bassmix.h"
#include <QSlider>
#include <QLabel>
#include <QSplitter>
#include <QTabWidget>
#include <QSystemTrayIcon>
#include "player2.h"
#include "playlist.h"
#include "library.h"
#include "inputsystem.h"
#include "encoderslist.h"
#include "configure.h"
#include "vk.h"
#include "djpanel.h"
#include "jingles.h"
#include "playlisthistory.h"


#ifdef _WIN32
#include "wskype.h"
#endif

namespace Ui {
class MBCWindow;
}

class MBCWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MBCWindow(QWidget *parent = 0);
    ~MBCWindow();

    bool playing;
    QString ExtractTags(QString file);
    HSTREAM main;
    int GetPlayerActive();
    void Next();
    void Play();
    void Stop();

    void SetUpTransition();
    void SetFastTransition();

    void Random10Playlist();

    bool RunEntity(QString entity);
    bool IsAEntity(QString entity);


    Player2 *player1;
    Player2 *player2;
    PlayList*playlist;
    Library*showlist;
    Library *library;
    QSplitter *splitter;
    InputSystem*micpanel;
    EncodersList *enclist;
    DJPanel*djpanel;

    #ifdef _WIN32
    WSkype*skype;
    #endif

    Jingles*jingles;
    PlaylistHistory*plhist;

 //   QTabWidget *pages;

    int encicons;
    //bool encerr;

    VK *vk;

    Configure*config;

    QSystemTrayIcon *tray;



    
private:
    Ui::MBCWindow *ui;
    QSlider *vol;
    QLabel *time;
    QDateTime *tim;
private slots:
    void TestButton();
    void PlaybackEnded();
    void NextButton();
    void PlayButton();
    void StopButton();
    void RandButton();
    void MicButton();
    void MainVol(int vol);
    void SpOrientation(Qt::Orientation orientation );
    void PlayerTimerTick();
    void PlaylistTimerTick();

    void OnSlienceCh(int vol, bool state);
    void OnMicState(int state);



     void ShowM();
     void HideM();
     void ExitM();

protected:
     void closeEvent(QCloseEvent *event);



};

#endif // MBCWINDOW_H
