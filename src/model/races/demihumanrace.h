// código da raça gigante

#ifndef demihuman_H
#define demihuman_H

#include "races.h"

class demihuman : public Race {
public:
    demihuman()
        : Race(100, 120, 100, 100, 100, "Demihuman") {}

    virtual void setDefaultAttributes() override {
        std::cout << "Atributos padrão para Demihuman definidos.\n";
        // Configurações específicas para Demihuman
    }

    virtual void raceSpecialTrait() override {
        std::cout << "Demihuman: você é um híbrido da prole de humanos com outros seres mágicos, você possui maior proficência com ataques mágicos devido sua natureza.\n";
    }
};

#endif // demihuman_H