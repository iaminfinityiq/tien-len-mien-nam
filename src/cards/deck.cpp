#include "deck.hpp"

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
    }
}