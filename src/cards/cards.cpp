#include "cards.hpp"

namespace cards {
    Card::Card(const CardType type, const CardValue value) {
        this->type = type;
        this->value = value;
    }
}