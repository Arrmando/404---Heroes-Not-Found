#include "./include/viewSobre.hpp"
#include "../telaCidade/include/viewCidade.hpp"
#include <iostream>

Sobre::Sobre()
    : window(sf::VideoMode(800, 600), "Criadores"),
      font(),
      viewModel(std::make_unique<SobreViewModel>(font)) {
    if (!font.loadFromFile("assets/fonts/CongresoDePerros.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }

    titleText.setFont(font);
    titleText.setString("Desenvolvedores:");
    titleText.setCharacterSize(100);
    titleText.setFillColor(sf::Color::Black);

    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setOrigin(titleBounds.width / 2, titleBounds.height / 2);
    titleText.setPosition(300, 100); // Centered title

    // Adding developer names
    nomeText.setFont(font);
    nomeText.setString("   FrontEnd\n1. Guilherme Fachinelli\n2. Rafael Campello Soares\n3. Gustavo Silvestre Barroso");
    nomeText.setCharacterSize(40);
    nomeText.setFillColor(sf::Color::Black);
    nomeText.setPosition(100, 230); 

    if (!backgroundTexture.loadFromFile("assets/images/Sobre.png")) {
        throw std::runtime_error("Erro ao carregar a textura de fundo!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    returnButton = std::make_unique<Button>(20, 20, 200, 60, sf::Color(128, 128, 128), "Voltar", font, 50);

    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
}

void Sobre::handleEvents() {
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        returnButton->setColorHover(sf::Color(255, 165, 0), sf::Color(128, 128, 128), window);

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (returnButton->isHover(mousePos)) {
                window.close();
                viewModel->handleReturnButtonClick(); // Manda para o viewModel -> Abre a CIDADE
            }
        }
    }
}

void Sobre::render() {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(titleText);
    window.draw(nomeText); // Draw developer names
    returnButton->draw(window);
    window.display();
}

void Sobre::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}
