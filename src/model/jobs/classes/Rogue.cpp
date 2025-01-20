#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Rogue : public Jobs {
public:
    Rogue() {
        Attributes rogueModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.3f,
            .magicDefense = 1.0f,
            .physicalDefense = 1.1f
        };

        Job rogue = {
            .occupation = Classes::ROGUE,
            .description = "A nimble and cunning fighter, skilled in evasion and precise attacks.",
            .modifiers = rogueModifiers
        };

        setJob(rogue);
    }

     void skill(Attributes* buff, int* tempo, lvl) override { //cast self

        buff.hp = 0;
        buff.magicAttack *= 2;
        buff.magicDefense = 0;
        buff.physicalAttack *= 3;
        buff.physicalDefense = 0;
        tempo = 3;    
        std::cout << "Rogue: Your agility and cunning make you a deadly and elusive opponent.\n";
    }
};