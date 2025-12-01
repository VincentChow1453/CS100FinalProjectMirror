#ifndef ITEMCLASS_HPP
#define ITEMCLASS_HPP

#include <iostream>
using namespace std;

class Item {

    public:
    string name;
    int price;
    string type;
    int amount;

    Item();
    Item(string item, int price, string type, int amount);
};



#endif