#include "hand.hpp"

namespace game {
    Hand::Hand(const std::string name) {
        this->name = name;
        this->cards = {};
    }

    void Hand::receive_card(const Card &card) {
        this->cards.push_back(card);
    }
}