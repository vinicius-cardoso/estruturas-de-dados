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
    string GetMao();
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

string Jogador::GetMao() {
    int repeticoes_valor = 0, repeticoes_naipe = 0;
    string mao_avaliada = "";

    // o for eh invertido porque deseja-se obter a mao com as cartas mais valiosas
    for (int i = NUMERO_DE_CARTAS; i > 0; i--) {
        if (mao[i].GetValor() == mao[i - 1].GetValor()) {
            repeticoes_valor++;

            if (repeticoes_valor == 2) {
                if (mao[i - 1].GetValor() == mao[i + 1].GetValor())
                    repeticoes_valor++;
            }
        }

        if (mao[i].GetNaipe() == mao[i - 1].GetNaipe()) {
            repeticoes_naipe++;
        }
    }

    // verificar se eh um Straight e se pode ser um Straight Flush
    if (repeticoes_valor == 0) {
        if ((mao[NUMERO_DE_CARTAS - 1].GetValor() - mao[0].GetValor()) == 4)
            mao_avaliada = "S";
        if ((mao[NUMERO_DE_CARTAS - 1].GetValor() - mao[1].GetValor()) == 3) {
            if (mao[NUMERO_DE_CARTAS - 1].GetValor() == 13 && mao[0].GetValor() == 1)
                mao_avaliada = "RS";  // Royal Straight eh auxiliar e temporario
        }
    }

    // verificar se eh um Flush ou Straight Flush
    if (repeticoes_naipe == 4) {
        if (mao_avaliada == "S")
            mao_avaliada = "SF";  // Straight Flush
        else if (mao_avaliada == "RS")
            mao_avaliada = "RSF";  // Royal Straight Flush
        else
            mao_avaliada = "F";  // Flush
    }

    switch (repeticoes_valor) {
        case 1:
            mao_avaliada = "OP";  // One Pair
            break;
        case 2:
            mao_avaliada = "TP";  // Two Pairs
            break;
        case 3:
            mao_avaliada = "TK";  // Three of a Kind
            break;
        case 4:
            mao_avaliada = "FK";  // Four of a Kind
            break;
    }

    // em uma quadra eh impossivel o segundo e o ultimo elemento serem diferentes
    // logo, se ha 4 repeticoes de valor, ha um full house
    if (repeticoes_valor == 4 && (mao[1].GetValor() != mao[3].GetValor()))
        mao_avaliada = "FH";  // Full House

    if (mao_avaliada == "RS")
        mao_avaliada = "S";
    if (mao_avaliada == "")
        mao_avaliada = "HC";

    return mao_avaliada;
}

#endif