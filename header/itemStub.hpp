#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
using namespace std;

class Item {

    public:
    string name;
    int price;

    Item();
    Item(string item, int price);
};



#endif