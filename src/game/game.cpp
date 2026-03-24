#include "game.hpp"
#include "../cards/deck.hpp"
#include "../helpers/random.hpp"
#include <vector>

using namespace helpers;

namespace game {
    Game::Game(std::vector<Hand> &players) {
        this->players = players;
        shuffle(this->players);

        Deck deck = Deck();
        deck.deal_cards(this->players);
    }

    size_t Game::discard_threes() {
        size_t three_spades_guy = 1e18;
        for (size_t i = 0; i < this->players.size(); i++) {
            std::vector<Card> dummy = this->players[i].cards;
            this->players[i].cards = {};
            for (const Card &card : dummy) {
                if (card.value == CardValue::Three) {
                    if (card.type == CardType::Spades) {
                        three_spades_guy = i;
                    }

                    continue;
                }

                this->players[i].receive_card(card);
            }
        }

        return three_spades_guy;
    }

    size_t Game::start_round(const size_t winner_idx) {
        std::vector<size_t> remaining_players = {};
        size_t idx = winner_idx;
        size_t iter_count = 0;
        while (iter_count < this->players.size()) {
            if (this->players[idx].cards.empty()) {
                idx++;
                idx %= this->players.size();
                iter_count++;
                continue;
            }

            remaining_players.push_back(idx);
            idx++;
            idx %= this->players.size();
            iter_count++;
        }
    }
}