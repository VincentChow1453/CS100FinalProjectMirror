#include <iostream>
#include "shopRoom.hpp"
#include "player.hpp"

using namespace std;

int main() {
    // Create Player
    Player player;

    // Add some items to inventory for testing
    player.inv.addItem(Item("Potion", 10));
    player.inv.addItem(Item("Sword", 50));
    player.inv.addItem(Item("Shield", 40));

    // Create ShopRoom
    ShopRoom shopRoom;

    cout << "Entering shop..." << endl;

    // Trigger the shop encounter
    shopRoom.TriggerEncounter(player);

    cout << "Exited shop successfully." << endl;

    return 0;
}
