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
    void Premiar(int premio);
    void AdicionarCarta(string _carta);
    void ImprimirMao();
    void LimparMao();
};

#endif