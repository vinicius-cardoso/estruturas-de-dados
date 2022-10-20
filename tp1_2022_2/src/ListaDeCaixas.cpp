#include "ListaDeCaixas.hpp"

ListaDeCaixas::ListaDeCaixas() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

ListaDeCaixas::~ListaDeCaixas() {
    Limpar();

    delete primeiro;
}

CaixaDeEntrada *ListaDeCaixas::GetCaixa(int id) {
    CaixaDeEntrada *atual = primeiro;

    // se a caixa com o id for a primeira caixa da lista
    if (atual->GetId() == id)
        return atual;

    while (atual->proximo && atual->proximo->GetId() != id) {
        atual = atual->proximo;
    }

    // se a proxima caixa nao for nula, retorna ela, caso nao, retorna a atual
    if (atual->proximo != nullptr)
        return atual->proximo;

    return atual;
}

bool ListaDeCaixas::IsVazia() {
    return primeiro == nullptr;
}

// insere uma nova caixa no final da lista
void ListaDeCaixas::InserirCaixa(CaixaDeEntrada *caixa_de_entrada) {
    CaixaDeEntrada *novo = new CaixaDeEntrada(*caixa_de_entrada);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        ultimo->proximo = novo;
        ultimo = novo;
    }

    tamanho++;
}

// procura pela caixa com o id fornecido e a deleta da lista
void ListaDeCaixas::RemoverCaixa(int id) {
    CaixaDeEntrada *atual = primeiro;
    CaixaDeEntrada *aux = nullptr;

    // caso seja o primeiro elemento da lista
    if (atual != nullptr && primeiro->GetId() == id) {
        aux = primeiro;
        primeiro = aux->proximo;

        if (primeiro == nullptr)
            ultimo = nullptr;
    } else {
        // percorre cada elemento da lista buscando o id fornecido
        while (atual != nullptr && atual->proximo != nullptr && atual->proximo->GetId() != id) {
            atual = atual->proximo;
        }

        if (atual != nullptr && atual->proximo != nullptr) {
            aux = atual->proximo;
            atual->proximo = aux->proximo;

            // caso o ultimo elemento seja removido
            if (atual->proximo == nullptr)
                ultimo = atual;
        }
    }

    if (aux) {
        // libera a memoria alocada para o objeto aux
        free(aux);
    }

    tamanho--;
}

bool ListaDeCaixas::PesquisarCaixa(int id) {
    CaixaDeEntrada *atual = primeiro;

    int posicao = 0;

    // percorre a lista de caixas buscando pelo id
    while (posicao < tamanho) {
        if (atual->GetId() == id)
            return true;

        atual = atual->proximo;

        posicao++;
    }

    return false;
}

void ListaDeCaixas::Limpar() {
    CaixaDeEntrada *atual = primeiro;

    // enqunato os objetos da lista nao forem nulos, deleta cada um deles
    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}
