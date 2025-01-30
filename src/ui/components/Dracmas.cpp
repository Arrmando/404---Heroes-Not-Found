#include "./include/Dracmas.hpp"
#include <fstream>
#include <iostream>

// Definição da instância (APENAS AQUI)
Dracmas* Dracmas::instance = nullptr;

// Implementação dos métodos
Dracmas* Dracmas::getInstance() {
    if (!instance) {
        instance = new Dracmas();
    }
    return instance;
}

int Dracmas::getQuantidade() {
    return getInstance()->quantidade;
}

void Dracmas::adicionar(int valor) {
    getInstance()->quantidade += valor;
}

void Dracmas::subtrair(int valor) {
    if (getInstance()->quantidade >= valor) {
        getInstance()->quantidade -= valor;
    }
}

void Dracmas::resetar() {
    getInstance()->quantidade = 10;
}

void Dracmas::salvarEmArquivo(const std::string& arquivo) {
    std::ofstream file(arquivo, std::ios::binary);
    if (file.is_open()) {
        int saldoAtual = getQuantidade();
        file.write(reinterpret_cast<const char*>(&saldoAtual), sizeof(saldoAtual));
        file.close();
    } else {
        std::cerr << "Erro ao salvar dracmas no arquivo!" << std::endl;
    }
}

void Dracmas::carregarDeArquivo(const std::string& arquivo) {
    std::ifstream file(arquivo, std::ios::binary);
    if (file.is_open()) {
        int salvo;
        file.read(reinterpret_cast<char*>(&salvo), sizeof(salvo)); // Corrigido para 'salvo'
        getInstance()->quantidade = salvo;
        file.close();
    } else {
        std::cerr << "Arquivo de save não encontrado. Usando valor padrão." << std::endl;
        resetar();
    }
}