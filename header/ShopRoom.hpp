#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.hpp"
#include "Shop.hpp"
#include "ShopMenu.hpp"
#include "CharacterClass.hpp"
#include "CharacterSelectMenu.hpp"

class ShopRoom : public Room {
private:
    Shop roomShop;

public: 
    ShopRoom() {}
    void TriggerRoom() override;  
    void OutputMapSymbol() const override;
};

#endif