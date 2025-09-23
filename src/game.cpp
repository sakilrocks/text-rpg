
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(std::string playerName) : player(playerName), enemiesDefeated(0) {
    std::srand(std::time(nullptr));
    player.addItem(Item("small Potion", "heal", 20));
    player.addItem(Item("big Potion", "heal", 40));
}

Enemy Game::generateEnemy() {
    int hp = 30 + std::rand() % 20;
    int atk = 8 + std::rand() % 5;
    return Enemy("Goblin", hp, atk);
}

void Game::battle(Enemy &enemy) {
    while (player.isAlive() && enemy.isAlive()) {
        std::cout << "\n--- Battle ---\n";
        std::cout << player.getName() << " HP: " << player.getHealth()
                  << " | " << enemy.getName() << " HP: " << enemy.getHealth() << "\n";

        std::cout << "1. attack \n2. use item\n 3. run\n choose: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int dmg = player.attack();
            enemy.takeDamage(dmg);
            std::cout << "you hit " << enemy.getName() << " for " << dmg << " damage\n";
        } else if (choice == 2) {
            player.showInventory();
            std::cout << "choose item index: ";
            int idx;
            std::cin >> idx;
            player.useItem(idx);
        } else if (choice == 3) {
            std::cout << "you ran away!\n";
            return;
        }

        if (enemy.isAlive()) {
            int dmg = enemy.attack();
            player.takeDamage(dmg);
            std::cout << enemy.getName() << " hits you for " << dmg << " damage\n";
        }
    }

    if (player.isAlive()) {
        std::cout << "you defeated " << enemy.getName() << "!\n";
        enemiesDefeated++;
    } else {
        std::cout << "you were defeated.\n";
    }
}

void Game::start() {
    std::cout << "welcome, " << player.getName() << "! your adventure begins \n";

    while (player.isAlive()) {
        Enemy enemy = generateEnemy();
        std::cout << "\nan enemy " << enemy.getName() << " appears!\n";
        battle(enemy);

        if (!player.isAlive()) break;

        char cont;
        std::cout << "\nfight another enemy? (y/n): ";
        std::cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    std::cout << "\ngame over. enemies defeated: " << enemiesDefeated << "\n";
}