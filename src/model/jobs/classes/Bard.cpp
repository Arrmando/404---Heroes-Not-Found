#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

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
    
    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

        Attributes buff{
            .hp = currentAttributes.hp * level,
            .magicAttack = currentAttributes.magicAttack * (level/2),
            .physicalAttack = 0,            
            .magicDefense = currentAttributes.magicDefense * (level/2),
            .physicalDefense = 0,
        };
        
        int timer = 6;

        attributesProcessor.setModifiersEffect(timer, buff);

        std::cout << "Bard: You inspire and support your allies while weakening your enemies with your enchanting melodies.\n";
    }
};