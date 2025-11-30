#include "Items.hpp"
#include "ItemClass.hpp"

vector<Item> items = {
    Item("Wooden Sword", 10),
    Item("Stone Sword", 10),
    Item("Metal Sword", 10),
    Item("Light Armor", 10),
    Item("Heavy Armor", 10),
    Item("Bandage", 10),
    Item("Health Potion", 10),
};

Item* getItemByName(const std::string& name) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == name) {
            return &items[i];
        }
    }
    return nullptr;
}
