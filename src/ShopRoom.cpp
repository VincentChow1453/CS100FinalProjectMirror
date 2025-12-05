#include "ShopRoom.hpp"

void ShopRoom::TriggerEncounter() {
    BoundaryShopMenu menu;
    menu.checkShop(roomShop, *player);
}
