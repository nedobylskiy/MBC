#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <QWidget>
#include "bass.h"
#include "bassmix.h"

namespace Ui {
class InputSystem;
}

class InputSystem : public QWidget
{
    Q_OBJECT
    
public:
    explicit InputSystem(QWidget *parent = 0);
    ~InputSystem();
    HSTREAM stream;
    HSTREAM main;
    void RefreshList();
    void SetMainStream(HSTREAM mains);
    void RunRecord();
    void StopRecord();
    void Update();

    
private:
    Ui::InputSystem *ui;

public slots:
    void OnMicOn();
    void OnMicOff();
    void OnVolSet(int vol);
};

#endif // INPUTSYSTEM_H
