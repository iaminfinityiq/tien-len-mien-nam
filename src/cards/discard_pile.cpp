#include "discard_pile.hpp"
#include "set_detector.hpp"

namespace cards {
    DiscardPile::DiscardPile() {
        this->clear();
    }

    void DiscardPile::clear() {
        this->last_played = {};
    }

    CardType find_highest_rank(const std::vector<Card> &cards) {
        CardType returned = CardType::Spades;
        for (const Card &card : cards) {
            if (static_cast<size_t>(card.type) > static_cast<size_t>(returned)) {
                returned = card.type;
            }

            if (returned == CardType::Hearts) {
                return returned;
            }
        }
        
        return returned;
    }

    bool DiscardPile::add_cards(const std::vector<Card> &cards) {
        SetType set = detect_set(cards);
        if (set == SetType::None) {
            return false;
        }

        if (this->last_played.empty()) {
            this->last_played = cards;
            return true;
        }

        SetType discard_set = detect_set(this->last_played);
        if (discard_set == SetType::Single) {
            if (set == SetType::ThreeConsecutivePairs || set == SetType::FourOfAKind || set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }

            if (set == SetType::Single) {
                size_t your_value = static_cast<size_t>(cards[0].value);
                size_t my_value = static_cast<size_t>(this->last_played[0].value);
                if (your_value > my_value) {
                    this->last_played = cards;
                    return true;
                }

                if (your_value < my_value) {
                    return false;
                }

                if (static_cast<size_t>(cards[0].type) > static_cast<size_t>(this->last_played[0].type)) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::Pair) {
            if (set == SetType::FourOfAKind || set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }

            if (set == SetType::Pair) {
                size_t your_value = static_cast<size_t>(cards[0].value);
                size_t my_value = static_cast<size_t>(this->last_played[0].value);
                if (your_value > my_value) {
                    this->last_played = cards;
                    return true;
                }

                if (your_value < my_value) {
                    return false;
                }

                if (static_cast<size_t>(find_highest_rank(cards)) > static_cast<size_t>(find_highest_rank(this->last_played))) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::Triple) {
            if (set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }

            if (set == SetType::Triple) {
                size_t your_value = static_cast<size_t>(cards[0].value);
                size_t my_value = static_cast<size_t>(this->last_played[0].value);
                if (your_value > my_value) {
                    this->last_played = cards;
                    return true;
                }

                if (your_value < my_value) {
                    return false;
                }

                if (static_cast<size_t>(find_highest_rank(cards)) > static_cast<size_t>(find_highest_rank(this->last_played))) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::Straight) {
            if (set == SetType::ThreeConsecutivePairs || set == SetType::FourOfAKind || set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }
        }

        return false;
    }
}