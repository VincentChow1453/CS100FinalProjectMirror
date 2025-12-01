#include "Items.hpp"
#include "ItemClass.hpp"


// Hard coded list of items with prices, types, and amounts
vector<Item> items = {
    Item("Wooden Sword", 10, "strength", 5),
    Item("Stone Sword", 20, "strength", 10),
    Item("Metal Sword", 30, "strength", 20),
    Item("Bandage", 5, "health", 20),
    Item("Health Potion", 15, "health", 50),
    Item("Apple", 5, "mana", 15),
    Item("Protein Bar", 15, "mana", 40),
};

// Helper Function to identify items in other functions like buy, sell, and use
Item* getItemByName(const std::string& name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == name) {
            return &items[i];
        }
    }
    return nullptr;
}
