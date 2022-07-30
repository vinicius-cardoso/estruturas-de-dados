#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

template <class T>
class Pilha;

template <class T>
class No {
   private:
    T item;
    No<T> *proximo;

   public:
    No(T item);

    friend class Pilha<T>;
};

template <class T>
class Pilha {
   private:
    int tamanho;
    No<T> *topo;

   public:
    Pilha();
    ~Pilha();

    bool IsVazia();
    int GetTamanho();
    void Empilhar(T item);
    T Desempilhar();
    void Imprimir();
    void Limpa();
};

#endif