#include "Pilha.hpp"

No::No(int item) {
    this->item = item;
    this->proximo = nullptr;
}

Pilha::Pilha() {
    topo = nullptr;
    tamanho = 0;
}

Pilha::~Pilha() {
    Limpar();

    delete topo;
}

void Pilha::Empilhar(int item) {
    No *novo = new No(item);

    if (topo == nullptr) {
        topo = novo;
    } else {
        novo->proximo = topo;
        topo = novo;
    }

    tamanho++;
}

int Pilha::Desempilhar() {
    if (topo == nullptr)
        throw "Erro: Pilha vazia";

    No *aux = topo;
    int desempilhado = aux->item;

    topo = topo->proximo;

    delete aux;
    tamanho--;

    return desempilhado;
}

void Pilha::Imprimir() {
    No *atual = topo;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

void Pilha::Limpar() {
    No *atual = topo;

    while (atual->proximo != nullptr) {
        topo = atual->proximo;
        delete atual;
        atual = topo->proximo;
    }

    tamanho = 0;
}