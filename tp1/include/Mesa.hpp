#ifndef MESA_H
#define MESA_H

#include <fstream>
#include <iostream>
#include <string>

#include "Jogador.hpp"

using namespace std;

class Mesa {
   private:
    int numero_de_rodadas;
    int dinheiro_inicial;
    int numero_de_jogadores;
    int valor_do_pingo;
    int valor_aposta;
    int pote;
    string nome_jogador;
    string jogada;
    string carta;
    string valor_mao;
    string nome_vencedor;
    string jogada_vencedor;
    bool invalida;
    Jogador *jogadores;
    Jogador vencedor;
    Jogador *vencedores;

   public:
    Mesa();

    void Partida(string nome_arquivo_entrada);
    int GetNrVencedores(Jogador *jogadores, int numero_jogadores);
    int GetVencedor(Jogador *jogadores, int numero_jogadores);
    int *GetVencedores(Jogador *jogadores, int numero_jogadores);
};

#endif