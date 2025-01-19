#include "./include/viewBar.hpp"
#include "./include/viewModel.hpp"

Bar::Bar()
    : telaBar(sf::VideoMode(600, 300), "Bar"){
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!barTexture.loadFromFile("assets/images/bar.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }

    barSprite.setTexture(barTexture);
    barSprite.setScale(0.35f, 0.35f);

    comprarMercenario = std::make_unique<Button>(10, 200, 200, 100, sf::Color::White, "Comprar", font, 50);

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(10, 10);

    updateMoneyText(); // Atualiza o texto do contador
 }

void Bar::updateMercenarioText() {
    mercenarioText.setString("ORK Guerreiro level: 15");
}
void Bar::updateMoneyText() {
    moneyText.setString("Dinheiro: " + std::to_string(money));
}
void Bar::handleEvents() {
    sf::Event event;
    while (telaBar.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaBar.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaBar);

            if (comprarMercenario->isClicked(mousePos) && money >= precoMecenario) {
                updateMoneyText(); // Atualiza o texto do contador
            }
        }
    }
}

void Bar::run() {
    while (telaBar.isOpen()) {
        handleEvents();
        render();
    }
}

void Bar::render() {
    telaBar.clear();
    telaBar.draw(barSprite);// Exibe o texto do dinheiro
    comprarMercenario->draw(telaBar);
    telaBar.draw(moneyText);
    telaBar.draw(mercenarioText);
    telaBar.display();
}