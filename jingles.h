#ifndef JINGLES_H
#define JINGLES_H

#include <QWidget>
#include "bass.h"
#include "bassmix.h"
#include "player2.h"
#include "playlist.h"


namespace Ui {
class Jingles;
}

class Jingles : public QWidget
{
    Q_OBJECT
    
public:
    explicit Jingles(QWidget *parent = 0);
    ~Jingles();
    QString file;
    int mcount;
    int order;
    HSTREAM main;
    void SetMainStream(HSTREAM mains);
    bool CheckJingleTime();
    song next;
    song GenerateNewItem();
    void AssignToFile(QString filef);
    void LoadConfig();
    void SaveConfig();
    int CheckPatternActive(QString pattern);
    void CheckPatterns();
    Player2*jinplayer;

    
private:
    Ui::Jingles *ui;
    static QString ExtractPParam(QString content,QString key);
    static QString AddPParam(QString key,QString value);


private slots:
    void OnAddJingles();
    void OnDeleteJingles();
    void OnAddJingles2();
    void OnDeleteJingles2();
    void OnPlayerStops();
    int GetStreamSecLength(QString file);
    void OnChanges();
    bool PatContentsNum(QString pat, int num);
signals:
    void OnSilence(int,bool);
};

#endif // JINGLES_H
