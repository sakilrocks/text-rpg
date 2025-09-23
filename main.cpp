
#include "game.h"
#include <iostream>

int main() {
    std::string name;
    std::cout << "enter your character name: ";
    std::cin >> name;

    Game game(name);
    game.start();

    return 0;
}
