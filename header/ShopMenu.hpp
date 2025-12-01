#ifndef BOUNDARY_SHOP_MENU_H
#define BOUNDARY_SHOP_MENU_H

#include <iostream>
#include "shop.hpp"
#include "characterClass.h"

class BoundaryShopMenu {
private:
    int selectionChoice;

public:
    BoundaryShopMenu() : selectionChoice(0) {}

    void checkShop(Shop& shop, CharacterClass& player);
    void checkInventory(CharacterClass& player);
};

#endif
