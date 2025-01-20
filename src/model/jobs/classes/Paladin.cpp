#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Paladin : public Jobs {
public:
    Paladin() {
        Attributes paladinModifiers = {
            .hp = 1.2f,
            .magicAttack = 1.1f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.3f,
            .physicalDefense = 1.2f
        };

        Job paladin = {
            .occupation = Classes::PALADIN,
            .description = "A holy warrior, combining physical strength with divine magic to protect and heal.",
            .modifiers = paladinModifiers
        };

        setJob(paladin);
    }

    void skill(Attributes* buff, int* tempo, lvl) override { //cast all

        buff.hp *= (lvl/3);
        buff.magicAttack *= (lvl/3);
        buff.magicDefense *= (lvl/2);
        buff.physicalAttack *= (lvl/3);
        buff.physicalDefense *= (lvl/2);
        tempo = 6; 
        std::cout << "Paladin: You combine holy magic with martial prowess to shield and support your allies.\n";
    }
};