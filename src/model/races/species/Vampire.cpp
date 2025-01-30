#include "Races.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include <iostream>
#include "Vampire.hpp"

Vampire::Vampire() {
    Attributes vampireAttributes = { 
        .hp = 80.0f, 
        .magicAttack = 25.0f, 
        .physicalAttack = 25.0f, 
        .magicDefense = 10.0f, 
        .physicalDefense = 10.0f 
    };

    Attributes vampireModifiers = { 
        .hp = 0.8f, 
        .magicAttack = 1.25f, 
        .physicalAttack = 1.25f, 
        .magicDefense = 0.8f, 
        .physicalDefense = 0.8f 
    };

    Race vampire = {
        .species = Species::VAMPIRE,
        .description = "a nocturnal creature whose health is a little more fragile, but you have great attack strength and magic for your hunts.",
        .attributes = vampireAttributes,
        .modifiers = vampireModifiers
    };

    setRace(vampire);
}

void Vampire::setRaceSpecialTrait() {
    std::cout << "Vampire: você é uma criatura noturna cuja saúde é um pouco mais frágil, porém você possui grande força de ataque e mágica para suas caçadas\n";
}