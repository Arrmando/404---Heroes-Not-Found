#include "./include/viewSobre.hpp"
#include <iostream>

int main() {
    try {
        Sobre sobre;
        sobre.run();

    } catch (const std::exception& e) {
        std::cerr << "Erro: não foi possivel abrir a página Sobre" << e.what() << std::endl;
        return -1;
    }

    return 0;
}
