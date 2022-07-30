#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

using namespace std;

template <class T>
class ListaEncadeada;

template <class T>
class No {
   private:
    T item;
    No<T> *proximo;

   public:
    No(T item);

    friend class ListaEncadeada<T>;
};

template <typename T>
class ListaEncadeada {
   private:
    int tamanho;
    No<T> *primeiro;
    No<T> *ultimo;

   public:
    ListaEncadeada();
    ~ListaEncadeada();

    bool IsVazia();
    int GetTamanho();
    void InserirInicio(T item);
    void InserirFinal(T item);
    void InserirPosicao(T item, int pos);
    T RemoverInicio();
    T RemoverFinal();
    T RemoverPosicao(int pos);
    int Pesquisar(T chave);
    void Imprimir();
    void Limpar();
};

#endif