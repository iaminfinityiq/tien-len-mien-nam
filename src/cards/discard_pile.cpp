#include "discard_pile.hpp"
#include "set_detector.hpp"
#include <algorithm>

namespace cards {
    DiscardPile::DiscardPile() {
        this->clear();
    }

    void DiscardPile::clear() {
        this->last_played = {};
    }

    bool compare_card(const Card a, const Card b) {
        size_t a_value = static_cast<size_t>(a.value);
        size_t b_value = static_cast<size_t>(b.value);

        if (a_value != b_value) {
            return a_value < b_value;
        }

        return static_cast<size_t>(a.type) < static_cast<size_t>(b.type);
    }

    bool DiscardPile::add_cards(std::vector<Card> &cards) {
        SetType set = detect_set(cards);
        if (set == SetType::None) {
            return false;
        }

        if (this->last_played.empty()) {
            this->last_played = cards;
            return true;
        }

        SetType discard_set = detect_set(this->last_played);
        std::sort(cards.begin(), cards.end(), compare_card);

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
                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
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
                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
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

            if (set == SetType::Straight) {
                if (cards.size() != this->last_played.size()) {
                    return false;
                }

                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::ThreeConsecutivePairs) {
            if (set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }

            if (set == SetType::ThreeConsecutivePairs) {
                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::FourOfAKind) {
            if (set == SetType::FourConsecutivePairs) {
                this->last_played = cards;
                return true;
            }

            if (set == SetType::FourOfAKind) {
                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        if (discard_set == SetType::FourConsecutivePairs) {
            if (set == SetType::FourConsecutivePairs) {
                if (compare_card(*this->last_played.rbegin(), *cards.rbegin())) {
                    this->last_played = cards;
                    return true;
                }

                return false;
            }

            return false;
        }

        return false;
    }
}