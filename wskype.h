#ifndef WSKYPE_H
#define WSKYPE_H

#include <QWidget>
#include "bass.h"
#include "bassmix.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QProcess>

namespace Ui {
class WSkype;
}

class WSkype : public QWidget
{
    Q_OBJECT
    
public:
    explicit WSkype(QWidget *parent = 0);
    ~WSkype();
    HSTREAM skype,splitter,main;
    void SetMainStream(HSTREAM mains);
    QTcpSocket *client;
    QTcpServer *skpsock;
    QProcess *SkpServ;
    
private:
    Ui::WSkype *ui;

private slots:
    void OnSConnect();
    void OnSDisconnect();
    void OnSData();
    void OnCallToAir();
    void SkpServFinished(int, QProcess::ExitStatus);
    void OnMuteCall();
signals:
    void OnSilence(int,bool);

};

#endif // WSKYPE_H
