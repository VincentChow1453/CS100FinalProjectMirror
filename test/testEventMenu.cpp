#include "EventMenu.hpp"
#include "CharacterClass.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

// Helper to replace cin with stringstream input
void setInput(const std::string& input) {
    static std::stringstream ss;
    ss.clear();
    ss.str(input);
    std::cin.rdbuf(ss.rdbuf());
}

// EVENT 1 -------------------------------------------------------------

TEST(EventMenuTests, Event1NeutralDoesNotChangeStats) {
    CharacterClass player("Warrior", "Test", 100, 20, 10, 1, 50);

    setInput("1\n");    // choose neutral

    event1(player);

    EXPECT_EQ(player.getBaseHealth(), 100);
    EXPECT_EQ(player.getGold(), 50);
}

TEST(EventMenuTests, Event1GoodGivesGold) {
    CharacterClass player("Warrior", "Test", 100, 20, 10, 1, 0);

    setInput("3\n");    // choose good

    event1(player);

    EXPECT_EQ(player.getGold(), 20);
}

TEST(EventMenuTests, Event1BadRemovesHealth) {
    CharacterClass player("Warrior", "Test", 100, 20, 10, 1, 50);

    setInput("2\n");    // choose bad

    event1(player);

    EXPECT_EQ(player.getBaseHealth(), 90);
}

// EVENT 2 -------------------------------------------------------------

TEST(EventMenuTests, Event2GoodRestoresMana) {
    CharacterClass player("Mage", "Test", 50, 10, 5, 1, 0);

    setInput("2\n");    // drink potion

    event2(player);

    EXPECT_EQ(player.getBaseMana(), 20);
}

TEST(EventMenuTests, Event2BadDealsDamage) {
    CharacterClass player("Mage", "Test", 50, 10, 5, 1, 0);

    setInput("3\n");    // throw potion

    event2(player);

    EXPECT_EQ(player.getBaseHealth(), 45);
}

// EVENT 3 -------------------------------------------------------------

TEST(EventMenuTests, Event3GoodGivesItemAndGold) {
    CharacterClass player("Thief", "Test", 80, 10, 15, 1, 0);

    setInput("2\n");    // pick the lock

    event3(player);

    EXPECT_EQ(player.getGold(), 40);
    ASSERT_EQ(player.getInventory().size(), 1);
    EXPECT_EQ(player.getInventory()[0], "Rare Gem");
}

// EVENT 4 -----------------------------
