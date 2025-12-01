#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.hpp"
#include "Shop.hpp"
#include "ShopMenu.hpp"
#include "CharacterClass.hpp"

class ShopRoom : public Room {
private:
    Shop roomShop;

public:
    ShopRoom() {}
    void TriggerEncounter(CharacterClass& player);  
};

#endif
