#include "./ui/telaMenu/include/viewMenu.hpp"
#include "./model/character/include/TechnicalSheet.hpp"
#include "./ui/telaBar/include/viewBar.hpp"

int main() {
    int level = 1;
    std::string name = "Hero";
    Species species = Species::HUMAN;
    Classes classes = Classes::WARRIOR;

    TechnicalSheet mainCharacter(level, name, species, classes);
    mainCharacter.increaseDracmas(100);

    try {
        Bar bar(&mainCharacter); // Passa o personagem principal para o Bar
        bar.run();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
