#include "ItemClass.hpp"

Item::Item(){
    name = "Item";
    price = 0;
}

Item::Item(string name, int price){
    this->name = name;
    this->price = price;
}
