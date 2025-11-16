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

    void removeItem(int index);

    void displayInventory() const;
};

#endif
