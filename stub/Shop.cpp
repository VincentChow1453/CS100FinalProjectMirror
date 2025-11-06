#include "Shop.h"
#include <iostream>

void Shop::buyItem(int option) {
    std::cout << "Buying item: " << option << "\n";
}

void Shop::sellItem(int option) {
    std::cout << "Selling item: " << option << "\n";
}

void Shop::displayItems() const {
    std::cout << "Shop Catalogue:\n";
    for (const auto& item : catalogue) {
        item.displayInventory();
    }
}   