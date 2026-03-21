#include "repr.hpp"

namespace helpers {
    std::string type_repr(const CardType type) {
        if (type == CardType::Spades) {
            return "Spades";
        }

        if (type == CardType::Clubs) {
            return "Clubs";
        }

        if (type == CardType::Diamonds) {
            return "Diamonds";
        }

        return "Hearts";
    }

    std::string value_repr(const CardValue value) {
        if (value == CardValue::Three) {
            return "3";
        }

        if (value == CardValue::Four) {
            return "4";
        }

        if (value == CardValue::Five) {
            return "5";
        }

        if (value == CardValue::Six) {
            return "6";
        }

        if (value == CardValue::Seven) {
            return "7";
        }

        if (value == CardValue::Eight) {
            return "8";
        }

        if (value == CardValue::Nine) {
            return "9";
        }

        if (value == CardValue::Ten) {
            return "10";
        }

        if (value == CardValue::Jack) {
            return "J";
        }

        if (value == CardValue::Queen) {
            return "Q";
        }

        if (value == CardValue::King) {
            return "K";
        }

        if (value == CardValue::Ace) {
            return "A";
        }

        return "2";
    }
    
    std::string card_repr(const Card card) {
        return value_repr(card.value) + " of " + type_repr(card.type);
    }
}