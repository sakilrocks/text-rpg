
#include "player.h"
#include <iostream>
#include <cstdlib>

Player::Player(std::string playerName)
    : name(playerName), health(100), attackPower(10) {}

void Player::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

void Player::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
}

void Player::addItem(const Item &item) {
    inventory.push_back(item);
}

void Player::useItem(int index) {
    if (index < 0 || index >= (int)inventory.size()) {
        std::cout << "invalid item selection.\n";
        return;
    }
    Item &item = inventory[index];
    if (item.type == "heal") {
        heal(item.value);
        std::cout << name << " used " << item.name << " and healed " << item.value << " HP!\n";
    }
    inventory.erase(inventory.begin() + index);
}

int Player::attack() {
    return attackPower + (std::rand() % 5 - 2); // random variation
}

int Player::getHealth() const { return health; }
std::string Player::getName() const { return name; }

void Player::showInventory() const {
    if (inventory.empty()) {
        std::cout << "inventory is empty.\n";
        return;
    }
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ": " << inventory[i].name << " (" << inventory[i].type << ")\n";
    }
}

bool Player::isAlive() const { return health > 0; }