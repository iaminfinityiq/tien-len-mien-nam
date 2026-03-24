#pragma once
#include <vector>
#include "hand.hpp"

namespace game {
    struct Game {
        std::vector<Hand> players;
        
        Game(std::vector<Hand> &players);
        size_t discard_threes();
        size_t start_round(const size_t winner_idx);
    };
}