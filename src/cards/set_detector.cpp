#include "set_detector.hpp"
#include <map>

namespace cards {
    std::map<size_t, size_t> count_cards(const std::vector<Card> &cards) {
        std::map<size_t, size_t> returned = {};
        for (const Card &card : cards) {
            returned[static_cast<size_t>(card.value)]++;
        }

        return returned;
    }

    SetType detect_set(const std::vector<Card> &cards) {
        if (cards.empty()) {
            return SetType::None;
        }

        if (cards.size() == 1) {
            return SetType::Single;
        }

        if (cards.size() == 2) {
            if (cards[0].value == cards[1].value) {
                return SetType::Pair;
            }

            return SetType::None;
        }

        std::map<size_t, size_t> count = count_cards(cards);
        if (cards.size() == 3) {
            if (count.size() == 1) {
                return SetType::Triple;
            }
        }

        if (cards.size() == 4) {
            if (count.size() == 1) {
                return SetType::FourOfAKind;
            }
        }

        if (cards.size() == 6) {
            if (count.size() == 3) {
                size_t prev_value = 0;
                for (auto &it : count) {
                    if (it.second != 2) {
                        return SetType::None;
                    }

                    if (prev_value > 0) {
                        if (it.first != prev_value+1) {
                            return SetType::None;
                        }
                    }

                    prev_value = it.first;
                }

                return SetType::ThreeConsecutivePairs;
            }
        }

        if (cards.size() == 8) {
            if (count.size() == 4) {
                size_t prev_value = 0;
                for (auto &it : count) {
                    if (it.second != 2) {
                        return SetType::None;
                    }

                    if (prev_value > 0) {
                        if (it.first != prev_value+1) {
                            return SetType::None;
                        }
                    }

                    prev_value = it.first;
                }

                return SetType::FourConsecutivePairs;
            }
        }

        if (count.size() != cards.size()) {
            return SetType::None;
        }

        size_t prev_value = 0;
        for (auto &it : count) {
            if (prev_value > 0) {
                if (it.first != prev_value+1) {
                    return SetType::None;
                }
            }

            prev_value = it.first;
        }

        if (prev_value == static_cast<size_t>(CardValue::Two)) {
            return SetType::None;
        }

        return SetType::Straight;
    }
}