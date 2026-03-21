#include "game.hpp"
#include "../cards/deck.hpp"
#include "../helpers/random.hpp"
#include <iostream>
#include "../helpers/repr.hpp"

using namespace helpers;

namespace game {
    Game::Game(std::vector<Hand> &players) {
        this->players = players;
        shuffle(this->players);

        Deck deck = Deck();
        deck.deal_cards(this->players);

        std::cout << "STARTING HAND:\n";
        for (const Hand &player : this->players) {
            std::cout << player.name << "'s cards:\n";
            size_t i = 1;
            for (const Card &card : player.cards) {
                std::cout << i++ << ". " << card_repr(card) << "\n";
            }

            std::cout << "\n";
        }
    }
}