#ifndef DRACMAS_HPP
#define DRACMAS_HPP

#include <string> // Necessário para std::string

class Dracmas {
private:
    static Dracmas* instance; // Declaração
    int quantidade;

    Dracmas() : quantidade(10) {} // Construtor privado

public:
    // Eliminar cópias
    Dracmas(const Dracmas&) = delete;
    void operator=(const Dracmas&) = delete;

    // Interface pública
    static Dracmas* getInstance();
    static int getQuantidade();
    static void adicionar(int valor);
    static void subtrair(int valor);
    static void resetar();
    static void salvarEmArquivo(const std::string& arquivo);
    static void carregarDeArquivo(const std::string& arquivo);
};

#endif