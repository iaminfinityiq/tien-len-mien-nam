#include "terminal.hpp"
#include <iostream>
#include <string>

#ifdef _WIN32
    #include <windows.h>
#endif

namespace helpers {
    void clear() {
        #ifdef _WIN32
            system("cls");
        #else
            std::cout << "\033[2J\033[H" << std::flush;
        #endif
    }

    void petc() {
        std::string dummy;
        std::cout << "Press enter to continue...";
        std::getline(std::cin, dummy);
    }
}