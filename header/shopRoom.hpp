#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.hpp"
#include "shop.hpp"
#include "boundaryShopMenu.hpp"
#include "player.hpp"

class ShopRoom : public Room {
private:
    Shop roomShop;

public:
    ShopRoom() {}               // optional constructor
    void TriggerEncounter(Player& player) override;
};

#endif // SHOPROOM_H
