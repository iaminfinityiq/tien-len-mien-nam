#include <iostream>
#include <string>
#include "helpers/valid_number.hpp"
#include "helpers/terminal.hpp"
#include <vector>
#include "game/hand.hpp"
#include "game/game.hpp"
#include "helpers/repr.hpp"

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

    Game g = Game(players);
    for (const Hand &player : g.players) {
        clear();
        std::cout << "It is " << player.name << "'s turn to take a look at their cards. Please pass the device to them.\n";
        petc();

        clear();
        std::cout << player.name << ", you currently have " << player.cards.size() << " cards on your hand. Please take a look at them:\n";
        bool flag = false;
        for (size_t i = 0; i < player.cards.size(); i++) {
            std::cout << "[" << i+1 << "] " << card_repr(player.cards[i]) << "\n";
            if (player.cards[i].type == CardType::Spades && player.cards[i].value == CardValue::Three) {
                flag = true;
            }
        }

        if (flag) {
            std::cout << "You are going to play first as you have a 3 of Spades on your hand.\n";
        }

        petc();
    }

    clear();
    size_t go_first = g.discard_threes();
    std::cout << "We have just finished discarding all of your 3s\n";
    petc();
    for (const Hand &player : g.players) {
        clear();
        std::cout << "It is " << player.name << "'s turn to take a look at their cards. Please pass the device to them.\n";
        petc();

        clear();
        std::cout << player.name << ", you currently have " << player.cards.size() << " cards on your hand. Please take a look at them:\n";
        for (size_t i = 0; i < player.cards.size(); i++) {
            std::cout << "[" << i+1 << "] " << card_repr(player.cards[i]) << "\n";
        }

        petc();
    }

    clear();
    std::cout << "Player " << g.players[go_first].name << " will play first.\n";
    petc();
    return 0;
}