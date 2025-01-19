#include "./include/viewCidade.hpp"
#include <iostream>

int main() {
    try {
        Cidade cidade;
        cidade.run();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}