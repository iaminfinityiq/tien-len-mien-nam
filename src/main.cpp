#include <iostream>
#include <string>
#include "helpers/valid_number.hpp"
#include "helpers/terminal.hpp"
#include <vector>
#include "game/hand.hpp"
#include "game/game.hpp"

using namespace helpers;
using namespace game;

int main() {
    size_t result = 0;
    while (true) {
        clear();
        std::cout << "How many players are playing? ";
        std::string answer;
        std::getline(std::cin, answer);

        if (!valid_number(answer)) {
            std::cout << answer << " is not a valid number.\n";
            petc();
            continue;
        }

        if (check_boundaries(answer, 8)) {
            result = std::stoll(answer);
            break;
        }

        std::cout << answer << " is simply just a number that's too large.\n";
        petc();
    }

    std::vector<Hand> players = {};
    for (size_t i = 1; i <= result; i++) {
        std::string name;
        std::cout << "P" << i << ": ";
        std::getline(std::cin, name);

        players.push_back(Hand(name));
    }

    clear();
    Game g = Game(players);
    return 0;
}