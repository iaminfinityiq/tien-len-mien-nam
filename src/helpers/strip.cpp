#include "strip.hpp"

namespace helpers {
    std::string strip(const std::string str) {
        const std::string whitespace = " \t\n\r\f\v";
        size_t start = str.find_first_not_of(whitespace);
        if (start == std::string::npos) {
            return "";
        }

        size_t end = str.find_last_not_of(whitespace);
        return str.substr(start, end-start+1);
    }
}