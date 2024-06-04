#include "endscreen.h"
#include "ui_endscreen.h"

EndScreen::EndScreen(bool win,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EndScreen)
{

    ui->setupUi(this);
    if(win){
        ui->lblWinLose->setText("You WIN!");
    }
}

EndScreen::~EndScreen()
{
    delete ui;
}
