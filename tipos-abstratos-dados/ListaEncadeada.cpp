#include "ListaEncadeada.hpp"

template <class T>
No<T>::No(T item) {
    this->item = item;
    this->proximo = nullptr;
}

template <class T>
ListaEncadeada<T>::ListaEncadeada() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

template <class T>
ListaEncadeada<T>::~ListaEncadeada() {
    Limpar();

    delete primeiro;
}

template <class T>
bool ListaEncadeada<T>::IsVazia() {
    return primeiro == nullptr;
}

template <class T>
int ListaEncadeada<T>::GetTamanho() {
    return tamanho;
}

template <class T>
void ListaEncadeada<T>::InserirInicio(T item) {
    No<T> *novo = new No<T>(item);

    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = primeiro;
    } else {
        novo->proximo = primeiro;
        primeiro = novo;
    }

    tamanho++;
}

template <class T>
void ListaEncadeada<T>::InserirFinal(T item) {
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
void ListaEncadeada<T>::InserirPosicao(T item, int pos) {
    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    No<T> *novo = new No<T>(item);
    No<T> *atual = primeiro;

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

template <class T>
T ListaEncadeada<T>::RemoverInicio() {
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
T ListaEncadeada<T>::RemoverFinal() {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    int aux = ultimo->item;

    if (primeiro->proximo == nullptr)
        primeiro = nullptr;
    else {
        No<T> *atual = primeiro;
        while (atual->proximo->proximo != nullptr)
            atual = atual->proximo;

        No<T> *ult = atual->proximo;
        atual->proximo = nullptr;
        ultimo = atual;

        delete ult;
    }

    if (tamanho == 1)
        ultimo = primeiro;

    tamanho--;
    return aux;
}

template <class T>
T ListaEncadeada<T>::RemoverPosicao(int pos) {
    if (tamanho == 0)
        throw "Erro: Lista vazia";

    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    int aux;
    No<T> *atual = primeiro;

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
            No<T> *temp;

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

template <class T>
int ListaEncadeada<T>::Pesquisar(T chave) {
    No<T> *atual = primeiro;

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

template <class T>
void ListaEncadeada<T>::Imprimir() {
    No<T> *atual = primeiro;

    while (atual != nullptr) {
        cout << atual->item << " ";

        atual = atual->proximo;
    }

    cout << endl;
}

template <class T>
void ListaEncadeada<T>::Limpar() {
    No<T> *atual = primeiro;

    while (atual->proximo != nullptr) {
        primeiro = atual->proximo;
        delete atual;
        atual = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}