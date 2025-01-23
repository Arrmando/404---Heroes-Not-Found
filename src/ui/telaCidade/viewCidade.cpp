#include "./include/viewCidade.hpp"

Cidade::Cidade()
    : telaCidade(sf::VideoMode(700, 700), "Cidade"){
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!cidadeTexture.loadFromFile("assets/images/cidade.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }

    cidadeSprite.setTexture(cidadeTexture);
    cidadeSprite.setScale(0.35f, 0.35f);

    irMenu = std::make_unique<Button>(350, 500, 200, 100, sf::Color::Yellow, "Menu", font, 30);
    irBar = std::make_unique<Button>(350, 200, 200, 100, sf::Color::Yellow, "Bar", font, 30);
    irCombate = std::make_unique<Button>(350, 50, 200, 100, sf::Color::Yellow, "Combate", font, 30);
    irLoja = std::make_unique<Button>(350, 350, 200, 100, sf::Color::Yellow, "Loja", font, 30); // Initialize irLoja

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(10, 10);

    updateMoneyText(); // Atualiza o texto do contador

    viewModel = new ViewModelCidade();
}

void Cidade::updateMoneyText() {                                                                                                                                     
    moneyText.setString("Dinheiro: " + std::to_string(money) + " R$");
}

void Cidade::handleEvents() {
    sf::Event event;
    while (telaCidade.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaCidade.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaCidade);

            if (irLoja->isClicked(mousePos)) {
              telaCidade.close();
              viewModel->mudarParaLoja();
            }

            if (irMenu->isClicked(mousePos)) {
              telaCidade.close();
              viewModel->mudarParaMenu();
            }
    
            if (irBar->isClicked(mousePos)) {
              telaCidade.close();
              viewModel->mudarParaBar();
            }

            if (irCombate->isClicked(mousePos)) {
              telaCidade.close();
              viewModel->mudarParaCombate();
            }
        }
    }
}

void Cidade::run() {
    while (telaCidade.isOpen()) {
        handleEvents();
        render();
    }
}

void Cidade::render() {
    telaCidade.clear();
    telaCidade.draw(cidadeSprite); // Exibe o texto do dinheiro
    irCombate->draw(telaCidade);
    irLoja->draw(telaCidade); // Ensure irLoja is drawn
    irBar->draw(telaCidade);
    irMenu->draw(telaCidade);
    telaCidade.draw(moneyText);
    telaCidade.display();
}
