#include "./include/timer.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

Timer::Timer(sf::Font& font, float x, float y, int size)
    : initialTime(0), remainingTime(0), finished(true) {
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    updateText();
}

void Timer::start(int seconds) {
    initialTime = seconds;
    remainingTime = static_cast<float>(seconds);
    finished = false;
    updateText();
}

void Timer::reset() {
    remainingTime = static_cast<float>(initialTime);
    finished = false;
    updateText();
}

void Timer::update(sf::Time deltaTime) {
    if (finished) return;

    remainingTime -= deltaTime.asSeconds();
    if (remainingTime <= 0) {
        remainingTime = 0;
        finished = true;
    }
    updateText();
}

void Timer::draw(sf::RenderWindow& window) {
    window.draw(text);
}

bool Timer::isFinished() const {
    return finished;
}

void Timer::updateText() {
    int minutes = static_cast<int>(remainingTime) / 60;
    int seconds = static_cast<int>(remainingTime) % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << seconds;
    std::cout << "Timer: " << oss.str() << std::endl;
    text.setString(oss.str());
}
