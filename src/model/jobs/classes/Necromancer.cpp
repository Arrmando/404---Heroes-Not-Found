#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Necromancer : public Jobs {
public:
    Necromancer() {
        Attributes necromancerModifiers = {
            .hp = 0.7f,
            .magicAttack = 1.7f,
            .physicalAttack = 0.6f,
            .magicDefense = 1.2f,
            .physicalDefense = 0.8f
        };

        Job necromancer = {
            .occupation = Classes::NECROMANCER,
            .description = "A master of death magic, capable of raising undead minions and cursing foes.",
            .modifiers = necromancerModifiers
        };

        setJob(necromancer);
    }

    void skill(Attributes* buff, int* tempo, lvl) override { //cast self

        buff.hp *= lvl;
        buff.magicAttack *= lvl;
        buff.magicDefense *= lvl;
        buff.physicalAttack = 0;
        buff.physicalDefense = 0;
        tempo = 12; 

        std::cout << "Necromancer: Your dark magic allows you to control death itself.";
    }
};