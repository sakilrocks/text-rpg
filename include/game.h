
#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"

class Game {
    private:
        Player player;
        int enemiesDefeated;

        Enemy generateEnemy();
        void battle(Enemy &enemy);

    public:
        Game(std::string playerName);
        void start();
     
};

#endif