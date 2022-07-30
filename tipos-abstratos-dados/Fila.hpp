#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

template <class T>
class Fila;

template <class T>
class No {
   private:
    T item;
    No<T> *proximo;

   public:
    No(T item);

    friend class Fila<T>;
};

template <class T>
class Fila {
   private:
    int tamanho;
    No<T> *primeiro;
    No<T> *ultimo;

   public:
    Fila();
    ~Fila();

    bool IsVazia();
    int GetTamanho();
    void Enfileirar(T item);
    T Desenfileirar();
    void Imprimir();
    void Limpar();
};

#endif