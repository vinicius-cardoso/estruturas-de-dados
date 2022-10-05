#include "Pilha.hpp"

template <class T>
No<T>::No(T item) {
    this->item = item;
    this->proximo = nullptr;
}

template <class T>
Pilha<T>::Pilha() {
    topo = nullptr;
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
    No<T> *novo = new No<T>(item);

    if (topo == nullptr) {
        topo = novo;
    } else {
        novo->proximo = topo;
        topo = novo;
    }

    tamanho++;
}

template <class T>
T Pilha<T>::Desempilhar() {
    if (topo == nullptr)
        throw "Erro: Pilha vazia!";

    No<T> *aux = topo;
    T desempilhado = aux->item;

    topo = topo->proximo;

    delete aux;
    tamanho--;

    return desempilhado;
}

template <class T>
void Pilha<T>::Imprimir() {
    No<T> *atual = topo;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

template <class T>
void Pilha<T>::Limpa() {
    while (!IsVazia())
        Desempilhar();
}