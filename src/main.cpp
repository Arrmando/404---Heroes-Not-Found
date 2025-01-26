#include "ui/telaMenu/include/viewMenu.hpp"
#include <iostream>

int main() {
    try {
        Menu menu;
        menu.run();

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
