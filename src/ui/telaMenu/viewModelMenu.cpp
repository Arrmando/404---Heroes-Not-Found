#include "./include/viewModelMenu.hpp"
#include <iostream>
#include "../telaCidade/include/viewCidade.hpp" 

MenuViewModel::MenuViewModel(const sf::Font& font) : font(font) {}

void MenuViewModel::handlePlayButtonClick() {
    Cidade cidade; 
    cidade.run();  
}

void MenuViewModel::handleAboutButtonClick() {
    std::cout << "About button clicked!" << std::endl;
}
