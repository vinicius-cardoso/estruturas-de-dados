#include "ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada() {
    this->tamanho = 0;

    primeiro = new Palavra();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada() {
    Limpa();

    delete primeiro;
}

void ListaEncadeada::InsereFinal(Palavra *palavra) {
    Palavra *nova = new Palavra();
    nova = palavra;
    ponteiro = primeiro;

    while (ponteiro->proximo) {
        ponteiro = ponteiro->proximo;
    }

    ponteiro->proximo = nova;
    nova->proximo = nullptr;

    tamanho++;
}

void ListaEncadeada::RemovePosicao(int pos) {
    if (pos < 0 || pos > this->tamanho)
        throw "Posicao invalida";

    Palavra *atual = primeiro;

    for (int i = 0; i < pos - 1; i++)
        atual = atual->proximo;

    Palavra *aux = atual->proximo;
    atual->proximo = aux->proximo;

    delete aux;

    tamanho--;
}

int ListaEncadeada::Pesquisa(string palavra) {
    ponteiro = primeiro;
    int local = 0;

    while (ponteiro) {
        if (ponteiro->palavra == palavra) {
            return local;
        }

        local++;
        ponteiro = ponteiro->proximo;
    }

    return -1;
}

void ListaEncadeada::Limpa() {
    Palavra *p;
    p = primeiro->proximo;

    while (p != nullptr) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
};