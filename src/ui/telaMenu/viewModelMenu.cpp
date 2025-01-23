#include "./include/viewModelMenu.hpp"
#include <iostream> // Include for std::cout

MenuViewModel::MenuViewModel(const sf::Font& font) : font(font) {
    // Button creation logic removed
}

void MenuViewModel::handlePlayButtonClick() {
    std::cout << "Jogar clicado!\n"; // Use std::cout
}

void MenuViewModel::handleAboutButtonClick() {
    std::cout << "Sobre clicado!\n"; // Use std::cout
}

void MenuViewModel::handleQuitButtonClick() {
    std::cout << "Sair clicado!\n"; // Use std::cout
}

bool MenuViewModel::isPlayButtonHovered(const sf::Vector2i& mousePos) const {
    return playButton->isHover(mousePos);
}

bool MenuViewModel::isQuitButtonHovered(const sf::Vector2i& mousePos) const {
    return quitButton->isHover(mousePos);
}   

// New methods to draw buttons removed