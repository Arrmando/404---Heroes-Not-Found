#ifndef MENU_VIEW_MODEL_HPP
#define MENU_VIEW_MODEL_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "../../components/include/Button.hpp" // Updated path
#include <iostream>

class MenuViewModel {
public:
    MenuViewModel(const sf::Font& font);
    
    void handlePlayButtonClick(); // Declare the new method
    void handleAboutButtonClick();
    
private:
    const sf::Font& font;
};

#endif // MENU_VIEW_MODEL_HPP
