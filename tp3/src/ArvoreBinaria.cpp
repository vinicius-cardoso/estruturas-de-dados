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
    // aloca espaco para um novo objeto do tipo email
    if (p == nullptr) {
        p = new Email(email->id_email, email->id_destinatario, email->mensagem);
        // insere nos na arvore de maneira ordenada
    } else {
        if (email->GetIdEmail() < p->GetIdEmail())
            InserirRecursivo(p->esquerda, email);
        else
            InserirRecursivo(p->direita, email);
    }
}

void ArvoreBinaria::Inserir(Email *email) {
    InserirRecursivo(raiz, email);

    tamanho++;
}

bool ArvoreBinaria::ApagarRecursivo(Email *&p, int chave) {
    if (p == nullptr)
        return false;

    if (chave < p->GetIdEmail())
        return ApagarRecursivo(p->esquerda, chave);
    else if (chave > p->GetIdEmail())
        return ApagarRecursivo(p->direita, chave);
    else {
        Email *temp_dir = p->direita;

        if (p->direita == nullptr) {
            Email *temp_esq = p->esquerda;
            delete p;
            p = temp_esq;
        } else if (p->esquerda == nullptr) {
            delete p;
            p = temp_dir;
        } else {
            Email *proximo_pai = p;

            // enquanto nao chegar no ultimo elemento da esquerda
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

int ArvoreBinaria::PesquisarRecursivo(Email *&p, int chave) {
    if (p == nullptr)
        return -1;

    if (chave < p->GetIdEmail())
        return PesquisarRecursivo(p->esquerda, chave);
    else if (chave > p->GetIdEmail())
        return PesquisarRecursivo(p->direita, chave);
    else {
        return p->GetIdEmail();
    }
}

int ArvoreBinaria::Pesquisar(int chave) {
    return PesquisarRecursivo(raiz, chave);
}

string ArvoreBinaria::PesquisarEmailRecursivo(Email *&p, int chave, int destinatario) {
    if (p == nullptr)
        return "";

    if (chave < p->GetIdEmail())
        return PesquisarEmailRecursivo(p->esquerda, chave, destinatario);
    else if (chave > p->GetIdEmail())
        return PesquisarEmailRecursivo(p->direita, chave, destinatario);
    else {
        // verifica se o email encontrado contem o identificador do destinatario
        // caso nao haja, retorna uma string vazia
        if (p->GetIdDestinatario() == destinatario)
            return p->GetMensagem();
        else
            return "";
    }
}

string ArvoreBinaria::PesquisarEmail(int chave, int destinatario) {
    return PesquisarEmailRecursivo(raiz, chave, destinatario);
}

void ArvoreBinaria::RemoverRecursivo(Email *p) {
    if (p != nullptr) {
        RemoverRecursivo(p->esquerda);
        RemoverRecursivo(p->direita);

        delete p;
    }
}

void ArvoreBinaria::Limpa() {
    RemoverRecursivo(raiz);
    raiz = nullptr;
}