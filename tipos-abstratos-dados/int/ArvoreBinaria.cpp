#include "ArvoreBinaria.hpp"

No::No(int item) {
    this->item = item;
    this->esquerda = nullptr;
    this->direita = nullptr;
}

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
    tamanho = 0;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpar();

    delete raiz;
}

bool ArvoreBinaria::IsVazia() {
    return tamanho == 0;
}

void ArvoreBinaria::InserirRecursivo(No *&p, int item) {
    if (p == nullptr) {
        p = new No(item);
    } else {
        if (item < p->item)
            InserirRecursivo(p->esquerda, item);
        else
            InserirRecursivo(p->direita, item);
    }
}

void ArvoreBinaria::Inserir(int item) {
    InserirRecursivo(raiz, item);

    tamanho++;
}

bool ArvoreBinaria::ApagarRecursivo(No *&p, int chave) {
    if (p == nullptr)
        return false;

    if (chave < p->item)
        return ApagarRecursivo(p->esquerda, chave);
    else if (chave > p->item)
        return ApagarRecursivo(p->direita, chave);
    else {
        No *temp_dir = p->direita;

        if (p->direita == nullptr) {
            No *temp_esq = p->esquerda;
            delete p;
            p = temp_esq;
        } else if (p->esquerda == nullptr) {
            delete p;
            p = temp_dir;
        } else {
            No *proximo_pai = p;

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

bool ArvoreBinaria::Apagar(int chave) {
    tamanho--;

    return ApagarRecursivo(raiz, chave);
}

int ArvoreBinaria::PesquisarRecursivo(No *&p, int chave) {
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

int ArvoreBinaria::Pesquisar(int chave) {
    return PesquisarRecursivo(raiz, chave);
}

void ArvoreBinaria::RemoverRecursivo(No *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

void ArvoreBinaria::Caminhar(int tipo) {
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

void ArvoreBinaria::PreOrdem(No *p) {
    if (p != nullptr) {
        cout << p->item << " ";
        PreOrdem(p->esquerda);
        PreOrdem(p->direita);
    }
}

void ArvoreBinaria::InOrdem(No *p) {
    if (p != nullptr) {
        InOrdem(p->esquerda);
        cout << p->item << " ";
        InOrdem(p->direita);
    }
}

void ArvoreBinaria::PosOrdem(No *p) {
    if (p != nullptr) {
        PosOrdem(p->esquerda);
        PosOrdem(p->direita);
        cout << p->item << " ";
    }
}

void ArvoreBinaria::Limpar() {
    RemoverRecursivo(raiz);

    raiz = nullptr;
}