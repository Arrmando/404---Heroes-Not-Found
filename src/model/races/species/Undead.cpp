#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Undead : public Races {
public:
    Undead() {
        Attributes undeadAttributes = { 
            .hp = 140.0f, 
            .magicAttack = 10.0f, 
            .physicalAttack = 20.0f, 
            .magicDefense = 15.0f, 
            .physicalDefense = 25.0f 
        };

        Attributes undeadModifiers = { 
            .hp = 1.3f, 
            .magicAttack = 0.8f, 
            .physicalAttack = 1.1f, 
            .magicDefense = 1.0f, 
            .physicalDefense = 1.2f 
        };

        Race undead = {
            .species = Species::UNDEAD,
            .description = "Reanimated corpses, usually possessing resilience and a resistance to magic.",
            .attributes = undeadAttributes,
            .modifiers = undeadModifiers
        };

        setRace(undead);
    }

protected:
    void setRaceSpecialTrait() override {
        std::cout << "Undead: você é imune a muitos efeitos mágicos e possui resistência aumentada a ataques físicos.\n";
    }
};