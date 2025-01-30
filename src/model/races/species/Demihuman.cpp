#include "Races.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include <iostream>
#include "Demihuman.hpp"

Demihuman::Demihuman() {
    Attributes demihumanAttributes = { 
        .hp = 110.0f, 
        .magicAttack = 15.0f, 
        .physicalAttack = 25.0f, 
        .magicDefense = 10.0f, 
        .physicalDefense = 20.0f 
    };

    Attributes demihumanModifiers = { 
        .hp = 1.2f, 
        .magicAttack = 0.9f, 
        .physicalAttack = 1.2f, 
        .magicDefense = 0.9f, 
        .physicalDefense = 1.1f 
    };

    Race demihuman = {
        .species = Species::DEMIHUMAN,
        .description = "Hybrid beings with traits of humans and other creatures, often strong and resilient.",
        .attributes = demihumanAttributes,
        .modifiers = demihumanModifiers
    };

    setRace(demihuman);
}

void Demihuman::setRaceSpecialTrait() {
    std::cout << "Demihuman: você é um híbrido da prole de humanos com outros seres mágicos, você possui maior proficência com ataques mágicos devido sua natureza.\n";
}