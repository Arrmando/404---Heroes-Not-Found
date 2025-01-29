#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

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

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

        Attributes buff{
            .hp = currentAttributes.hp*2*level,
            .magicAttack = 0,
            .physicalAttack = currentAttributes.physicalAttack*2*level,
            .magicDefense = 0,
            .physicalDefense = 0,
        };

        int timer = 18;

        attributesProcessor.setModifiersEffect(timer, buff);        

        std::cout << "Barbarian: Your raw strength and ferocity make you a relentless force in battle.";
    }
};