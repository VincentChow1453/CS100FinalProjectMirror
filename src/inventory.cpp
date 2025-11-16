#include "inventory.hpp"
#include <iostream>


void Inventory::addItem(const Item& item) { 
    items.push_back(item); 
}

void Inventory::removeItem(int index) {
        if (index >= 0 && index < items.size())
            items.erase(items.begin() + index);
}

void Inventory::displayInventory() const{
    if (items.empty()){
        cout << "inventory is empty" << endl;
        return;
    }

    else {
        for (int i = 0; i < items.size(); i++) {
            cout << i << ": " << items[i].name << " (Price: " << items[i].price << ")" << endl;
        }
    }
}