#include "ItemClass.hpp"


// Constructors
Item::Item(){
    name = "Item";
    price = 0;
    type = "";
    amount = 0;
}

Item::Item(string name, int price, string type, int amount){
    this->name = name;
    this->price = price;
    this->type = type;
    this->amount = amount;
}
