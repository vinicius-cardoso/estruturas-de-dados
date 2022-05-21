#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

template <class T>
class Fila;

template <class T>
class No {
   private:
    T conteudo;
    No<T> *proximo;

   public:
    No();
    No(T item);
    void SetItem(T item);
    T GetItem();
    // void SetProximo(No<T> *proximo);
    // No<T> *GetProximo();

    friend class Fila<T>;
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
void No<T>::SetItem(T item) {
    conteudo = item;
}

template <class T>
T No<T>::GetItem() {
    return conteudo;
}

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
    void Imprime();
    void Limpa();
};

template <class T>
Fila<T>::Fila() {
    primeiro = new No<T>();
    ultimo = primeiro;
    tamanho = 0;
}

template <class T>
Fila<T>::~Fila() {
    Limpa();
    delete primeiro;
}

template <class T>
bool Fila<T>::IsVazia() {
    return tamanho == 0;
}

template <class T>
int Fila<T>::GetTamanho() {
    return tamanho;
}

template <class T>
void Fila<T>::Enfileirar(T item) {
    No<T> *nova = new No<T>();

    nova->conteudo = item;
    ultimo->proximo = nova;
    ultimo = nova;

    tamanho++;
}

template <class T>
T Fila<T>::Desenfileirar() {
    T aux;
    No<T> *p;

    if (tamanho == 0) {
        throw "Erro: Pilha vazia";
    }

    aux = primeiro->proximo->conteudo;
    p = primeiro;
    primeiro = primeiro->proximo;

    delete p;

    tamanho--;

    return aux;
}

template <class T>
void Fila<T>::Imprime() {
    No<T> *p = primeiro;

    p = primeiro->proximo;

    while (p != nullptr) {
        cout << p->conteudo << " ";
        p = p->proximo;
    }

    cout << endl;
}

template <class T>
void Fila<T>::Limpa() {
    No<T> *p;
    p = primeiro->proximo;

    while (p != nullptr) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;

    tamanho = 0;
}

#endif