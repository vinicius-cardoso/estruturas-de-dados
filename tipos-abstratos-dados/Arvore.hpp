#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

template <class T>
class Arvore;

template <class T>
class No {
   private:
    T conteudo;
    No<T> *esquerda;
    No<T> *direita;
    No<T> *proximo;

   public:
    No();
    No(T item);
    void SetItem(T item);
    T GetItem();

    friend class Arvore<T>;
};

template <class T>
No<T>::No() {
    conteudo = -1;
    No<T> *proximo = nullptr;
}

template <class T>
No<T>::No(T item) {
    conteudo = item;
    proximo = nullptr;
    esquerda = nullptr;
    direita = nullptr;
}

template <class T>
void No<T>::SetItem(T item) {
    conteudo = item;
}

template <class T>
T No<T>::GetItem() {
    return conteudo;
}

template <class T>
class Arvore {
   private:
    int tamanho;
    No<T> *raiz;

    void InserirRecursivo(No<T> *&p, T item);
    void RemoverRecursivo(No<T> *p);

   public:
    Arvore();
    ~Arvore();

    bool IsVazia();
    void Inserir(T item);
    void Caminha(int tipo);
    void PreOrdem(No<T> *p);
    void InOrdem(No<T> *p);
    void PosOrdem(No<T> *p);
    void Limpa();
};

template <class T>
Arvore<T>::Arvore() {
    tamanho = 0;
    raiz = nullptr;
}

template <class T>
Arvore<T>::~Arvore() {
    Limpa();
    delete raiz;
}

template <class T>
bool Arvore<T>::IsVazia() {
    return raiz == -1;
}

template <class T>
void Arvore<T>::InserirRecursivo(No<T> *&p, T item) {
    if (p == nullptr) {
        p = new No<T>();
        p->SetItem(item);
    } else {
        if (item < p->GetItem())
            InserirRecursivo(p->esquerda, item);
        else
            InserirRecursivo(p->direita, item);
    }
}

template <class T>
void Arvore<T>::Inserir(T item) {
    InserirRecursivo(raiz, item);
}

template <class T>
void Arvore<T>::Caminha(int tipo) {
    switch (tipo) {
        case 1:
            PreOrdem(raiz);
            cout << endl;
            break;
        case 2:
            InOrdem(raiz);
            cout << endl;
            break;
        case 3:
            PosOrdem(raiz);
            cout << endl;
            break;
    }
}

template <class T>
void Arvore<T>::PreOrdem(No<T> *p) {
    if (p != nullptr) {
        cout << " " << p->conteudo << " ";
        PreOrdem(p->esquerda);
        PreOrdem(p->direita);
    }
}

template <class T>
void Arvore<T>::InOrdem(No<T> *p) {
    if (p != nullptr) {
        InOrdem(p->esquerda);
        cout << " " << p->conteudo << " ";
        InOrdem(p->direita);
    }
}

template <class T>
void Arvore<T>::PosOrdem(No<T> *p) {
    if (p != nullptr) {
        PosOrdem(p->esquerda);
        PosOrdem(p->direita);
        cout << " " << p->conteudo << " ";
    }
}

template <class T>
void Arvore<T>::RemoverRecursivo(No<T> *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

template <class T>
void Arvore<T>::Limpa() {
    RemoverRecursivo(raiz);
    raiz = nullptr;
}

#endif