#ifndef BATTLEMENU_HPP
#define BATTLEMENU_HPP

#include "MonsterStats.hpp"

class BattleMenu {
private:
    int selection_choice;
    MonsterStats monster;

public:
    BattleMenu(const MonsterStats& m);

    void displayMenu() const;
    void chooseOption(int selection_choice);
    void run();
};

#endif
