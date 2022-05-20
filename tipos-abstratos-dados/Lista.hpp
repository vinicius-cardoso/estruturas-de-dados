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
    No();
    No(T item);

    friend class Lista<T>;
};

template <typename T>
class Lista {
   private:
    int tamanho;
    No<T> *primeiro;
    No<T> *ultimo;

   public:
    Lista();
    ~Lista();
    T GetItem(int pos);
    int GetTamanho();
    // void SetItem(T item, int pos);
    void InsereInicio(T item);
    void InsereFinal(T item);
    // void InserePosicao(T item, int pos);
    No<T> RemoveInicio();
    T RemoveFinal();
    // T RemovePosicao(int pos);
    // T Pesquisa(T c);
    void Imprime();
    void Limpa();
};

template <class T>
No<T>::No() {
    No<T> *proximo = NULL;
}

template <class T>
No<T>::No(T item) {
    conteudo = item;
    No<T> *proximo = NULL;
}

template <class T>
Lista<T>::Lista() {
    tamanho = 0;
    primeiro = new No<T>();
    primeiro->proximo = primeiro;
    ultimo = primeiro;
}

template <class T>
Lista<T>::~Lista() {
    Limpa();
    delete primeiro;
}

template <class T>
int Lista<T>::GetTamanho() {
    return tamanho + 1;
}

template <class T>
void Lista<T>::InsereInicio(T item) {
    T *nova;
    nova = new No<T>();

    nova->conteudo = item;
    nova->proximo = primeiro->proximo;
    primeiro->proximo = nova;

    tamanho++;

    if (nova->proximo == NULL)
        ultimo = nova;
}

template <class T>
void Lista<T>::InsereFinal(T item) {
    No<T> *nova = new No<T>();

    nova->conteudo = item;
    ultimo->proximo = nova;
    ultimo = nova;

    tamanho++;
}

template <class T>
No<T> Lista<T>::RemoveInicio() {
    No<T> aux;
    No<T> *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->proximo;
    primeiro->proximo = p->proximo;

    tamanho--;

    if (primeiro->proximo == NULL)
        ultimo = primeiro;

    aux = p->conteudo;

    delete p;

    return aux;
}

template <class T>
void Lista<T>::Imprime() {
    No<T> *p = primeiro;

    while (p != NULL) {
        cout << p->conteudo << " ";
        p = p->proximo;
    }

    cout << endl;
}

template <class T>
void Lista<T>::Limpa() {
    No<T> *p;
    p = primeiro->proximo;

    while (p != NULL) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
};

#endif