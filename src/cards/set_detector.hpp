#pragma once
#include <vector>
#include "cards.hpp"

namespace cards {
    enum struct SetType {
        None,
        Single,
        Pair,
        Triple,
        Straight,
        FourOfAKind,
        ThreeConsecutivePairs,
        FourConsecutivePairs
    };

    SetType detect_set(const std::vector<Card> &cards);
}