#include "./include/Button.hpp"

Button::Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label, sf::Font& font, float fontSize, bool isCircle, float borderThickness) {
    if (isCircle) {
        // Configura o botão circular
        float radius = width / 2.f; // Calcula o raio com base na largura
        circleShape.setRadius(radius);
        circleShape.setOrigin(radius, radius); // Define a origem no centro
        circleShape.setPosition(x + width / 2.f, y + height / 2.f); // Centraliza o círculo no ponto correto
        circleShape.setFillColor(color);
        circleShape.setOutlineThickness(borderThickness); // Define a grossura da borda
        circleShape.setOutlineColor(sf::Color::Black); // Define a cor padrão da borda
    } else {
        // Configura o botão retangular
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(color);
        shape.setOutlineThickness(borderThickness); // Define a grossura da borda
        shape.setOutlineColor(sf::Color::Black); // Define a cor padrão da borda
    }

    // Configura o texto (comum para ambos os tipos)
    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::Black);

    // Centraliza o texto no botão
    recalculateTextPosition();
}

void Button::setColor(const sf::Color& color) {
    if (circleShape.getRadius() > 0) {
        circleShape.setFillColor(color);  
    } else {
        shape.setFillColor(color);  
    }
}

void Button::setBorderColor(const sf::Color& borderColor) {
    if (circleShape.getRadius() > 0) {
        circleShape.setOutlineColor(borderColor);
    } else {
        shape.setOutlineColor(borderColor);
    }
}

void Button::setColorHover(const sf::Color& hoverColor, const sf::Color& defaultColor, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (isHover(mousePos)) {
        setColor(hoverColor);
    } else {
        setColor(defaultColor);
    }
}

void Button::draw(sf::RenderWindow& window) {
    if (circleShape.getRadius() > 0) {
        window.draw(circleShape); // Desenha o botão circular
    } else {
        window.draw(shape); // Desenha o botão retangular
    }
    window.draw(text); // Desenha o texto em ambos os casos
}

bool Button::isClicked(const sf::Vector2i& mousePos) {
    if (circleShape.getRadius() > 0) {
        return circleShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    } else {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}

bool Button::isHover(const sf::Vector2i& mousePos) const {
    if (circleShape.getRadius() > 0) {
        return circleShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    } else {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}

void Button::setText(const std::string& label) {
    text.setString(label);
    recalculateTextPosition(); // Recalcula a posição do texto
}

void Button::recalculateTextPosition() {
    if (circleShape.getRadius() > 0) {
        // Centraliza o texto no botão circular
        text.setPosition(
            circleShape.getPosition().x - text.getGlobalBounds().width / 2.f,
            circleShape.getPosition().y - text.getGlobalBounds().height / 2.f - text.getLocalBounds().top
        );
    } else {
        // Centraliza o texto no botão retangular
        text.setPosition(
            shape.getPosition().x + (shape.getSize().x - text.getGlobalBounds().width) / 2.f,
            shape.getPosition().y + (shape.getSize().y - text.getGlobalBounds().height) / 2.f - text.getLocalBounds().top
        );
    }
}
