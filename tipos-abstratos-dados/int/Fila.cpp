#include "Fila.hpp"

No::No(int item) {
    this->item = item;
    this->proximo = nullptr;
}

Fila::Fila() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

Fila::~Fila() {
    Limpar();

    delete primeiro;
}

void Fila::Enfileirar(int item) {
    No *novo = new No(item);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }

    tamanho++;
}

int Fila::Desenfileirar() {
    if (primeiro == nullptr)
        throw "Erro: Fila vazia";

    No *aux = primeiro;
    int desenfileirado = aux->item;

    primeiro = primeiro->proximo;

    if (primeiro->proximo == nullptr)
        ultimo = primeiro;

    delete aux;
    tamanho--;

    return desenfileirado;
}

void Fila::Imprimir() {
    No *atual = primeiro;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

void Fila::Limpar() {
    No *atual = primeiro;

    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}