#pragma once
#include <vector>
#include "hand.hpp"
#include "../cards/discard_pile.hpp"

using namespace cards;

namespace game {
    struct Game {
    public:
        std::vector<Hand> players;
        
        Game(std::vector<Hand> &players);
        size_t discard_threes();
        size_t start_round(const size_t winner_idx);
        bool start_turn(const size_t player_idx);
    private:
        DiscardPile discard_pile;
    };
}