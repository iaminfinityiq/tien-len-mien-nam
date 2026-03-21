#pragma once
#include <vector>
#include "cards.hpp"

namespace cards {
    struct Deck {
    public:
        Deck();
    private:
        std::vector<Card> cards;
        std::vector<CardType> types;
        std::vector<CardValue> values;
    };
}