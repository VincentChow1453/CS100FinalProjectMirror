#ifndef BATTLEMENU_HPP
#define BATTLEMENU_HPP

#include "MonsterStats.hpp"

class Character; 

class BattleMenu {
private:
    int selection_choice;
    MonsterStats &monster;

public:
    BattleMenu(MonsterStats &m);
    void displayMenu() const;
    void chooseOption(int selection);
    void run(Character &player);
};

#endif
