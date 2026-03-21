#pragma once
#include "cards/cards.hpp"
#include <string>

using namespace cards;

namespace helpers {
    std::string type_repr(const CardType type);
    std::string value_repr(const CardValue value);
    std::string card_repr(const Card card);
}