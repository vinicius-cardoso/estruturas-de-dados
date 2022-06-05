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
    int valor_mao;
    Carta mao[NUMERO_DE_CARTAS];

   public:
    Jogador();
    Jogador(string nome, int dinheiro, int valor_aposta);

    void SetNome(string nome);
    string GetNome();
    void SetDinheiro(int dinheiro);
    int GetDinheiro();
    bool SetAposta(int aposta);
    void SetValorMao(string valor_mao);
    int GetValorMao();
    string *GetMao();
    void AdicionarCarta(string _carta);
    void ImprimirMao();
    void LimparMao();
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

void Jogador::SetNome(string nome) {
    this->nome = nome;
}

string Jogador::GetNome() {
    return this->nome;
}

void Jogador::SetDinheiro(int dinheiro) {
    this->dinheiro = dinheiro;
}

int Jogador::GetDinheiro() {
    return this->dinheiro;
}

bool Jogador::SetAposta(int aposta) {
    this->valor_aposta = aposta;
    this->dinheiro -= this->valor_aposta;

    bool condicao;
    condicao = this->dinheiro < 0 ? false : true;

    return condicao;
}

void Jogador::SetValorMao(string valor_mao) {
    if (valor_mao == "HC")
        this->valor_mao = 1;
    else if (valor_mao == "OP")
        this->valor_mao = 2;
    else if (valor_mao == "TP")
        this->valor_mao = 3;
    else if (valor_mao == "TK")
        this->valor_mao = 4;
    else if (valor_mao == "S")
        this->valor_mao = 5;
    else if (valor_mao == "F")
        this->valor_mao = 6;
    else if (valor_mao == "FH")
        this->valor_mao = 7;
    else if (valor_mao == "FK")
        this->valor_mao = 8;
    else if (valor_mao == "SF")
        this->valor_mao = 9;
    else if (valor_mao == "RSF")
        this->valor_mao = 10;
}

int Jogador::GetValorMao() {
    return this->valor_mao;
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

string *Jogador::GetMao() {
    int repeticoes_valor = 0, repeticoes_naipe = 0;
    string *detalhes_mao = new string[3];
    string mao_avaliada = "";
    string maior_carta_avaliada = "";
    bool trinca = false;

    // o for eh invertido porque deseja-se obter a mao com as cartas mais valiosas
    for (int i = NUMERO_DE_CARTAS; i > 0; i--) {
        if (mao[i].GetValor() == mao[i - 1].GetValor()) {
            repeticoes_valor++;

            if (repeticoes_valor == 2) {
                if (mao[i - 1].GetValor() == mao[i + 1].GetValor()) {
                    repeticoes_valor++;
                    trinca = true;
                }
            }
        }

        if (mao[i].GetNaipe() == mao[i - 1].GetNaipe()) {
            repeticoes_naipe++;
        }
    }

    if (repeticoes_valor == 1 || ((repeticoes_valor == 2) && trinca == false)) {
        for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
            if (mao[i].GetValor() == mao[i + 1].GetValor()) {
                maior_carta_avaliada = mao[i + 1].GetCarta();
            }
        }
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
            maior_carta_avaliada = mao[2].GetCarta();
            break;
        case 4:
            mao_avaliada = "FK";  // Four of a Kind
            maior_carta_avaliada = mao[1].GetCarta();
            break;
    }

    // verificar se eh um Straight e se pode ser um Straight Flush
    if (repeticoes_valor == 0) {
        if ((mao[NUMERO_DE_CARTAS - 1].GetValor() - mao[0].GetValor()) == 4) {
            mao_avaliada = "S";
            maior_carta_avaliada = mao[NUMERO_DE_CARTAS - 1].GetCarta();
        }
        if ((mao[NUMERO_DE_CARTAS - 1].GetValor() - mao[1].GetValor()) == 3) {
            if (mao[NUMERO_DE_CARTAS - 1].GetValor() == 13 && mao[0].GetValor() == 1)
                mao_avaliada = "RS";  // Royal Straight eh auxiliar e temporario
        }
    }

    // verificar se eh um Flush ou Straight Flush
    if (repeticoes_naipe == 4) {
        if (mao_avaliada == "S") {
            mao_avaliada = "SF";  // Straight Flush

            if (mao[NUMERO_DE_CARTAS - 1].GetValor() == 13 && mao[0].GetValor() == 1)
                maior_carta_avaliada = mao[0].GetCarta();  // As
            else
                maior_carta_avaliada = mao[NUMERO_DE_CARTAS - 1].GetCarta();

        } else if (mao_avaliada == "RS") {
            mao_avaliada = "RSF";                      // Royal Straight Flush
            maior_carta_avaliada = mao[0].GetCarta();  // As
        } else {
            mao_avaliada = "F";  // Flush

            if (mao[NUMERO_DE_CARTAS - 1].GetValor() == 13 && mao[0].GetValor() == 1)
                maior_carta_avaliada = mao[0].GetCarta();  // As
            else
                maior_carta_avaliada = mao[NUMERO_DE_CARTAS - 1].GetCarta();
        }
    }

    // em uma quadra eh impossivel o segundo e o ultimo elemento serem diferentes
    // logo, se ha 4 repeticoes de valor, ha um full house
    if (repeticoes_valor == 4 && (mao[1].GetValor() != mao[3].GetValor())) {
        mao_avaliada = "FH";  // Full House
        maior_carta_avaliada = mao[2].GetCarta();
    }

    string maior_carta_mao = mao[NUMERO_DE_CARTAS - 1].GetCarta();

    if (mao_avaliada == "RS")
        mao_avaliada = "S";
    if (mao_avaliada == "") {
        mao_avaliada = "HC";
        maior_carta_avaliada = maior_carta_mao;
    }

    detalhes_mao[0] = mao_avaliada;
    detalhes_mao[1] = maior_carta_avaliada;
    detalhes_mao[2] = maior_carta_mao;

    return detalhes_mao;
}

void Jogador::LimparMao() {
    for (int i = 0; i < NUMERO_DE_CARTAS; i++)
        mao[i].SetCarta("0Z");
}

#endif