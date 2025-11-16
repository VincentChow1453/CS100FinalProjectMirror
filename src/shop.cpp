#include "shop.hpp"
#include <iostream>
using namespace std;

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

// TEMP DISPLAY — Hard-coded fake shop items
void Shop::displayItems() {
    cout << "\n===== TEMP SHOP ITEM LIST =====\n";
    cout << "0: Potion (10 gold)\n";
    cout << "1: Sword  (50 gold)\n";
    cout << "2: Shield (40 gold)\n";
    cout << "[TEMP] Real shop inventory not implemented yet.\n";
}
