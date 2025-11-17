#include "player.hpp"

Player::Player() {
    gold = 100;
}

int Player::getGold() const {
    return gold;
}

void Player::addGold(int amount) {
    gold += amount;
}

bool Player::spendGold(int amount) {
        if (gold >= amount) {
            gold -= amount;
            return true;
        }
        return false;
}