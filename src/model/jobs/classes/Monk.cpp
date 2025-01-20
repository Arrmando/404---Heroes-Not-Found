#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Monk : public Jobs {
public:
    Monk() {
        Attributes monkModifiers = {
            .hp = 1.1f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.2f,
            .physicalDefense = 1.2f
        };

        Job monk = {
            .occupation = Classes::MONK,
            .description = "A disciplined combatant who channels spiritual energy into martial prowess.",
            .modifiers = monkModifiers
        };

        setJob(monk);
    }

    void skill() override {

        void skill(Attributes* buff, int* tempo, lvl) override { //cast self

        buff.hp = 0;
        buff.magicAttack = 0;
        buff.magicDefense *= lvl;
        buff.physicalAttack *= lvl;
        buff.physicalDefense *= lvl;
        tempo = 12; 

        std::cout << "Monk: Your discipline and spiritual energy make you a master of martial arts.";
    }
};