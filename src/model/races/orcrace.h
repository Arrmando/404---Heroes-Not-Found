// código raça orquica

#ifndef orc_H
#define orc_H

#include "races.h"

class orc : public Race {
public:
    orc()
        : Race(100, 100, 125, 100, 125, "Orc") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Orc definidos.\n";
        // Configurações específicas para Orc
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Orc: sua natureza selkvagem te permite ser um guerreiro incrível (maior aptidão com ataques físicos e defesa física).\n";
    }
};

#endif // orc_H