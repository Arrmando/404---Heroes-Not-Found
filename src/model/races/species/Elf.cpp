#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Elf : public Races {
public:
    Elf() {
        Attributes elfAttributes = { 
            .hp = 80.0f, 
            .magicAttack = 30.0f, 
            .physicalAttack = 15.0f, 
            .magicDefense = 20.0f, 
            .physicalDefense = 10.0f 
        };

        Attributes elfModifiers = { 
            .hp = 1.0f, 
            .magicAttack = 1.3f, 
            .physicalAttack = 0.9f, 
            .magicDefense = 1.2f, 
            .physicalDefense = 0.8f 
        };

        Race elf = {
            .species = Species::ELF,
            .description = "A magical race with high proficiency in spellcasting and weaker physical prowess.",
            .attributes = elfAttributes,
            .modifiers = elfModifiers
        };

        setRace(elf);
    }
    
protected:
    void setRaceSpecialTrait()  override {
        std::cout << "Elf: você possui grande habilidade mágica e uma natureza ágil, ideal para magias e tarefas que exigem destreza.\n";
    }
};