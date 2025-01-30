#include "./include/viewBar.hpp"
#include "./include/viewModelBar.hpp"

Bar::Bar()
    : telaBar(sf::VideoMode(900, 600), "Bar"),
      timer(font, 800, 20, 30) {
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!barTexture.loadFromFile("assets/images/bar.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }

    timer.start(120);
    viewModel = new ViewModelBar();
    
    barSprite.setTexture(barTexture);
    barSprite.setScale(1.5f, 1.8f);

    comprarMercenario = std::make_unique<Button>(350, 300, 400, 50, sf::Color::Yellow, "Comprar Mercenario", font, 30);
    retornar = std::make_unique<Button>(20, 20, 200, 60, sf::Color(128, 128, 128), "Voltar", font, 50);

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(20, 90);

    updateMoneyText();
}

void Bar::updateMoneyText() {
    moneyText.setString("Dracmas: " + std::to_string(Dracmas::getQuantidade()));
}

void Bar::handleEvents() {
    sf::Event event;
    while (telaBar.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaBar.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaBar);

            if (comprarMercenario->isClicked(mousePos) && Dracmas::getQuantidade() >= precoMecenario) {
                Dracmas::subtrair(precoMecenario);
                updateMoneyText();
            }
            if (retornar->isClicked(mousePos)) {
                telaBar.close();
                viewModel->mudarParaCidade();
            }
        }
    }
}

void Bar::run() {
    while (telaBar.isOpen()) {
        handleEvents();
        update();
        render();
    }
}


void Bar::update() {
    sf::Time deltaTime = gameClock.restart();
    timer.update(deltaTime);
    updateMoneyText(); // Atualiza o texto do dinheiro
}

void Bar::render() {
    sf::Color hoverColor = sf::Color(200, 200, 200);
    sf::Color defaultColor = sf::Color(128, 128, 128);

    comprarMercenario->setColorHover(hoverColor, defaultColor, telaBar);
    retornar->setColorHover(sf::Color(255, 165, 0), sf::Color(128, 128, 128), telaBar);

    telaBar.clear();
    telaBar.draw(barSprite);
    comprarMercenario->draw(telaBar);
    retornar->draw(telaBar);
    timer.draw(telaBar);
    telaBar.draw(moneyText);
    telaBar.display();
}