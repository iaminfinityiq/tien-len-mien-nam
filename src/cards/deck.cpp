#include "deck.hpp"
#include "../helpers/random.hpp"

using namespace helpers;

namespace cards {
    Deck::Deck() {
        this->cards = {};
        this->types = {
            CardType::Spades,
            CardType::Clubs,
            CardType::Diamonds,
            CardType::Hearts
        };
        this->values = {
            CardValue::Three,
            CardValue::Four,
            CardValue::Five,
            CardValue::Six,
            CardValue::Seven,
            CardValue::Eight,
            CardValue::Nine,
            CardValue::Ten,
            CardValue::Jack,
            CardValue::Queen,
            CardValue::King,
            CardValue::Ace,
            CardValue::Two
        };

        for (const CardType &type : this->types) {
            for (const CardValue &value : this->values) {
                this->cards.push_back(Card(type, value));
            }
        }

        shuffle(this->cards);
    }

    void Deck::deal_cards(std::vector<Hand> &players) {
        size_t player_idx = 0;

        while (!this->cards.empty()) {
            players[player_idx++].receive_card(this->cards[0]);
            player_idx %= players.size();

            this->cards.erase(this->cards.begin());
        }
    }
}