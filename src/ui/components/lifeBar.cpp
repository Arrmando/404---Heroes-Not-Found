#include "./include/lifeBar.hpp"

lifeBar::lifeBar(float x, float y, float width, float height, const sf::Color& fillColor, float maxLife, float currentLife) {
    this->maxLife;     // É PRECISO PEGAR ESSE VALOR DO MODEL
    this->currentLife; 
    isFlashing = false;   // Define se está piscando

    lifeWidth = width * (currentLife / maxLife); // Define a largura da barra de vida com base na % atual

    // Inicializa a barra de vida
    lifeFill.setSize(sf::Vector2f(lifeWidth, height));
    lifeFill.setFillColor(fillColor);
    lifeBack.setOutlineThickness(2);
    lifeFill.setPosition(x, y);

    // Inicializa o fundo
    lifeBack.setSize(sf::Vector2f(width, height));
    lifeBack.setFillColor(sf::Color::Black);
    lifeBack.setOutlineThickness(2);
    lifeBack.setOutlineColor(sf::Color::Black);
    lifeBack.setPosition(x, y);

}

void lifeBar::draw(sf::RenderWindow& window) {
    window.draw(lifeBack);
    window.draw(lifeFill);
}