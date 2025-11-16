#ifndef SHOP_H
#define SHOP_H


#include <vector>
#include "itemStub.hpp"
#include "player.hpp"

class Shop {
private:
    vector<Item> catalogue;

public:
    void buyItem(int option);
    void sellItem(int index, Player& player);
    void displayItems();
};

#endif
