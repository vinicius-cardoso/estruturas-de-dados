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

    string GetNome();
    void AdicionarCarta(string carta);
    Lista<Carta> GetMao();
    void Imprimir();
};

Jogador::Jogador() {
    this->nome = "NOME";
    this->dinheiro = 0;
}

Jogador::Jogador(string nome, int dinheiro, int valor_aposta) {
    this->nome = nome;
    this->dinheiro = dinheiro;
    this->valor_aposta = valor_aposta;
}

string Jogador::GetNome() {
    return this->nome;
}

void Jogador::AdicionarCarta(string carta) {
    Carta *carta_obj = new Carta(carta);

    mao.Inserir(Carta(*carta_obj));

    if (mao.GetTamanho() == 5) {
        Lista<Carta> *aux = new Lista<Carta>;

        for (int i = 0; i < 4; i++) {
            if (mao.GetItem(i) < mao.GetItem(i + 1)) {
                aux->SetItem(*mao.GetItem(i), i);      // aux = mao[i]
                mao.SetItem(*mao.GetItem(i + 1), i);   // mao[i] = mao[i + 1]
                mao.SetItem(*aux->GetItem(i), i + 1);  // mao[i + 1] = aux
            }
        }
    }
}

Lista<Carta> Jogador::GetMao() {
    return mao;
}

void Jogador::Imprimir() {
    for (int i = 0; i < 5; i++)
        cout << mao.GetItem(i)->GetCarta() << endl;
}

#endif