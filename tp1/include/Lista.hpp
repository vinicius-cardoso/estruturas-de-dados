#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

template <typename T>
class Lista;

template <typename T>
class No;

template <typename T>
class No {
   private:
    T conteudo;
    No<T> *anterior;
    No<T> *proximo;

   public:
    No();
    No(T *conteudo, No<T> *anterior, No<T> *proximo);

    void InserirProximo(No<T> *proximo);
    void InserirAnterior(No<T> *anterior);
    No<T> *GetProximo();
    No<T> *GetAnterior();
    T GetConteudo();

    friend class Lista<T>;
};

template <typename T>
No<T>::No() {
    this->anterior = nullptr;
    this->proximo = nullptr;
}

template <typename T>
No<T>::No(T *conteudo, No<T> *anterior, No<T> *proximo) {
    this->anterior = nullptr;
    this->proximo = nullptr;
}

template <typename T>
void No<T>::InserirProximo(No<T> *proximo) {
    this->proximo = proximo;
}

template <typename T>
void No<T>::InserirAnterior(No<T> *anterior) {
    this->anterior = anterior;
}

template <typename T>
No<T> *No<T>::GetProximo() {
    return this->proximo;
}

template <typename T>
No<T> *No<T>::GetAnterior() {
    return this->anterior;
}

template <typename T>
T No<T>::GetConteudo() {
    return this->conteudo;
}

template <typename T>
class Lista {
   private:
    int tamanho;
    No<T> *primeiro;
    No<T> *ultimo;
    No<T> *ponteiro;

   public:
    Lista();
    ~Lista();

    bool IsVazia();
    int GetTamanho();
    T *GetItem(int pos);
    void SetItem(T item, int pos);
    void Inserir(T item);
    void RemoveInicio();
    void RemoveFinal();
    void RemovePosicao(int pos);
    int Pesquisa(T item);
    void Imprime();
    void Limpa();
};

template <typename T>
Lista<T>::Lista() {
    tamanho = 0;

    primeiro = new No<T>();
    ultimo = primeiro;
}

template <typename T>
Lista<T>::~Lista() {
    Limpa();
    delete primeiro;
}

template <typename T>
bool Lista<T>::IsVazia() {
    return tamanho == 0;
}

template <typename T>
int Lista<T>::GetTamanho() {
    return tamanho;
}

template <typename T>
T *Lista<T>::GetItem(int pos) {
    No<T> *aux = new No<T>();

    for (int i = 0; i < pos; i++) {
        if (aux && aux->proximo != nullptr) {
            aux = aux->proximo;
        }
    }

    return &aux->conteudo;
}

template <typename T>
void Lista<T>::SetItem(T item, int pos) {
    No<T> *aux = new No<T>();
    aux = primeiro;

    for (int i = 0; i < pos; i++) {
        aux = aux->proximo;
    }

    aux->conteudo = item;
}

template <typename T>
void Lista<T>::Inserir(T item) {
    No<T> *nova = new No<T>();
    nova->conteudo = item;
    nova->proximo = primeiro->proximo;
    primeiro->proximo = nova;

    tamanho++;
}

template <typename T>
void Lista<T>::RemoveInicio() {
    No<T> *p;

    if (tamanho == 0)
        throw "Erro: Lista vazia";

    p = primeiro->proximo;
    primeiro->proximo = p->proximo;
    tamanho--;

    if (primeiro->proximo == nullptr)
        ultimo = primeiro;

    delete p;
}

template <typename T>
void Lista<T>::RemoveFinal() {
    RemovePosicao(tamanho);
}

template <typename T>
void Lista<T>::RemovePosicao(int pos) {
    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    No<T> *atual = primeiro;

    for (int i = 0; i < pos - 1; i++)
        atual = atual->proximo;

    No<T> *aux = atual->proximo;
    atual->proximo = aux->proximo;

    delete aux;

    tamanho--;
}

template <typename T>
int Lista<T>::Pesquisa(T item) {
    No<T> *aux = new No<T>();
    aux = primeiro;
    int local = 0;

    while (aux) {
        if (aux->conteudo == item) {
            return local;
        }

        local++;
        aux = aux->proximo;
    }

    return -1;
}

template <typename T>
void Lista<T>::Imprime() {
    No<T> *p = primeiro;

    p = primeiro->proximo;
    while (p != nullptr) {
        cout << p->conteudo << " ";
        p = p->proximo;
    }

    cout << endl;
}

template <typename T>
void Lista<T>::Limpa() {
    No<T> *p = primeiro->proximo;

    while (p != nullptr) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}

template class Lista<int>;

#endif