// código da raça gigante

#ifndef giant_H
#define giant_H

#include "races.h"

class giant : public Race {
public:
    giant()
        : Race(150, 50, 70, 110, 130, "Giant") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Giant definidos.\n";
        // Configurações específicas para Giant
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Giant: Alto em defesa e vida, porém baixo em ataque.\n";
    }
};

#endif // giant_H