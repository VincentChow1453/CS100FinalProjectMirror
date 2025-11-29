#ifndef SHOP_H
#define SHOP_H


#include <vector>
#include "ItemClass.hpp"
#include "Items.hpp"
#include "player.hpp"

class Shop {
private:
    vector<Item> catalogue;

public:
    Shop();
    void addItem(string item);
    void buyItem(int index);
    void sellItem(int index, Player& player);
    void displayItems();
};

#endif
