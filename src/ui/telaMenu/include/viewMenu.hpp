#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <string>
#include "../../components/include/Button.hpp" // Updated path to Button.hpp
#include "viewModelMenu.hpp"

class Menu {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text titleText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    // Button member variables
    std::unique_ptr<Button> playButton;
    std::unique_ptr<Button> aboutButton;
    std::unique_ptr<Button> quitButton;

    // ViewModel member variable
    std::unique_ptr<MenuViewModel> viewModel; // Added viewModel

public:
    Menu();
    void handleEvents();
    void render();
    void run();

    // Button handling methods
    void handlePlayButtonClick();
    void handleAboutButtonClick();
    void handleQuitButtonClick();
    bool isPlayButtonHovered(const sf::Vector2i& mousePos) const;
    bool isAboutButtonHovered(const sf::Vector2i& mousePos) const;
    bool isQuitButtonHovered(const sf::Vector2i& mousePos) const;
};

#endif
