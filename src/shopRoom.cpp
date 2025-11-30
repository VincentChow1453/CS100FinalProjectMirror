#include "shopRoom.hpp"

void ShopRoom::TriggerEncounter(CharacterClass& player) {
    BoundaryShopMenu menu;
    menu.checkShop(roomShop, player);
}
