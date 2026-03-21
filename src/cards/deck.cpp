#include "deck.hpp"
#include <random>

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

        std::vector<Card> dummy = {};
        for (const CardType &type : this->types) {
            for (const CardValue &value : this->values) {
                dummy.push_back(Card(type, value));
            }
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        while (!dummy.empty()) {
            std::uniform_int_distribution<size_t> roll(0, dummy.size()-1);
            size_t position = roll(gen);

            this->cards.push_back(dummy[position]);
            dummy.erase(dummy.begin() + position);
        }
    }
}