#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Fairy : public Races {
public:
    Fairy() {
        Attributes fairyAttributes = { 
            .hp = 60.0f, 
            .magicAttack = 40.0f, 
            .physicalAttack = 10.0f, 
            .magicDefense = 25.0f, 
            .physicalDefense = 5.0f 
        };

        Attributes fairyModifiers = { 
            .hp = 0.8f, 
            .magicAttack = 1.5f, 
            .physicalAttack = 0.7f, 
            .magicDefense = 1.3f, 
            .physicalDefense = 0.6f 
        };

        Race fairy = {
            .species = Species::FAIRY,
            .description = "Small, magical creatures with exceptional powers in magic but lacking in physical strength.",
            .attributes = fairyAttributes,
            .modifiers = fairyModifiers
        };

        setRace(fairy);
    }
    
protected:
    void setRaceSpecialTrait()  override {
        std::cout << "Fairy: você é uma criatura mágica de pequena estatura, com grande controle sobre magias e feitiços.\n";
    }
};