#include <gtest/gtest.h>
#include "../header/CharacterClass.hpp"

//to run: cd build, cmake .., make, cd.., .test/runAllTests

//test constructor defaults
TEST(CharacterClassTests, ConstructorAssignsValues) {
    CharacterClass cc("Warrior", "Hero");

    EXPECT_EQ(cc.getClassType(), "Warrior");
    EXPECT_EQ(cc.getName(), "Hero");
    EXPECT_EQ(cc.getBaseHealth(), 0);
    EXPECT_EQ(cc.getBaseMana(), 0);
    EXPECT_EQ(cc.getBaseStrength(), 0);
    EXPECT_EQ(cc.getBaseLevel(), 1);
    EXPECT_EQ(cc.getGold(), 0);
}

//valid setname
TEST(CharacterClassTests, SetNameValid) {
    CharacterClass cc;
    cc.setName("Mage");
    EXPECT_EQ(cc.getName(), "Mage");
}

//throws on empty
TEST(CharacterClassTests, SetNameThrowsOnEmpty) {
    CharacterClass cc;
    EXPECT_THROW(cc.setName(""), std::invalid_argument);
}

//valid setclass
TEST(CharacterClassTests, SetClassTypeValid) {
    CharacterClass cc;
    cc.setClassType("Rogue");
    EXPECT_EQ(cc.getClassType(), "Rogue");
}

//throws on empty
TEST(CharacterClassTests, SetClassTypeThrowsOnEmpty) {
    CharacterClass cc;
    EXPECT_THROW(cc.setClassType(""), std::invalid_argument);
}

TEST(CharacterClassTests, SetBaseHealthValid) {
    CharacterClass cc;
    cc.setBaseHealth(50);
    EXPECT_EQ(cc.getBaseHealth(), 50);
}

TEST(CharacterClassTests, SetBaseHealthThrowsOnNegative) {
    CharacterClass cc;
    EXPECT_THROW(cc.setBaseHealth(-10), std::invalid_argument);
}

//add item
TEST(CharacterClassTests, AddItemValid) {
    CharacterClass cc;
    cc.addItem("Potion");
    ASSERT_EQ(cc.getInventory().size(), 1);
    EXPECT_EQ(cc.getInventory()[0], "Potion");
}

//add empty item
TEST(CharacterClassTests, AddItemThrowsOnEmpty) {
    CharacterClass cc;
    EXPECT_THROW(cc.addItem(""), std::invalid_argument);
}

//remove item
TEST(CharacterClassTests, RemoveItemValid) {
    CharacterClass cc;
    cc.addItem("Sword");
    cc.addItem("Shield");

    cc.removeItem("Sword");

    ASSERT_EQ(cc.getInventory().size(), 1);
    EXPECT_EQ(cc.getInventory()[0], "Shield");
}

//remove nonexistent item
TEST(CharacterClassTests, RemoveItemThrowsWhenNotFound) {
    CharacterClass cc;
    cc.addItem("Potion");

    EXPECT_THROW(cc.removeItem("Elixir"), std::invalid_argument);
}

//display empty inv
TEST(CharacterClassTests, DisplayInventoryEmpty) {
    CharacterClass cc;

    testing::internal::CaptureStdout();
    cc.displayInventory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Empty"), std::string::npos);
}