#ifndef DJPANEL_H
#define DJPANEL_H

#include <QWidget>
#include "bass.h"
#include "sample.h"

namespace Ui {
class DJPanel;
}

class DJPanel : public QWidget
{
    Q_OBJECT
    
public:
    explicit DJPanel(HSTREAM mains = 0);
    ~DJPanel();
        HSTREAM main;

void SetMainStream(HSTREAM mains);
bool ListAuto();
void ToggleMicState(bool state);
bool IsMicOn();

private:
    Ui::DJPanel *ui;
    Sample *sample[5];

private slots:
    void OnSilenceCh();
    void OnMicCh();
    void OnAutCh();
    void OnNotepadChanged();



signals:
    void OnSilence(int,bool);
    void OnMicStatus(int);

};

#endif // DJPANEL_H
