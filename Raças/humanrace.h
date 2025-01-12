// código raça humana

#ifndef human_H
#define human_H

#include "races.h"

class human : public Race {
public:
    human()
        : Race(100, 100, 100, 100, 100, "Human") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Human definidos.\n";
        // Configurações específicas para Human
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Human: possui escala de atributos normal.\n";
    }
};

#endif // human_H

git config --global user.name "EliasDMS"
git config --global user.email "eliasdaniel_ms@outlook.com.br"