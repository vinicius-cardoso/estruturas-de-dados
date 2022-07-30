#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

using namespace std;

class No {
   private:
    int item;
    No *proximo;

   public:
    No(int item);

    friend class ListaEncadeada;
};

class ListaEncadeada {
   private:
    No *primeiro;
    No *ultimo;
    int tamanho;

   public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool IsVazia();
    int GetTamanho();
    void InserirInicio(int item);
    void InserirFinal(int item);
    void InserirPosicao(int item, int pos);
    int RemoverInicio();
    int RemoverFinal();
    int RemoverPosicao(int pos);
    int Pesquisar(int chave);
    void Imprimir();
    void Limpar();
};

#endif