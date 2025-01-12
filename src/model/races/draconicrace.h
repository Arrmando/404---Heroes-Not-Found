// código raça draconica

#ifndef draconic_H
#define draconic_H

#include "races.h"

class draconic : public Race {
public:
    draconic()
        : Race(120, 100, 100, 120, 120, "Droconic") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Draconic definidos.\n";
        // Configurações específicas para Draconic
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Draconic: sua descendencia e sangue de dragão provém grande resistência em seu couro endurecido aumentando também sua longevidade. \n";
    }
};

#endif // draconic_H