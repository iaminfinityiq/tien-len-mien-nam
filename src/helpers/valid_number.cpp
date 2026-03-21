#include "valid_number.hpp"

namespace helpers {
    bool valid_number(const std::string value) {
        if (value == "") {
            return false;
        }
        
        for (const char &c : value) {
            if (c < '0' || c > '9') {
                return false;
            }
        }

        return true;
    }

    bool check_boundaries(const std::string compared, const size_t bounds) {
        if (compared.size() >= 10) {
            return false;
        }

        return std::stoull(compared) <= bounds;
    }
}