#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

template <class T>
class Pilha;

template <class T>
class No {
   private:
    T conteudo;
    No<T> *proximo;

   public:
    No();
    No(T item);

    friend class Pilha<T>;
};

template <class T>
No<T>::No() {
    conteudo = -1;
    No<T> *proximo = nullptr;
}

template <class T>
No<T>::No(T item) {
    conteudo = item;
    proximo = nullptr;
}

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
    void Desempilhar();
    void Imprime();
    void Limpa();
};

template <class T>
Pilha<T>::Pilha() {
    topo = new No<T>();
    tamanho = 0;
}

template <class T>
Pilha<T>::~Pilha() {
    Limpa();
    delete topo;
}

template <class T>
bool Pilha<T>::IsVazia() {
    return topo == nullptr;
}

template <class T>
int Pilha<T>::GetTamanho() {
    return tamanho;
}

template <class T>
void Pilha<T>::Empilhar(T item) {
    No<T> *nova = new No<T>();

    nova->conteudo = item;
    nova->proximo = topo;
    topo = nova;

    tamanho++;
}

template <class T>
void Pilha<T>::Desempilhar() {
    if (tamanho == 0)
        throw "Erro: Pilha vazia!";

    No<T> *aux = topo;
    topo = topo->proximo;

    delete aux;

    tamanho--;
}

template <class T>
void Pilha<T>::Imprime() {
    No<T> *p = topo;

    while (p != nullptr) {
        if (p->proximo)
            cout << p->conteudo << " ";

        p = p->proximo;
    }

    cout << endl;
}

template <class T>
void Pilha<T>::Limpa() {
    No<T> *p;
    p = topo->proximo;

    while (p != nullptr) {
        topo->proximo = p->proximo;
        delete p;
        p = topo->proximo;
    }

    tamanho = 0;
}

#endif