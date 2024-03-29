#include "Fila.hpp"

template <class T>
No<T>::No(T item) {
    this->item = item;
    this->proximo = nullptr;
}

template <class T>
Fila<T>::Fila() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

template <class T>
Fila<T>::~Fila() {
    Limpar();

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
    No<T> *novo = new No<T>(item);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }

    tamanho++;
}

template <class T>
T Fila<T>::Desenfileirar() {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    int aux = primeiro->item;
    No<T> *atual = primeiro;

    primeiro = primeiro->proximo;

    tamanho--;

    if (tamanho == 1)
        ultimo = primeiro;

    delete atual;

    return aux;
}

template <class T>
void Fila<T>::Imprimir() {
    No<T> *atual = primeiro;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

template <class T>
void Fila<T>::Limpar() {
    No<T> *atual = primeiro;

    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}