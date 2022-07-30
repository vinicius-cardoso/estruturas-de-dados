#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <iostream>

#define PRE_ORDEM 1
#define IN_ORDEM 2
#define POS_ORDEM 3

using namespace std;

template <class T>
class ArvoreBinaria;

template <class T>
class No {
   private:
    T item;
    No<T> *esquerda;
    No<T> *direita;

   public:
    No(T item);

    friend class ArvoreBinaria<T>;
};

template <class T>
class ArvoreBinaria {
   private:
    No<T> *raiz;
    int tamanho;

    void InserirRecursivo(No<T> *&p, T item);
    bool ApagarRecursivo(No<T> *&p, T chave);
    T PesquisarRecursivo(No<T> *&p, T chave);
    void RemoverRecursivo(No<T> *p);
    void PreOrdem(No<T> *p);
    void InOrdem(No<T> *p);
    void PosOrdem(No<T> *p);

   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    bool IsVazia();
    void Inserir(T item);
    bool Apagar(T chave);
    T Pesquisar(T chave);
    void Caminhar(int tipo);
    void Limpar();
};

#endif