
#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy{
    private:
        std::string name;
        int health;
        int attackPower;

    public:
        Enemy(std::sring enemyName, int hp, int attack);
        void takeDamage(int dmg);
        int attack();
        bool isAlive() const;
        int getHealth() const;
        std::string getName() const;

};

#endif