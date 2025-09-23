
#include "enemy.h"
#include <cstdlib>

Enemy::Enemy(std::string enemyName, int hp, int attack)
    : name(enemyName), health(hp), attackPower(attack) {}

void Enemy::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

int Enemy::attack() {
    return attackPower + (std::rand() % 5 - 2);
}

bool Enemy::isAlive() const { return health > 0; }
int Enemy::getHealth() const { return health; }
std::string Enemy::getName() const { return name; }