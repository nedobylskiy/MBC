#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QMenu>
#include <QDateTime>
#include <QTreeWidget>

//#include "library.h"
struct song
{
  int duration;
  QString path,name,started;

  //bool fasttrans;
};


namespace Ui {
class PlayList;
class TreeWidgetPL;
}

class TreeWidgetPL : public QTreeWidget
{
     Q_OBJECT

    public:
    explicit TreeWidgetPL(QWidget *parent = 0);

    protected:
        void dropEvent(QDropEvent *event);
        void keyPressEvent(QKeyEvent* event);
signals:
       void OnDragDrop();
       void OnKeyPress(QKeyEvent* event);

};

class PlayList : public QWidget
{
    Q_OBJECT
    
public:
    explicit PlayList(QWidget *parent = 0);
    ~PlayList();
    int length;
    int spos;
    QString file;

    void AddItem(QString name,QString path, int duration,int index=-1);
    int count();
    void DeleteTopItem();
    song GetTopItem();
    void Mirror(); //not used
    void clear();
    void DeleteSelected();
    void SetLen(int dlen,int dpos);
    void AssignToFile(QString filef);
    void RenameItemDlg();
    void SaveList();
    void LoadList();
    song GetRandomItem(int from);
    bool ListHaveIt(QString path);


private:
    Ui::PlayList *ui;
    TreeWidgetPL *treeWidget;
     QString Sec22TimeStr(int sec);
     QMenu *menu;
     QString ExtractPParam(QString content,QString key);
     QString AddPParam(QString key,QString value);
private slots:
     void MenuDelete();
     void MenuClear();
     void MenuRun(const QPoint & pos);
     void MenuToTop();
     void MenuRename();
     void UpdateTimer();
      void OnTreeKeyPress(QKeyEvent* event);
signals:
     void OnTimerTick();
};

#endif // PLAYLIST_H
