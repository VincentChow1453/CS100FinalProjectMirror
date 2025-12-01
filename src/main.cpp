#include "shop.hpp"
#include "boundaryShopMenu.hpp"
#include "characterClass.h"

int main() {
    CharacterClass player("Warrior", "John", 100, 50, 20, 1, 100);
    Shop shop;
    BoundaryShopMenu menu;

    menu.checkShop(shop, player);

    return 0;
}
