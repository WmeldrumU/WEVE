

#include "app.hpp"

// std
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    weve::App app{};

    try {
        std::cout << "hello weve" << '\n';
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << '\n';
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}