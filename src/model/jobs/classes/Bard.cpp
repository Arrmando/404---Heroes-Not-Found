#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Bard : public Jobs {
public:
    Bard() {
        Attributes bardModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.3f,
            .physicalAttack = 1.0f,
            .magicDefense = 1.2f,
            .physicalDefense = 0.9f
        };

        Job bard = {
            .occupation = Classes::BARD,
            .description = "A charismatic performer, inspiring allies and confounding enemies with music and magic.",
            .modifiers = bardModifiers
        };

        setJob(bard);
    }
    
     void skill(Attributes* buff, int* tempo, lvl) override { //cast all

        buff.hp *= lvl;
        buff.magicAttack *= (lvl/2);
        buff.magicDefense *= (lvl/2);
        buff.physicalAttack = 0;
        buff.physicalDefense = 0;
        tempo = 6; 
        std::cout << "Bard: You inspire and support your allies while weakening your enemies with your enchanting melodies.\n";
    }
};