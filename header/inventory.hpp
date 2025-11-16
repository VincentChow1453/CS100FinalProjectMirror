#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;
#include <vector>
#include "itemStub.hpp"

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item) { items.push_back(item); }

    void removeItem(int index) {
        if (index >= 0 && index < items.size())
            items.erase(items.begin() + index);
    }

    void displayInventory() const;
};

#endif
