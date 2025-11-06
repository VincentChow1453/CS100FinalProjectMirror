#include "item.h"
#include <iostream>


void Item::useItem(int which_item) {
    std::cout << "Using item: " << which_item << "\n";
}

void Item::back() {
    std::cout << "Going back from item menu.\n";
}

void Item::displayInventory() const {
    std::cout << "Item: " << which_item << "\n";
}