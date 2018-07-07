#include "player1.h"
#include "ui_player1.h"

Player1::Player1(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Player1)
{
    ui->setupUi(this);
}

Player1::~Player1()
{
    delete ui;
}
