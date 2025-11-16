#include "boundaryShopMenu.hpp"

void BoundaryShopMenu::checkShop(Shop& shop, Player& player){
    while (selectionChoice != 4){
        cout << "\n===== SHOP MENU =====\n";
        cout << "Gold: " << player.getGold() << "\n";
        cout << "1. Buy Items\n";
        cout << "2. Sell Items\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit Shop\n";
        cout << "Enter choice: ";
        cin >> selectionChoice;

        if (selectionChoice == 1) {
            shop.displayItems();
        }
        else if (selectionChoice == 2) {
            int index;
            player.inv.displayInventory();
            cout << "Enter index to sell: " << endl;
            cin >> index;
            shop.sellItem(index, player);
        }
        else if (selectionChoice == 3) {
            checkInventory(player);
        }
        else if (selectionChoice == 4) {
            cout << "Leaving Shop... " << endl;
        }

        else {
            cout << "Invalid choice." << endl;
        }
    }
}

void BoundaryShopMenu::checkInventory(Player& player) {
    cout << "\n===== INVENTORY =====\n";
    player.inv.displayInventory();
}