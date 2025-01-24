#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    // Construtor modificado com o parâmetro isCircle
    Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label, sf::Font& font, float fontSize, bool isCircle = false);

    // Métodos para alterar e interagir com o botão
    void setColor(const sf::Color& color);
    void setColorHover(const sf::Color& hoverColor, const sf::Color& defaultColor, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePos);
    bool isHover(const sf::Vector2i& mousePos) const;
    void setText(const std::string& label);

private:
    // Forma do botão: pode ser um retângulo ou círculo
    sf::RectangleShape shape;
    sf::CircleShape circleShape;
    
    // Texto do botão
    sf::Text text;
};

#endif // BUTTON_HPP
