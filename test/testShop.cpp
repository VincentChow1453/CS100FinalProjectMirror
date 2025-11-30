#include <gtest/gtest.h>
#include "ItemClass.hpp"
#include "Items.hpp"
#include "characterClass.h"
#include "shop.hpp"
#include "shopRoom.hpp"

// ITEM TESTS
TEST(ItemTest, CreateItem) {
    Item potion("Potion", 10);

    EXPECT_EQ(potion.name, "Potion");
    EXPECT_EQ(potion.price, 10);
}

// INVENTORY TESTS
TEST(InventoryTest, AddItems) {
    CharacterClass p;
    p.addItem("Sword");
    p.addItem("Shield");

    EXPECT_EQ(p.getInventory().size(), 2);
}

TEST(InventoryTest, RemoveItems) {
    CharacterClass p;
    p.addItem("Sword");
    p.addItem("Shield");

    p.removeItem("Sword");

    EXPECT_EQ(p.getInventory().size(), 1);
}

// PLAYER (CharacterClass) Tests
TEST(PlayerTest, PlayerStartsWithGold) {
    CharacterClass p;
    EXPECT_EQ(p.getGold(), 0);  // default gold is 0 based on your constructor
}

TEST(PlayerTest, AddGoldWorks) {
    CharacterClass p;
    p.setGold(100);
    p.setGold(p.getGold() + 25);

    EXPECT_EQ(p.getGold(), 125);
}

TEST(PlayerTest, SpendGoldSuccess) {
    CharacterClass p;
    p.setGold(100);

    bool success;
    if (p.getGold() >= 30) {
        p.setGold(p.getGold() - 30);
        success = true;
    } else {
        success = false;
    }

    EXPECT_TRUE(success);
    EXPECT_EQ(p.getGold(), 70);
}

TEST(PlayerTest, SpendGoldFail) {
    CharacterClass p;
    p.setGold(100);

    bool success;
    if (p.getGold() >= 999) {
        p.setGold(p.getGold() - 999);
        success = true;
    } else {
        success = false;
    }

    EXPECT_FALSE(success);
    EXPECT_EQ(p.getGold(), 100);
}

// SHOP TESTS
TEST(ShopTest, DisplayItemsDoesNotCrash) {
    Shop s;
    EXPECT_NO_THROW(s.displayItems());
}

TEST(ShopTest, SellItemCallDoesNotCrash) {
    Shop s;
    CharacterClass p;

    // Player must possess the item for selling to be valid
    p.addItem("Wooden Sword");

    EXPECT_NO_THROW(s.sellItem("Wooden Sword", p));
}

