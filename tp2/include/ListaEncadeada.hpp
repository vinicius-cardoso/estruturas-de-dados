#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

#include "Palavra.hpp"

using namespace std;

class ListaEncadeada {
   private:
    int tamanho;
    Palavra *primeiro;
    Palavra *ultimo;
    Palavra *ponteiro;

   public:
    ListaEncadeada();
    ~ListaEncadeada();

    int GetTamanho();
    void InsereFinal(Palavra *palavra);
    void RemovePosicao(int pos);
    int Pesquisa(string palavra);
    void Limpa();
};

#endif