#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Timer {
public:
    Timer(sf::Font& font, float x, float y, int size = 30);

    void start(int seconds);           // Inicia a contagem regressiva
    void reset();                      // Reseta o timer para o valor original
    void update(sf::Time deltaTime);   // Atualiza o timer com base no tempo decorrido
    void draw(sf::RenderWindow& window); // Desenha o timer na janela
    bool isFinished() const;           // Retorna se o timer chegou a zero

private:
    sf::Text text;                     // Texto exibido na tela
    int initialTime;                   // Tempo inicial (em segundos)
    float remainingTime;               // Tempo restante (em segundos)
    bool finished;                     // Indica se o timer terminou

    void updateText();                 // Atualiza o texto exibido
};

#endif // TIMER_HPP
