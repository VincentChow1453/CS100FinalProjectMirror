#include "ShopRoom.hpp"

void ShopRoom::TriggerRoom() {
    BoundaryShopMenu menu;
    menu.checkShop(roomShop, *CharacterSelectMenu::player);
}
void ShopRoom::OutputMapSymbol()const{
    cout<<"S";
}