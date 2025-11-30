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

void Shop::addItem(const string& itemName){
    Item* item = getItemByName(itemName);

    if (item != nullptr){
        catalogue.push_back(itemName);
    }
    else {
        cout << "ITEM: " << itemName << " NOT FOUND!" << endl;
    }
}

// displays shoplist
void Shop::displayItems() {
    cout << "\n===== SHOP INVENTORY =====\n";

    for (int i = 0; i < catalogue.size(); i++) {
        // Each entry is a string (the name)
        string itemName = catalogue[i];

        // Lookup full item info
        Item* item = getItemByName(itemName);

        if (item) {
            cout << i << ": " << item->name << " (" << item->price << " gold)\n";
        }
    }

    cout << "===========================\n";
}

// Purchase Item Logic
void Shop::buyItem(int option, CharacterClass& player) {
    if (option < 0 || option >= catalogue.size()){
        cout << "Invalid Item\n";
        return;
    }

    string itemName = catalogue[option];
    Item * item = getItemByName(itemName);

    if (!item){
        cout << "Item was not found in database\n";
        return;
    }

    if (player.getGold() < item->price){
        cout << "Not enough gold to purchase!\n";
        return;
    }

    player.setGold(player.getGold() - item->price);

    player.addItem(itemName);

    cout << "Congrats! You purchased: " << itemName << " for " << item->price << " gold.\n";
}

// TEMP SELL — Just prints what was chosen
void Shop::sellItem(const string &itemName, CharacterClass& player) {
    cout << "[TEMP] sellItem() called with option = " << itemName << endl;
    cout << "[TEMP] This feature is not implemented yet.\n";

    // Optional: show player gold
    cout << "[TEMP] Player gold: " << player.getGold() << endl;
}
