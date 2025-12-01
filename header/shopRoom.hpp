#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.hpp"
#include "shop.hpp"
#include "ShopMenu.hpp"
#include "CharacterClass.h"   // FIX: Player → CharacterClass

class ShopRoom : public Room {
private:
    Shop roomShop;

public:
    ShopRoom() {}
    void TriggerEncounter(CharacterClass& player);   // FIX: Player → CharacterClass
};

#endif
