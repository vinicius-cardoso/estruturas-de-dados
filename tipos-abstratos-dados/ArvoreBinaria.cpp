#include "ArvoreBinaria.hpp"

template <class T>
No<T>::No(T item) {
    this->item = item;
    this->esquerda = nullptr;
    this->direita = nullptr;
}

template <class T>
ArvoreBinaria<T>::ArvoreBinaria() {
    raiz = nullptr;
    tamanho = 0;
}

template <class T>
ArvoreBinaria<T>::~ArvoreBinaria() {
    Limpar();

    delete raiz;
}

template <class T>
bool ArvoreBinaria<T>::IsVazia() {
    return tamanho == 0;
}

template <class T>
void ArvoreBinaria<T>::InserirRecursivo(No<T> *&p, T item) {
    if (p == nullptr) {
        p = new No<T>(item);
    } else {
        if (item < p->item)
            InserirRecursivo(p->esquerda, item);
        else
            InserirRecursivo(p->direita, item);
    }
}

template <class T>
void ArvoreBinaria<T>::Inserir(T item) {
    InserirRecursivo(raiz, item);

    tamanho++;
}

template <class T>
bool ArvoreBinaria<T>::ApagarRecursivo(No<T> *&p, T chave) {
    if (p == nullptr)
        return false;

    if (chave < p->item)
        return ApagarRecursivo(p->esquerda, chave);
    else if (chave > p->item)
        return ApagarRecursivo(p->direita, chave);
    else {
        No<T> *temp_dir = p->direita;

        if (p->direita == nullptr) {
            No<T> *temp_esq = p->esquerda;
            delete p;
            p = temp_esq;
        } else if (p->esquerda == nullptr) {
            delete p;
            p = temp_dir;
        } else {
            No<T> *proximo_pai = p;

            while (temp_dir->esquerda != nullptr) {
                proximo_pai = temp_dir;
                temp_dir = temp_dir->esquerda;
            }

            if (proximo_pai != p)
                proximo_pai->esquerda = temp_dir->direita;
            else
                proximo_pai->direita = temp_dir->direita;

            delete temp_dir;
        }
    }

    return true;
}

template <class T>
bool ArvoreBinaria<T>::Apagar(T chave) {
    tamanho--;

    return ApagarRecursivo(raiz, chave);
}

template <class T>
T ArvoreBinaria<T>::PesquisarRecursivo(No<T> *&p, T chave) {
    if (p == nullptr)
        return -1;

    if (chave < p->item)
        return PesquisarRecursivo(p->esquerda, chave);
    else if (chave > p->item)
        return PesquisarRecursivo(p->direita, chave);
    else {
        return p->item;
    }
}

template <class T>
T ArvoreBinaria<T>::Pesquisar(T chave) {
    return PesquisarRecursivo(raiz, chave);
}

template <class T>
void ArvoreBinaria<T>::PreOrdem(No<T> *p) {
    if (p != nullptr) {
        cout << p->item << " ";
        PreOrdem(p->esquerda);
        PreOrdem(p->direita);
    }
}

template <class T>
void ArvoreBinaria<T>::InOrdem(No<T> *p) {
    if (p != nullptr) {
        InOrdem(p->esquerda);
        cout << p->item << " ";
        InOrdem(p->direita);
    }
}

template <class T>
void ArvoreBinaria<T>::PosOrdem(No<T> *p) {
    if (p != nullptr) {
        PosOrdem(p->esquerda);
        PosOrdem(p->direita);
        cout << p->item << " ";
    }
}

template <class T>
void ArvoreBinaria<T>::Caminhar(int tipo) {
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
void ArvoreBinaria<T>::RemoverRecursivo(No<T> *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

template <class T>
void ArvoreBinaria<T>::Limpar() {
    RemoverRecursivo(raiz);

    raiz = nullptr;
}

int main() {
    ArvoreBinaria<char> *arv1 = new ArvoreBinaria<char>();

    arv1->Inserir('c');
    arv1->Inserir('a');
    arv1->Inserir('e');
    arv1->Inserir('b');
    arv1->Inserir('d');

    arv1->Caminhar(PRE_ORDEM);
    arv1->Caminhar(IN_ORDEM);
    arv1->Caminhar(POS_ORDEM);

    arv1->Pesquisar('c') ? cout << "encontrado\n" : cout << "nao encontrado\n";

    arv1->Apagar('c');
    arv1->Apagar('a');
    arv1->Apagar('e');

    arv1->Caminhar(PRE_ORDEM);
    arv1->Caminhar(IN_ORDEM);
    arv1->Caminhar(POS_ORDEM);

    return 0;
}