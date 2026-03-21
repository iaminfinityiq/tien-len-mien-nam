#pragma once
#include <vector>
#include "cards.hpp"
#include "../game/hand.hpp"

using namespace game;

namespace cards {
    struct Deck {
    public:
        Deck();
        void deal_cards(std::vector<Hand> &players);
    private:
        std::vector<Card> cards;
        std::vector<CardType> types;
        std::vector<CardValue> values;
    };
}