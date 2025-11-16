#ifndef SHOPROOM_H
#define SHOPROOM_H

#include "Room.hpp"        // or "Room.h", depending on your naming
#include "Shop.hpp"
#include "BoundaryShopMenu.hpp"
#include "Player.hpp"

class ShopRoom : public Room {
private:
    Shop roomShop;   // The shop attached to this room

public:
    ShopRoom() {}    // Optional constructor

    virtual void triggerEncounter() override;
};

#endif
