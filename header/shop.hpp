#ifndef SHOP_H
#define SHOP_H


#include <vector>
#include "ItemClass.hpp"
#include "Items.hpp"
#include "characterClass.h"

class Shop {
private:
    vector<string> catalogue;


public:
    Shop();
    void addItem(const string& item);
    void buyItem(int option, CharacterClass& player);
    void sellItem(const string& itemName, CharacterClass& player);
    void displayItems();
};

#endif
