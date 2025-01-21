#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Cleric : public Jobs {
public:
    Cleric() {
        Attributes clericModifiers = {
            .hp = 1.0f,
            .magicAttack = 1.3f,
            .physicalAttack = 0.8f,
            .magicDefense = 1.4f,
            .physicalDefense = 1.0f
        };

        Job cleric = {
            .occupation = Classes::CLERIC,
            .description = "A divine spellcaster, focused on healing and protecting allies through holy magic.",
            .modifiers = clericModifiers
        };

        setJob(cleric);
    }

    void skill(int* hp, int level) override { //Necessário que hp seja igual ao HP máximo do clérigo; //cast all
        hp = hp*(0.2+(0.02*level));
        job.skill(&hp);
        std::cout << "Cleric: You channel divine power to heal and protect your allies, ensuring their survival.\n";
    }
};




