#ifndef ITEMS_HPP
#define ITEMS_HPP

#include "ItemClass.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Global array of hard-coded items
extern vector<Item> items;
Item* getItemByName(const string& name);


#endif
