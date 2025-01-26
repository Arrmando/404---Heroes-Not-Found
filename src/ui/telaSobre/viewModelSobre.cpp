#include "./include/viewModelSobre.hpp"
#include "../telaMenu/include/viewMenu.hpp" // Include the viewCidade header

SobreViewModel::SobreViewModel(const sf::Font& font) : font(font) {}

void SobreViewModel::handleReturnButtonClick() {
    Menu menu; 
    menu.run();  
}
