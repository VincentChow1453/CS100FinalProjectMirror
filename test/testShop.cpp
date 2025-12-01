#include <gtest/gtest.h>
#include "ItemClass.hpp"
#include "Items.hpp"
#include "CharacterClass.hpp"
#include "Shop.hpp"
#include "ShopRoom.hpp"

// ITEM TESTS
TEST(ItemTest, CreateItem) {
    Item potion("Potion", 10, "health", 50);

    EXPECT_EQ(potion.name, "Potion");
    EXPECT_EQ(potion.price, 10);
    EXPECT_EQ(potion.type, "health");
    EXPECT_EQ(potion.amount, 50);
}

TEST(ItemTest, EditCharacterStrength) {
    CharacterClass testPlayer("Warrior", "Bob", 100, 50, 10, 1, 0);

    testPlayer.addItem("Wooden Sword");  // <-- REQUIRED

    Item* sword = getItemByName("Wooden Sword");

    int oldStrength = testPlayer.getBaseStrength();
    testPlayer.useItem(*sword);

    EXPECT_EQ(testPlayer.getBaseStrength(), oldStrength + sword->amount);
}




// INVENTORY/INV TESTS
TEST(InventoryTest, AddItems) {
    CharacterClass player;
    player.addItem("Sword");
    player.addItem("Shield");

    EXPECT_EQ(player.getInventory().size(), 2);
}

TEST(InventoryTest, RemoveItems) {
    CharacterClass player;
    player.addItem("Sword");
    player.addItem("Shield");

    player.removeItem("Sword");

    EXPECT_EQ(player.getInventory().size(), 1);
}

//(CharacterClass) Tests
TEST(PlayerTest, PlayerStartsWithGold) {
    CharacterClass player;
    EXPECT_EQ(player.getGold(), 0);  // default gold is 0
}

TEST(PlayerTest, AddGoldWorks) {
    CharacterClass player;
    player.setGold(100);
    player.setGold(player.getGold() + 25);

    EXPECT_EQ(player.getGold(), 125);
}

// SHOP TESTS
TEST(ShopTest, DisplayItemsDoesNotCrash) {
    Shop s;
    EXPECT_NO_THROW(s.displayItems());
}


// Buy logic
TEST(ShopTest, BuyItemSuccess) {
    Shop s;
    CharacterClass player;
    player.setGold(100);

    int startingGold = player.getGold();   // Save gold before purchase

    s.buyItem(0, player); // Buy wooden sword (10 gold)

    EXPECT_EQ(player.getInventory().size(), 1);
    EXPECT_EQ(player.getGold(), startingGold - 10); 
}


TEST(ShopTest, BuyItemFailsWithoutGold) {
    Shop s;
    CharacterClass p;

    p.setGold(0);                // 0 gold
    s.buyItem(0, p);           

    EXPECT_EQ(p.getInventory().size(), 0);        // inv size and gold unchanged
    EXPECT_EQ(p.getGold(), 0);                    
}

// sell
TEST(ShopTest, SellItemWorks) {
    Shop s;
    CharacterClass p;

    p.setGold(0);
    p.addItem("Wooden Sword");    // player already owns one

    s.sellItem("Wooden Sword", p);

    EXPECT_EQ(p.getInventory().size(), 0);        // item removed
    EXPECT_GT(p.getGold(), 0);                    // gold increased
}

// sell fails
TEST(ShopTest, SellItemFailsIfNotOwned) {
    Shop s;
    CharacterClass p;

    p.setGold(0);

    s.sellItem("Wooden Sword", p); // player does NOT own it

    EXPECT_EQ(p.getInventory().size(), 0);        // inv and gold untouched
    EXPECT_EQ(p.getGold(), 0);                    
}