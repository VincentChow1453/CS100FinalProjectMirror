#include "shopRoom.hpp"

void ShopRoom::TriggerEncounter(Player& player) {
    BoundaryShopMenu menu;
    menu.checkShop(roomShop, player);
}
