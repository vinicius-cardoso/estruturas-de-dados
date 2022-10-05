#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

class No {
   private:
    int item;
    No *proximo;

   public:
    No(int item);

    friend class Pilha;
};

class Pilha {
   private:
    No *topo;
    int tamanho;

   public:
    Pilha();
    ~Pilha();

    bool IsVazia();
    void Empilhar(int item);
    int Desempilhar();
    void Imprimir();
    void Limpar();
};

#endif