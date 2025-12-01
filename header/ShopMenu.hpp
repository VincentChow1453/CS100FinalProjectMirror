#ifndef SHOP_MENU_H
#define SHOP_MENU_H

#include <iostream>
#include "Shop.hpp"
#include "CharacterClass.h"

class BoundaryShopMenu {
private:
    int selectionChoice;

public:
    BoundaryShopMenu() : selectionChoice(0) {}

    void checkShop(Shop& shop, CharacterClass& player);
    void checkInventory(CharacterClass& player);
};

#endif
