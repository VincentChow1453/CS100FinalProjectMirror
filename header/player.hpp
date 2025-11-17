#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.hpp"

class Player {
private:
    int gold;

public:
    Inventory inv;
    Player();   // default starting gold

    // --- Gold interface ---
    int getGold() const;
    void addGold(int amount);
    bool spendGold(int amount);
};

#endif
