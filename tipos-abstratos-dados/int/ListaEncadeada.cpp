#include "ListaEncadeada.hpp"

No::No(int item) {
    this->item = item;
    this->proximo = nullptr;
}

ListaEncadeada::ListaEncadeada() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

ListaEncadeada::~ListaEncadeada() {
    Limpar();

    delete primeiro;
}

bool ListaEncadeada::IsVazia() {
    return primeiro == nullptr;
}

int ListaEncadeada::GetTamanho() {
    return tamanho;
}

void ListaEncadeada::InserirInicio(int item) {
    No *novo = new No(item);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        novo->proximo = primeiro;
        primeiro = novo;
    }

    tamanho++;
}

void ListaEncadeada::InserirFinal(int item) {
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

void ListaEncadeada::InserirPosicao(int item, int pos) {
    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    No *novo = new No(item);
    No *atual = primeiro;

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        if (pos == 0) {
            novo->proximo = primeiro;
            primeiro = novo;
        } else if (pos == tamanho) {
            ultimo->proximo = novo;
            ultimo = novo;
        } else {
            if (pos == 1) {
                novo->proximo = primeiro->proximo;
                primeiro->proximo = novo;
            } else {
                for (int i = 0; i < pos - 1; i++) {
                    atual = atual->proximo;
                }

                novo->proximo = atual->proximo;
                atual->proximo = novo;
            }
        }
    }

    tamanho++;
}

int ListaEncadeada::RemoverInicio() {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    int aux = primeiro->item;
    No *atual = primeiro;

    primeiro = primeiro->proximo;

    tamanho--;

    if (tamanho == 1)
        ultimo = primeiro;

    delete atual;

    return aux;
}

int ListaEncadeada::RemoverFinal() {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    int aux = ultimo->item;

    if (primeiro->proximo == nullptr)
        primeiro = nullptr;
    else {
        No *atual = primeiro;

        while (atual->proximo->proximo != nullptr)
            atual = atual->proximo;

        No *ult = atual->proximo;
        atual->proximo = nullptr;
        ultimo = atual;

        delete ult;
    }

    if (tamanho == 1)
        ultimo = primeiro;

    tamanho--;
    return aux;
}

int ListaEncadeada::RemoverPosicao(int pos) {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    int aux;
    No *atual = primeiro;

    if (atual->proximo == nullptr) {
        aux = atual->item;

        primeiro = nullptr;

        delete atual;
    } else {
        if (pos == 0) {
            if (tamanho == 1)
                atual = nullptr;
            else {
                primeiro = atual->proximo;

                aux = atual->item;

                delete atual;
            }
        } else {
            No *temp;

            for (int i = 0; i < pos - 1; i++)
                atual = atual->proximo;

            temp = atual->proximo;
            atual->proximo = temp->proximo;

            aux = temp->item;

            delete temp;
        }
    }

    if (tamanho == 1)
        ultimo = primeiro;

    tamanho--;
    return aux;
}

int ListaEncadeada::Pesquisar(int chave) {
    No *atual = primeiro;

    int posicao = 0;

    while (atual != nullptr) {
        if (atual->item == chave) {
            return posicao;
        }

        atual = atual->proximo;
        posicao++;
    }

    return -1;
}

void ListaEncadeada::Imprimir() {
    No *atual = primeiro;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

void ListaEncadeada::Limpar() {
    No *atual = primeiro;

    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}