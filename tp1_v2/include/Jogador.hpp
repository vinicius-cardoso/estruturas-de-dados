#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>

#include "Carta.hpp"

#define NUMERO_DE_CARTAS 5

using namespace std;

class Jogador {
   private:
    string nome;
    int dinheiro;
    int valor_aposta;
    Carta mao[NUMERO_DE_CARTAS];

   public:
    Jogador();
    Jogador(string nome, int dinheiro, int valor_aposta);

    string GetNome();
    int GetDinheiro();
    void SetAposta(int aposta);
    void AdicionarCarta(string _carta);
    void ImprimirMao();
};

Jogador::Jogador() {
    this->nome = "";
    this->dinheiro = 0;
    this->valor_aposta = 0;
}

Jogador::Jogador(string nome, int dinheiro, int valor_aposta) {
    this->nome = nome;
    this->dinheiro = dinheiro;
    this->valor_aposta = valor_aposta;
}

string Jogador::GetNome() {
    return this->nome;
}

int Jogador::GetDinheiro() {
    return this->dinheiro;
}

void Jogador::SetAposta(int aposta) {
    this->valor_aposta = aposta;
}

void Jogador::AdicionarCarta(string _carta) {
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        if (mao[i].GetCarta() == "VAZIO") {
            mao[i].SetCarta(_carta);

            if (mao[NUMERO_DE_CARTAS - 1].GetCarta() != "VAZIO") {
                for (int j = 0; j < NUMERO_DE_CARTAS - 1; j++) {
                    for (int k = 0; k < NUMERO_DE_CARTAS - j - 1; k++) {
                        if (mao[k].GetValor() > mao[k + 1].GetValor()) {
                            Carta aux;
                            aux.SetCarta(mao[k].GetCarta());
                            mao[k].SetCarta(mao[k + 1].GetCarta());
                            mao[k + 1].SetCarta(aux.GetCarta());
                        }
                    }
                }
            }

            return;
        }
    }
}

void Jogador::ImprimirMao() {
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        cout << mao[i].GetCarta() << " ";
    }

    cout << endl;
}

#endif