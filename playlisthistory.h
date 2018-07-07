#ifndef PLAYLISTHISTORY_H
#define PLAYLISTHISTORY_H

#include <QWidget>
#include "library.h"
#include "previewplayer.h"

namespace Ui {
class PlaylistHistory;
}

class PlaylistHistory : public QWidget
{
    Q_OBJECT
    
public:
    explicit PlaylistHistory(QWidget *parent = 0);
    ~PlaylistHistory();
    TreeWidget *treeWidget;
   void AddItem(QString name,QString path, int duration, QString started);
   QString Sec22TimeStr(int sec);
    
private:
    Ui::PlaylistHistory *ui;
};

#endif // PLAYLISTHISTORY_H
