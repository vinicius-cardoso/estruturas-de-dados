#include "ArvoreBinaria.hpp"

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;
    tamanho = 0;
}

ArvoreBinaria::~ArvoreBinaria() {
    Limpa();
    delete raiz;
}

bool ArvoreBinaria::IsVazia() {
    return tamanho == 0;
}

void ArvoreBinaria::InserirRecursivo(Email *&p, Email *email) {
    if (p == nullptr) {
        p = new Email(email->id, email->mensagem);
    } else {
        if (email->GetId() < p->GetId())
            InserirRecursivo(p->esquerda, email);
        else
            InserirRecursivo(p->direita, email);
    }
}

void ArvoreBinaria::Inserir(Email *email) {
    InserirRecursivo(raiz, email);

    tamanho++;
}

int ArvoreBinaria::Pesquisar(int chave) {
    return PesquisarRecursivo(raiz, chave);
}

int ArvoreBinaria::PesquisarRecursivo(Email *&p, int chave) {
    if (p == nullptr) {
        return -1;
    }

    if (chave < p->GetId())
        return PesquisarRecursivo(p->esquerda, chave);
    else if (chave > p->GetId())
        return PesquisarRecursivo(p->direita, chave);
    else
        return p->GetId();
}

void ArvoreBinaria::RemoverRecursivo(Email *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

void ArvoreBinaria::Caminha(int tipo) {
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

void ArvoreBinaria::PreOrdem(Email *p) {
    if (p != nullptr) {
        cout << " " << p->GetId() << " ";
        PreOrdem(p->esquerda);
        PreOrdem(p->direita);
    }
}

void ArvoreBinaria::InOrdem(Email *p) {
    if (p != nullptr) {
        InOrdem(p->esquerda);
        cout << " " << p->GetId() << " ";
        InOrdem(p->direita);
    }
}

void ArvoreBinaria::PosOrdem(Email *p) {
    if (p != nullptr) {
        PosOrdem(p->esquerda);
        PosOrdem(p->direita);
        cout << " " << p->GetId() << " ";
    }
}

void ArvoreBinaria::Limpa() {
    RemoverRecursivo(raiz);
    raiz = nullptr;
}
