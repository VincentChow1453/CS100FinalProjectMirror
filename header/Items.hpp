#ifndef ITEMS_HPP
#define ITEMS_HPP

#include "ItemClass.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Global array of hard-coded items
extern vector<Item> items;

// Helper function to ID items in other functions like buy and sell
Item* getItemByName(const string& name);
Item createItem(const string& name, int price, const string& type="", int amount=0);

#endif