#pragma once
#include <vector>
#include "cards.hpp"

namespace cards {
    struct DiscardPile {
        std::vector<cards::Card> last_played;
        DiscardPile();
        void clear();
        bool add_cards(std::vector<cards::Card> &cards);
    };
}