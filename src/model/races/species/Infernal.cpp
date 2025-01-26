#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Infernal : public Races {
public:
    Infernal() {
        Attributes infernalAttributes = { 
            .hp = 100.0f, 
            .magicAttack = 23.0f, 
            .physicalAttack = 20.0f, 
            .magicDefense = 18.0f, 
            .physicalDefense = 15.0f 
        };

        Attributes infernalModifiers = { 
            .hp = 1.0f, 
            .magicAttack = 1.2f, 
            .physicalAttack = 1.0f, 
            .magicDefense = 1.2f, 
            .physicalDefense = 1.0f 
        };

        Race infernal = {
            .species = Species::INFERNAL,
            .description = "A versatile race with well-balanced physical and a stronger magical attributes.",
            .attributes = infernalAttributes,
            .modifiers = infernalModifiers
        };

        setRace(infernal);
    }

protected:
    void setRaceSpecialTrait() override {
        std::cout << "Infernal: você é uma raça equilibrada, com boa adaptabilidade, possui maior adaptabilidade a magia e uma boa defesa mágica devido suas origens infernais.\n";
    }
};
