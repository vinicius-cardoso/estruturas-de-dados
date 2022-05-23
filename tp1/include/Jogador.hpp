#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

#include "Carta.hpp"
#include "Lista.hpp"

using namespace std;

class Jogador {
   private:
    string nome;
    int dinheiro;
    int valor_aposta;
    Lista<Carta> mao;

   public:
    Jogador();
    Jogador(string nome, int dinheiro, int valor_aposta);

    void AdicionarCarta(string carta);
    Lista<Carta> GetMao();
};

Jogador::Jogador() {
    this->nome = "";
    this->dinheiro = 0;
}

Jogador::Jogador(string nome, int dinheiro, int valor_aposta) {
    this->nome = nome;
    this->dinheiro = dinheiro;
    this->valor_aposta = valor_aposta;
}

void Jogador::AdicionarCarta(string carta) {
    mao.Inserir(Carta(carta));
}

Lista<Carta> Jogador::GetMao() {
    return mao;
}

#endif