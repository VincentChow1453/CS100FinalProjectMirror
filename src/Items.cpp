#include "Items.hpp"
#include "ItemClass.hpp"


// Hard coded list of items and prices that will be changed later
vector<Item> items = {
    Item("Wooden Sword", 10, "strength", 5),
    Item("Stone Sword", 20, "strength", 10),
    Item("Metal Sword", 30, "strength", 15),
    Item("Apple", 5, "health", 10),
    Item("Protein Bar", 10, "mana", 20),
    Item("Bandage", 5, "health", 20),
    Item("Health Potion", 15, "health", 50),
    Item("Rare Gem", 50, "none", 0)
};

// Helper Function to identify items in other functions like buy and sell
Item* getItemByName(const std::string& name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == name) {
            return &items[i];
        }
    }
    return nullptr;
}