#ifndef VIEW_MODEL_HPP
#define VIEW_MODEL_HPP

#include <SFML/Graphics.hpp>
#include <memory>      


class ViewModelCidade{
private:

sf::RenderWindow* janela;

public:

void mudarParaMenu();
void mudarParaCombate();
void mudarParaBar();

void fecharJanelaAtual();
};

#endif // VIEW_MODEL_HPP
