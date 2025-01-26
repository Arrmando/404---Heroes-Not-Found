#include "./include/viewLoja.hpp"
#include <iostream>

int main() {
    try {
        Loja loja;
        loja.run();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}