#ifndef VK_H
#define VK_H

#include <QWidget>
#include <QUrl>
#include <QtNetwork>
#include <QFile>
#include "library.h"
#include "previewplayer.h"

namespace Ui {
class VK;
}

class VK : public QWidget
{
    Q_OBJECT
    
public:
    explicit VK(QWidget *parent = 0);
    ~VK();
    QString access_token;
    //QHttp *http;
    QString lastjsonrequest;
    PreViewPlayer *player;
    bool logined;
    void Athorized();
    void AddItem(QString name,QString path, int duration);
    void VKSearch(QString q);

    
private:
    Ui::VK *ui;
    QFile file;
    QMenu *menu;
     QString Sec22TimeStr(int sec);
     TreeWidget *treeWidget;
public slots:
    void urllChanged(QUrl url);
    void reqFinished(bool err);
    void SerFild();
    void AuthBut();
    void Additional();
    void VKBut();
   void OnTreeKeyPress(QKeyEvent* event);
   void Download();


};

#endif // VK_H
