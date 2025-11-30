#include "Items.hpp"
#include "ItemClass.hpp"


// Hard coded list of items and prices that will be changed later
vector<Item> items = {
    Item("Wooden Sword", 10),
    Item("Stone Sword", 20),
    Item("Metal Sword", 30),
    Item("Light Armor", 15),
    Item("Heavy Armor", 30),
    Item("Bandage", 5),
    Item("Health Potion", 15),
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
