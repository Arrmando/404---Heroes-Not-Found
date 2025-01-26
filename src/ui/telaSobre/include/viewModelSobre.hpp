#ifndef SOBRE_VIEW_MODEL_HPP
#define SOBRE_VIEW_MODEL_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "../../components/include/Button.hpp" 
#include <iostream>

class SobreViewModel {
public:
    SobreViewModel(const sf::Font& font);
    
    void handleReturnButtonClick(); 

    
private:
    const sf::Font& font;
};

#endif 
