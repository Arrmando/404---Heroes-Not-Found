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
    void handlePlayButtonClick();
    void handleAboutButtonClick();
    void handleQuitButtonClick();
    bool isPlayButtonHovered(const sf::Vector2i& mousePos) const;
    bool isAboutButtonHovered(const sf::Vector2i& mousePos) const;
    bool isQuitButtonHovered(const sf::Vector2i& mousePos) const;

    // New methods to draw buttons
    void drawPlayButton(sf::RenderWindow& window) const;
    void drawAboutButton(sf::RenderWindow& window) const;
    void drawQuitButton(sf::RenderWindow& window) const;

    // Changed to public
    std::unique_ptr<Button> playButton;
    std::unique_ptr<Button> aboutButton;
    std::unique_ptr<Button> quitButton;

private:
    sf::Font font;
};

#endif
