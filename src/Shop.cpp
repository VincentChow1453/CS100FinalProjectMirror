#include "Shop.hpp"
#include <iostream>
using namespace std;

// Items in our shop
Shop::Shop() {
    catalogue = {
        "Wooden Sword",
        "Stone Sword",
        "Metal Sword",
        "Bandage",
        "Health Potion"
    };
}


// Adding manually
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

    // printing all items
    for (int i = 0; i < catalogue.size(); i++) {
        
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

    // error check
    if (option < 0 || option >= catalogue.size()){
        cout << "Invalid Item\n";
        return;
    }

    // fetching item "id"
    string itemName = catalogue[option];
    Item * item = getItemByName(itemName);

    if (!item){
        cout << "Item was not found.\n";
        return;
    }

    // insufficient balance
    if (player.getGold() < item->price){
        cout << "Not enough gold to purchase!\n";
        return;
    }

    // Purchase was successful, item is added to inv
    player.setGold(player.getGold() - item->price);
    player.addItem(itemName);

    cout << "Congrats! You purchased: " << itemName << " for " << item->price << " gold.\n";
}

// Sell Logic
void Shop::sellItem(const string &itemName, CharacterClass& player) {
    const vector<string>& inventory = player.getInventory();

    // find the item in player's inv
    int index = -1;
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == itemName) {
            index = i;
            break;
        }
    }

    // player doesn't have item
    if (index == -1){
        cout << "You don't have a " << itemName << " to sell.\n";
        return;
    }

    Item* item = getItemByName(itemName);
    if (!item) {
        cout << "Item not found in database. \n";
        return;
    }

    // Sell was successful, item is deleted from inv
    player.setGold(player.getGold() + item->price);
    player.removeItem(itemName);

    cout << "You sold a " << itemName << " for " << item->price << " gold.\n";

    // displays inv
    player.displayInventory();
    
}
