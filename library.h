#ifndef LIBRARY_H
#define LIBRARY_H

#include <QWidget>
#include <QTreeWidget>
#include "playlist.h"
#include "previewplayer.h"
#include <QProgressDialog>

namespace Ui {
class Library;
class TreeWidget;
}

class TreeWidget : public QTreeWidget
{
     Q_OBJECT

    public:
    explicit TreeWidget(QWidget *parent = 0);

    protected:
        void dropEvent(QDropEvent *event);
        void keyPressEvent(QKeyEvent* event);
signals:
       void OnDragDrop();
       void OnKeyPress(QKeyEvent* event);

};

class Library : public QWidget
{
    Q_OBJECT
    
public:
    explicit Library(QWidget *parent = 0);
    ~Library();
    QString file;

    void AddItem(QString name,QString path, int duration);
    int count();
    void DeleteTopItem();
    song GetTopItem();
    void Mirror(); //not used
    void clear();
    void DeleteSelected();
    void RenameItem(int i); //not used
    void RenameItemDlg();
    void AssignToFile(QString filef);
    void SaveList();
    void LoadList();
    PreViewPlayer *player;
    void FileFolderFind(const QString& sDir);
    bool FFFStop;
     QProgressDialog *progress;
     int fff1,fff2;
     song GetRandomItem(int from=0);

    
private:
    Ui::Library *ui;
    QString Sec22TimeStr(int sec);
    QMenu *menu;
    TreeWidget *treeWidget;
    TreeWidget *sresult;
    static QString ExtractPParam(QString content,QString key);
    static QString AddPParam(QString key,QString value);
private slots:
    void MenuDelete();
    void MenuClear();
    void MenuRun(const QPoint & pos);
    void MenuToTop();
    void UpdateTimer();
    void AddFilesButton();
    void AddUrlButton();
    void AddFolderButton();
    void SearchButton();
    QString ExtractTags(QString file);
    int GetStreamSecLength(QString file);
    void OnTreeDragDrop();
    void OnTreeKeyPress(QKeyEvent* event);
    void OnSearchTreeKeyPress(QKeyEvent* event);
    void OnSearchText();
    void OnFFFCancel();
signals:
    void OnTimerTick();
};



#endif // LIBRARY_H
