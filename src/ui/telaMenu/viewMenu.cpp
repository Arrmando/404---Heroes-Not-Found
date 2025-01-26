#include "./include/viewMenu.hpp"
#include "../telaCidade/include/viewCidade.hpp"
#include <iostream>

Menu::Menu()
    : window(sf::VideoMode(800, 600), "Heroes not found"),
      font(),
      viewModel(std::make_unique<MenuViewModel>(font)) {
    if (!font.loadFromFile("assets/fonts/CongresoDePerros.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }

    titleText.setFont(font);
    titleText.setString("Heroes not found");
    titleText.setCharacterSize(100);
    titleText.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = titleText.getLocalBounds();
    titleText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    titleText.setPosition(300, 20);

    if (!backgroundTexture.loadFromFile("assets/images/menu.jpg")) {
        throw std::runtime_error("Erro ao carregar a textura de fundo!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    playButton = std::make_unique<Button>(150, 175, 200, 60, sf::Color(128, 128, 128), "Jogar", font, 50);
    aboutButton = std::make_unique<Button>(150, 245, 200, 60, sf::Color(128, 128, 128), "Sobre", font, 50);
    quitButton = std::make_unique<Button>(150, 315, 200, 60, sf::Color(128, 128, 128), "Sair", font, 50);

    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
}

void Menu::handleEvents() {
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        playButton->setColorHover(sf::Color(255, 165, 0), sf::Color(128, 128, 128), window);
        aboutButton->setColorHover(sf::Color(255, 165, 0), sf::Color(128, 128, 128), window);
        quitButton->setColorHover(sf::Color(255, 165, 0), sf::Color(128, 128, 128), window);

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (playButton->isHover(mousePos)) {
                window.close();
                viewModel->handlePlayButtonClick(); // Manda para o viewModel -> Abre a CIDADE
            }

            if (aboutButton->isHover(mousePos)) {
                window.close();
                viewModel->handleAboutButtonClick();
            }

            if (quitButton->isHover(mousePos)) {
                window.close();
            }
        }
    }
}

void Menu::render() {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(titleText);
    playButton->draw(window);
    aboutButton->draw(window);
    quitButton->draw(window);
    window.display();
}

void Menu::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}
