
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"

class Player {

private:
    std::string name;
    int health;
    int attackPower;
    std::vector<Item> inventory;
    
public:
    Player(std::string playerName);
    void takeDamage(int dmg);
    void heal(int amount);
    void addItem(const Item &item);
    void useItem(int index);
    int attack();
    int getHealth() const;
    std::string getName() const;
    bool isAlive() const;

};

#endif