#ifndef BOUNDARY_SHOP_MENU_H
#define BOUNDARY_SHOP_MENU_H

#include <iostream>
#include "shop.hpp"
#include "player.hpp"

class BoundaryShopMenu {
private:
    int selectionChoice;

public:
    BoundaryShopMenu(): selectionChoice(0) {}

    void checkShop(Shop& shop, Player& player);
    void checkInventory(Player& player);
};

#endif
