#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Barbarian : public Jobs {
public:
    Barbarian() {
        Attributes barbarianModifiers = {
            .hp = 1.4f,
            .magicAttack = 0.5f,
            .physicalAttack = 1.5f,
            .magicDefense = 0.6f,
            .physicalDefense = 1.0f
        };

        Job barbarian = {
            .occupation = Classes::BARBARIAN,
            .description = "A fierce warrior fueled by rage, excelling in raw physical power.",
            .modifiers = barbarianModifiers
        };

        setJob(barbarian);
    }

    void skill(Attributes* buff, int* tempo, lvl) override { //cast self
        buff.hp *= 2*lvl;
        buff.magicAttack = 0;
        buff.magicDefense = 0;
        buff.physicalAttack *= 2*lvl;
        buff.physicalDefense = 0;
        tempo = 18; 

        std::cout << "Barbarian: Your raw strength and ferocity make you a relentless force in battle.";
    }
};