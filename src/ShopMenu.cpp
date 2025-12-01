#include "ShopMenu.hpp"
#include <limits>


// Pretty much just text and calling the logic
void BoundaryShopMenu::checkShop(Shop& shop, CharacterClass& player) {
    
    // Reset menu each time shop is opened
    selectionChoice = 0;

    // Keep Looping until quit
    while (selectionChoice != 4) {
        cout << "\n===== SHOP MENU =====\n";
        cout << "Gold: " << player.getGold() << "\n";
        cout << "1. Buy Items\n";
        cout << "2. Sell Items\n";
        cout << "3. View Inventory\n";
        cout << "4. Exit Shop\n";
        cout << "Enter choice: ";
        cin >> selectionChoice;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        // BUY ITEMS
        if (selectionChoice == 1) {
            shop.displayItems();
            cout << "\nWhat do you want to buy? (enter index, -1 to cancel): ";
            
            int buyChoice;
            cin >> buyChoice;

            if (buyChoice == -1) {
                cout << "Cancelled.\n";
            }
            else {
                shop.buyItem(buyChoice, player);
            }
        }

        // SELL ITEMS
        else if (selectionChoice == 2) {
            cout << "\n===== YOUR INVENTORY =====\n";

            // loading inv
            const vector<string>& inv = player.getInventory();
            player.displayInventory();

            // no items
            if (inv.empty()) {
                cout << "Nothing to sell.\n";
                continue;
            }

            cout << "Enter name of item to sell: ";
            string itemName;
            cin >> ws;
            getline(cin, itemName);

            // calling sell logic
            shop.sellItem(itemName, player);
        }

        // VIEW INVENTORY
        else if (selectionChoice == 3) {
            checkInventory(player);
        }

        // EXIT SHOP
        else if (selectionChoice == 4) {
            cout << "Leaving Shop...\n";
            break;
        }

        // Loop back
        else {
            cout << "Invalid selection.\n";
        }
    }
}

// Display Player's Inventory
void BoundaryShopMenu::checkInventory(CharacterClass& player) {
    cout << "\n===== INVENTORY =====\n";
    player.displayInventory();
}
