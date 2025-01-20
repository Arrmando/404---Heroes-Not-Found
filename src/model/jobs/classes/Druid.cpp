#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Druid : public Jobs {
public:
    Druid() {
        Attributes druidModifiers = {
            .hp = 1.3f,
            .magicAttack = 1.3f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.2f,
            .physicalDefense = 1.1f
        };

        Job druid = {
            .occupation = Classes::DRUID,
            .description = "A guardian of nature, capable of shapeshifting and wielding natural magic.",
            .modifiers = druidModifiers
        };

        setJob(druid);
    }

    void skill(int* hp, int level) override { //Necessário que hp seja igual ao HP máximo do druida; //cast all
        hp = hp*(0.1+(0.01*level));
        job.skill(&hp);
        std::cout << "Druid: Your connection to nature grants you unique powers and versatility.";
    }
};