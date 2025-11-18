#include <gtest/gtest.h>
#include "itemStub.hpp"
#include "inventory.hpp"
#include "player.hpp"
#include "shop.hpp"
#include "shopRoom.hpp"

// distributing item logic
TEST(ItemTest, CreateItem) {
    Item potion("Potion", 10);

    EXPECT_EQ(potion.name, "Potion");
    EXPECT_EQ(potion.price, 10);
}


// adding items to inv
TEST(InventoryTest, AddItems) {
    Inventory inv;

    inv.addItem(Item("Sword", 50));
    inv.addItem(Item("Shield", 40));

    EXPECT_EQ(inv.size(), 2);
}

TEST(InventoryTest, RemoveItems) {
    Inventory inv;

    inv.addItem(Item("Sword", 50));
    inv.addItem(Item("Shield", 40));

    inv.removeItem(0);

    EXPECT_EQ(inv.size(), 1);
}



// Player Tests (currency)
TEST(PlayerTest, PlayerStartsWithGold) {
    Player p;
    EXPECT_EQ(p.getGold(), 100);
}

TEST(PlayerTest, AddGoldWorks) {
    Player p;
    p.addGold(25);
    EXPECT_EQ(p.getGold(), 125);
}

TEST(PlayerTest, SpendGoldSuccess) {
    Player p;
    bool success = p.spendGold(30);

    EXPECT_TRUE(success);
    EXPECT_EQ(p.getGold(), 70);
}

TEST(PlayerTest, SpendGoldFail) {
    Player p;
    bool success = p.spendGold(999);

    EXPECT_FALSE(success);
    EXPECT_EQ(p.getGold(), 100);
}



// SHOP TESTS NO LOGIC YET
TEST(ShopTest, DisplayItemsDoesNotCrash) {
    Shop s;


    EXPECT_NO_THROW(s.displayItems());
}

TEST(ShopTest, SellItemCallDoesNotCrash) {
    Shop s;
    Player p;

    EXPECT_NO_THROW(s.sellItem(0, p));
}


