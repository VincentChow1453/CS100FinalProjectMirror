#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "item.h"

class Shop {
private:
    std::vector<Item> catalogue;

    public:
    Shop() {}

    void buyItem(int option);
    void sellItem(int option);
    void displayItems() const;
    };

#endif // SHOP_H