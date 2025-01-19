#include "./include/viewBar.hpp"
#include <iostream>

int main() {
    try {
        Bar bar;
        bar.run();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}