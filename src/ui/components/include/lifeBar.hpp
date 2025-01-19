#ifndef LIFEBAR_HPP
#define LIFEBAR_HPP

#include <SFML/Graphics.hpp>
#include <string>

class lifeBar {
private:
    sf::RectangleShape lifeFill;
    sf::RectangleShape lifeBack;
    float maxLife;
    float currentLife;
    float lifeWidth;    
    bool isFlashing;

public:
    lifeBar(float x, float y, float width, float height, const sf::Color& fillcolor, float maxLife, float currentLife);
    void reduceLife(float amount);
    void update();
    void draw(sf::RenderWindow& window);
};

#endif
