#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T>
class Lista;

template <class T>
class No {
   private:
    T conteudo;
    No<T> *proximo;

   public:
    No();
    No(T item, No<T> *ptr);

    friend class Lista<T>;
};

template <class T>
No<T>::No() {
    conteudo = -1;
    No<T> *proximo = nullptr;
}

template <class T>
No<T>::No(T item, No<T> *ptr) {
    conteudo = item;
    proximo = ptr;
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
    T GetItem(int pos);
    void SetItem(T item, int pos);
    int GetTamanho();
    void InsereInicio(T item);
    void InsereFinal(T item);
    void InserePosicao(T item, int pos);
    void RemoveInicio();
    void RemoveFinal();
    void RemovePosicao(int pos);
    int Pesquisa(T item);
    void Imprime();
    void Limpa();
};

template <class T>
Lista<T>::Lista() {
    tamanho = 0;

    primeiro = new No<T>();
    ultimo = primeiro;
}

template <class T>
Lista<T>::~Lista() {
    Limpa();
    delete primeiro;
}

template <class T>
bool Lista<T>::IsVazia() {
    return tamanho == 0;
}

template <class T>
T Lista<T>::GetItem(int pos) {
    ponteiro = primeiro;

    for (int i = 0; i < pos; i++) {
        if (ponteiro->proximo != nullptr)
            ponteiro = ponteiro->proximo;
    }

    return ponteiro->conteudo;
}

template <class T>
void Lista<T>::SetItem(T item, int pos) {
    ponteiro = primeiro;

    for (int i = 0; i < pos; i++) {
        ponteiro = ponteiro->proximo;
    }

    ponteiro->conteudo = item;
}

template <class T>
int Lista<T>::GetTamanho() {
    return tamanho;
}

template <class T>
void Lista<T>::InsereInicio(T item) {
    No<T> *nova = new No<T>();
    nova->conteudo = item;
    nova->proximo = primeiro->proximo;
    primeiro->proximo = nova;

    tamanho++;

    if (nova->proximo == nullptr)
        ultimo = nova;
}

template <class T>
void Lista<T>::InsereFinal(T item) {
    No<T> *nova = new No<T>();
    nova->conteudo = item;
    ponteiro = primeiro;

    while (ponteiro->proximo) {
        ponteiro = ponteiro->proximo;
    }

    ponteiro->proximo = nova;
    nova->proximo = nullptr;

    tamanho++;
}

template <class T>
void Lista<T>::InserePosicao(T item, int pos) {
    if (pos < 0 || pos > tamanho)
        throw "Erro: Posicao invalida";

    No<T> *p;
    No<T> *nova = new No<T>();
    nova->conteudo = item;

    ponteiro = primeiro;

    for (int i = 0; i < pos; i++) {
        p = ponteiro;
        ponteiro = ponteiro->proximo;
    }

    ponteiro = p;
    nova->proximo = ponteiro->proximo;
    ponteiro->proximo = nova;

    tamanho++;
}

template <class T>
void Lista<T>::RemoveInicio() {
    T aux;
    No<T> *p;

    if (tamanho == 0)
        throw "Erro: Lista vazia";

    p = primeiro->proximo;
    primeiro->proximo = p->proximo;
    tamanho--;

    if (primeiro->proximo == nullptr)
        ultimo = primeiro;

    aux = p->conteudo;

    delete p;
}

template <class T>
void Lista<T>::RemoveFinal() {
    RemovePosicao(tamanho);
}

template <class T>
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

template <class T>
int Lista<T>::Pesquisa(T item) {
    ponteiro = primeiro;
    int local = 0;

    while (ponteiro) {
        if (ponteiro->conteudo == item) {
            return local;
        }

        local++;
        ponteiro = ponteiro->proximo;
    }

    return -1;
}

template <class T>
void Lista<T>::Imprime() {
    No<T> *p = primeiro;

    p = primeiro->proximo;
    while (p != nullptr) {
        cout << p->conteudo << " ";
        p = p->proximo;
    }

    cout << endl;
}

template <class T>
void Lista<T>::Limpa() {
    No<T> *p;
    p = primeiro->proximo;

    while (p != nullptr) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
};

#endif