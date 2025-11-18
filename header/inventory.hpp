#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;
#include <vector>
#include "itemStub.hpp"

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item);
    int size() const { return items.size(); } // added a size function to get how many items in inv
    void removeItem(int index);

    void displayInventory() const;
};

#endif
