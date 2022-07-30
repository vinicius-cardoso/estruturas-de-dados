#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

class No {
   private:
    int item;
    No *proximo;

   public:
    No(int item);

    friend class Fila;
};

class Fila {
   private:
    No *primeiro;
    No *ultimo;
    int tamanho;

   public:
    Fila();
    ~Fila();

    void Enfileirar(int item);
    int Desenfileirar();
    void Imprimir();
    void Limpar();
};

#endif