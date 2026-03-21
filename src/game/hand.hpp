#pragma once
#include "../cards/cards.hpp"
#include <vector>
#include <string>

using namespace cards;

namespace game {
    struct Hand {
        std::vector<Card> cards;
        std::string name;
        
        Hand(const std::string name);
        void receive_card(const Card &card);
    };
}