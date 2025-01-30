#include "Races.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include <iostream>
#include "Orc.hpp"

Orc::Orc() {
    Attributes orcAttributes = { 
        .hp = 130.0f, 
        .magicAttack = 15.0f, 
        .physicalAttack = 35.0f, 
        .magicDefense = 10.0f, 
        .physicalDefense = 30.0f 
    };

    Attributes orcModifiers = { 
        .hp = 1.3f, 
        .magicAttack = 0.9f, 
        .physicalAttack = 1.5f, 
        .magicDefense = 0.8f, 
        .physicalDefense = 1.4f 
    };

    Race orc = {
        .species = Species::ORC,
        .description = "A strong, aggressive race with high physical power and solid defense but weaker magic abilities.",
        .attributes = orcAttributes,
        .modifiers = orcModifiers
    };

    setRace(orc);
}

void Orc::setRaceSpecialTrait() {
    std::cout << "Orc: você possui grande força física e resistência, ideal para combate direto e estratégias de destruição.\n";
}