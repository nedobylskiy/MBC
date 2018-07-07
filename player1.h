#ifndef PLAYER1_H
#define PLAYER1_H

#include <QDockWidget>

namespace Ui {
class Player1;
}

class Player1 : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit Player1(QWidget *parent = 0);
    ~Player1();
    
private:
    Ui::Player1 *ui;
};

#endif // PLAYER1_H
