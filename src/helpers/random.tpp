#include "random.hpp"
#include <random>
#include <utility>

namespace helpers {
    template<typename T>
    void shuffle(std::vector<T> &vec) {
        /*
        Algorithm details:
            Step 1: Iterate from 0 -> vec.size()-1;
            Step 2: Get the position from i -> vec.size()-1
            Step 3: Swap the position to position i

            Time complexity: O(n)
            Space complexity: O(1)
        */

        std::random_device rd;
        std::mt19937 gen(rd());

        size_t eol_idx = vec.size()-1;
        for (size_t i = 0; i < vec.size(); i++) {
            std::uniform_int_distribution<size_t> roll(i, eol_idx);
            size_t position = roll(gen);

            std::swap(vec[position], vec[i]);
        }
    }
}