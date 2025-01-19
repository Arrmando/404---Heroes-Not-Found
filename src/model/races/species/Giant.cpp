#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Giant : public Races {
public:
    Giant() {
        Attributes giantAttributes = { 
            .hp = 150.0f, 
            .magicAttack = 10.0f, 
            .physicalAttack = 30.0f, 
            .magicDefense = 10.0f, 
            .physicalDefense = 25.0f 
        };

        Attributes giantModifiers = { 
            .hp = 1.4f, 
            .magicAttack = 0.8f, 
            .physicalAttack = 1.4f, 
            .magicDefense = 0.9f, 
            .physicalDefense = 1.3f 
        };

        Race giant = {
            .species = Species::GIANT,
            .description = "Large, powerful beings with great physical strength but limited magical ability.",
            .attributes = giantAttributes,
            .modifiers = giantModifiers
        };

        setRace(giant);
    }
    
protected:
    void setRaceSpecialTrait()  override {
        std::cout << "Giant: sua força física é imensa, capaz de realizar feitos de grande resistência e destruição, mas suas habilidades mágicas são limitadas.\n";
    }
};