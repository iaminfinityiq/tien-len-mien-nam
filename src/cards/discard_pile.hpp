#pragma once
#include <vector>
#include "cards.hpp"

namespace cards {
    struct DiscardPile {
    public:
        DiscardPile();
        void clear();
        bool add_cards(const std::vector<cards::Card> &cards);
    private:
        std::vector<cards::Card> last_played;
    };
}