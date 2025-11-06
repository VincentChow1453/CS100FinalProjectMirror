#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
private:
    int which_item;

    public:
    void useItem(int which_item);
    void back(); 
    void displayInventory() const;
};
#endif // ITEM_H