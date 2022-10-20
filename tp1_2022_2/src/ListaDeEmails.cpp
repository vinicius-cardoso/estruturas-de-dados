#include "ListaDeEmails.hpp"

ListaDeEmails::ListaDeEmails() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

ListaDeEmails::~ListaDeEmails() {
    Limpar();

    delete primeiro;
}

bool ListaDeEmails::IsVazia() {
    return primeiro == nullptr;
}

void ListaDeEmails::InserirEmailOrdenado(Email *email) {
    Email *novo = new Email(email->GetPrioridade(), email->GetMensagem());
    Email *atual = primeiro;

    // verifica se a lista esta vazia
    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        // verifica se a prioridade do email a inserir eh maior que a do primeiro da lista
        if (email->GetPrioridade() > primeiro->GetPrioridade()) {
            novo->proximo = primeiro;
            primeiro = novo;
            // verifica se a prioridade do email a inserir eh menor que a do ultimo da lista
        } else if (email->GetPrioridade() <= ultimo->GetPrioridade()) {
            ultimo->proximo = novo;
            ultimo = novo;
            // percorre a lista de emails buscando um indice adequado para a lista ser ordenada
        } else {
            while (atual->proximo && email->GetPrioridade() <= atual->proximo->GetPrioridade())
                atual = atual->proximo;

            novo->proximo = atual->proximo;
            atual->proximo = novo;
        }
    }

    tamanho++;
}

string ListaDeEmails::RemoverEmailInicio() {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    Email *atual = primeiro;
    string aux = atual->GetMensagem();

    primeiro = primeiro->proximo;

    tamanho--;

    if (tamanho == 1)
        ultimo = primeiro;

    return aux;
}

void ListaDeEmails::Limpar() {
    Email *atual = primeiro;

    // enqunato os objetos da lista nao forem nulos, deleta cada um deles
    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}
