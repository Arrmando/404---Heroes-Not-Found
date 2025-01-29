#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Draconic : public Races {
public:
    Draconic() {
        Attributes draconicAttributes = { 
            .hp = 120.0f, 
            .magicAttack = 25.0f, 
            .physicalAttack = 25.0f, 
            .magicDefense = 20.0f, 
            .physicalDefense = 20.0f 
        };

        Attributes draconicModifiers = { 
            .hp = 1.2f, 
            .magicAttack = 1.2f, 
            .physicalAttack = 1.2f, 
            .magicDefense = 1.1f, 
            .physicalDefense = 1.1f 
        };

        Race draconic = {
            .species = Species::DRACONIC,
            .description = "A noble and ancient race, powerful both physically and magically.",
            .attributes = draconicAttributes,
            .modifiers = draconicModifiers
        };

        setRace(draconic);
    }

protected:
    void setRaceSpecialTrait() override {
        std::cout << "Draconic: você possui grande poder tanto em magia quanto em combate físico, sendo uma força da natureza.\n";
    }
};