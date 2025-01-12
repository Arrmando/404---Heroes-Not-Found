
// código raça fada 

#ifndef fairy_H
#define fairy_H

#include "races.h"

class Fairy : public Race {
public:
    Fairy()
        : Race(100, 120, 70, 60, 70, "Fairy") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Fairy definidos.\n";
        // Configurações específicas para Fairy
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Fairy: levemente forte em ataque e defesa mágica.\n";
    }
};

#endif // fairy_H

git config --global user.name "EliasDMS"
git config --global user.email "eliasdaniel_ms@outlook.com.br"