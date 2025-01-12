
// código raça Undead

#ifndef undead_H
#define undead_H

#include "races.h"

class undead : public Race {
public:
    undead()
        : Race(125, 100, 100, 75, 75, "Undead") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Undead definidos.\n";
        // Configurações específicas para Undead
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Undead: Sua desobediencia as ordens naturais em se manter vivo te torna mais sedento a vida porém mais vulneráavel devido sua podridão (possui maior escala de vida porém menor escala de defesa)\n";
    
    }
};

#endif // undead_H