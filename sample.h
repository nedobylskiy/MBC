#ifndef SAMPLE_H
#define SAMPLE_H

#include <QWidget>
#include "bass.h"

namespace Ui {
class Sample;
}

class Sample : public QWidget
{
    Q_OBJECT
    
public:
    explicit Sample(int num = 0);
    ~Sample();
    HSTREAM main;
    int n;
    QString file;
    void SetN(int ns);
    void SetMainStream(HSTREAM mains);
    void PlayLoadedFile();
    void LoadFile();
    
private:
    Ui::Sample *ui;

private slots:
    void OnBrowse();
    void OnPlay();
};

#endif // SAMPLE_H
