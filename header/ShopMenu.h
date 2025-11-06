#ifndef SHOPMENU_H
#define SHOPMENU_H

class ShopMenu {
private:
    int selection_choice;

public:
    ShopMenu() : selection_choice(0) {}

    void CheckShop(); 
    void CheckInv();  
};

#endif // SHOPMENU_H
