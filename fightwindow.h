#ifndef FIGHTWINDOW_H
#define FIGHTWINDOW_H

#include <QDialog>
#include "Character.h"
#include "Room.h"

namespace Ui {
class FightWindow;
}

class FightWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FightWindow(Room* room,QWidget *parent = nullptr);
    ~FightWindow();
    void updateCharacterHealth(int newHealth);
    void updateEnemyHealth(int newHealth);
    void handleFightEnd(bool playerWon);

private:
    Ui::FightWindow *ui;
    Room* fightRoom;
    Character player;
    bool bossFight = false;
};

#endif // FIGHTWINDOW_H
