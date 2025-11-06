#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> inventory;
public:
    void displayInventory() const;
};
#endif // INVENTORY_H