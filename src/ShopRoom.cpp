#include "ShopRoom.hpp"

void ShopRoom::TriggerEncounter(CharacterClass& player) {
    BoundaryShopMenu menu;
    menu.checkShop(roomShop, player);
}
void ShopRoom::OutputMapSymbol()const{
    cout<<"S";
}