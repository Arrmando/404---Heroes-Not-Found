#include "./include/viewSobre.hpp"
#include "../telaCidade/include/viewCidade.hpp"
#include <algorithm>
#include <vector>

Sobre::Sobre()
    : window(sf::VideoMode(800, 600), "Criadores"),
      font(),
      viewModel(std::make_unique<SobreViewModel>(font)) {
    if (!font.loadFromFile("assets/fonts/CongresoDePerros.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }

    // Configuração do título principal
    titleText.setFont(font);
    titleText.setString("Desenvolvedores:");
    titleText.setCharacterSize(80);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(250, 50);

    // Configuração dos títulos das colunas
    frontendTitleText.setFont(font);
    frontendTitleText.setString("FrontEnd");
    frontendTitleText.setCharacterSize(50);
    frontendTitleText.setFillColor(sf::Color::Black);
    frontendTitleText.setPosition(100, 150);

    backendTitleText.setFont(font);
    backendTitleText.setString("BackEnd");
    backendTitleText.setCharacterSize(50);
    backendTitleText.setFillColor(sf::Color::Black);
    backendTitleText.setPosition(450, 150);

    // Lista de nomes ordenados alfabeticamente
    std::vector<std::string> frontendNames = {
        "Gustavo Silvestre ",
        "Guilherme Fachinelli",
        "Rafael Campello "
    };
    std::sort(frontendNames.begin(), frontendNames.end());

    std::vector<std::string> backendNames = {
        "Arthur Rafael",
        "Elias Daniel",
        "Pedro Armando"
    };
    std::sort(backendNames.begin(), backendNames.end());

    // Configuração dos textos dos nomes
    nomeText.setFont(font);
    nomeText.setString("1. " + frontendNames[0] + "\n\n2. " + frontendNames[1] + "\n\n3. " + frontendNames[2]);
    nomeText.setCharacterSize(35);
    nomeText.setFillColor(sf::Color::Black);
    nomeText.setPosition(100, 230);

    backendText.setFont(font);
    backendText.setString("1. " + backendNames[0] + "\n\n2. " + backendNames[1] + "\n\n3. " + backendNames[2]);
    backendText.setCharacterSize(35);
    backendText.setFillColor(sf::Color::Black);
    backendText.setPosition(450, 230);

    // Configuração do background
    if (!backgroundTexture.loadFromFile("assets/images/Sobre.png")) {
        throw std::runtime_error("Erro ao carregar a textura de fundo!");
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Botão de retorno
    returnButton = std::make_unique<Button>(20, 20, 200, 60, sf::Color(128, 128, 128), "Voltar", font, 50);

    // Ajuste de escala do background
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
                viewModel->handleReturnButtonClick();
            }
        }
    }
}

void Sobre::render() {
    window.clear();
    window.draw(backgroundSprite);
    window.draw(titleText);
    window.draw(frontendTitleText);
    window.draw(backendTitleText);
    window.draw(nomeText);
    window.draw(backendText);
    returnButton->draw(window);
    window.display();
}

void Sobre::run() {
    while (window.isOpen()) {
        handleEvents();
        render();
    }
}