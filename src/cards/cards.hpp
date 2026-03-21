#pragma once

namespace cards {
    enum struct CardType {
        Spades,
        Clubs,
        Diamonds,
        Hearts
    }; // ordered from smallest to largest so that it is easier to compare

    enum struct CardValue {
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace,
        Two
    }; // ordered from smallest to largest so that it is easier to compare

    struct Card {
        CardType type;
        CardValue value;

        Card(const CardType type, const CardValue value);
    };
}