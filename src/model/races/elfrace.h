// código raça elfica

#ifndef elf_H
#define elf_H

#include "races.h"

class elf : public Race {
public:
    elf()
        : Race(100, 125, 100, 125, 100, "Elf") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Elf definidos.\n";
        // Configurações específicas para Elf
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Elf: possui maior vínculo com o arcano, sendo um ser quase perfeito.\n";
    }
};

#endif // elf_H