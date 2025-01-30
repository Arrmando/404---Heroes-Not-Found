#include "./character/include/CharacterProcessor.hpp"
#include <iostream>

int main() {
    try {
        CharacterProcessor processor;
        processor.addCharacter(
            31,
            "Goldorath",
            Species::ORC,
            Classes::SORCERER
        );

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}