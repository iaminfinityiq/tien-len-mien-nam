#pragma once
#include <string>

namespace helpers {
    bool valid_number(const std::string value);
    bool check_boundaries(const std::string value, const size_t bounds);
}