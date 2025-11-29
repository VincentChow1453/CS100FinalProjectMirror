#include "shop.hpp"
#include <iostream>
using namespace std;

Shop::Shop() {
    addItem("Wooden Sword");
    addItem("Stone Sword");
    addItem("Metal Sword");
    addItem("Light Armor");
    addItem("Heavy Armor");
    addItem("Bandage");
    addItem("Health Potion");
}

void Shop::addItem(string itemName){
    Item* item = getItemByName(itemName);

    if (item != nullptr){
        catalogue.push_back(*item);
    }
    else {
        cout << "ITEM: " << itemName << " NOT FOUND!" << endl;
    }
}

// displays shoplist
void Shop::displayItems() {
    cout << "\n===== SHOP ITEM LIST =====\n";
    for (unsigned int i = 0; i < catalogue.size(); i++){
        cout << i << ": " << catalogue[i].name << " (" << catalogue[i].price << ") gold\n";
    }

    cout << "===========================\n";
}

// TEMP BUY — Just prints what was chosen
void Shop::buyItem(int option) {
    cout << "[TEMP] buyItem() called with option = " << option << endl;
    cout << "[TEMP] This feature is not implemented yet.\n";
}

// TEMP SELL — Just prints what was chosen
void Shop::sellItem(int option, Player& player) {
    cout << "[TEMP] sellItem() called with option = " << option << endl;
    cout << "[TEMP] This feature is not implemented yet.\n";

    // Optional: show player gold
    cout << "[TEMP] Player gold: " << player.getGold() << endl;
}
