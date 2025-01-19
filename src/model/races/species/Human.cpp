#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Human : public Races {
public:
    Human() {
        Attributes humanAttributes = { 
            .hp = 100.0f, 
            .magicAttack = 20.0f, 
            .physicalAttack = 20.0f, 
            .magicDefense = 15.0f, 
            .physicalDefense = 15.0f 
        };

        Attributes humanModifiers = { 
            .hp = 1.1f, 
            .magicAttack = 1.0f, 
            .physicalAttack = 1.0f, 
            .magicDefense = 1.0f, 
            .physicalDefense = 1.0f 
        };

        Race human = {
            .species = Species::HUMAN,
            .description = "A versatile race with well-balanced physical and magical attributes.",
            .attributes = humanAttributes,
            .modifiers = humanModifiers
        };

        setRace(human);
    }

protected:
    void setRaceSpecialTrait() override {
        std::cout << "Human: você é uma raça equilibrada, com boa adaptabilidade e resistência tanto física quanto mágica.\n";
    }
};
