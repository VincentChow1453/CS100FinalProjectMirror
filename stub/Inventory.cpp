#include "Inventory.h"
#include <iostream>

void Inventory::displayInventory() const {
    std::cout << "Inventory Items:\n";
    for (const auto& item : inventory) {
        item.displayInventory();
    }
}