#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#define PRE_ORDEM 1
#define IN_ORDEM 2
#define POS_ORDEM 3

#include <iostream>

#include "Email.hpp"

using namespace std;

class ArvoreBinaria {
   private:
    int tamanho;
    Email *raiz;

    void InserirRecursivo(Email *&p, Email *email);
    void RemoverRecursivo(Email *p);
    int PesquisarRecursivo(Email *&p, int chave);

   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    bool IsVazia();
    void Inserir(Email *email);
    int Pesquisar(int chave);
    void Caminha(int tipo);
    void PreOrdem(Email *p);
    void InOrdem(Email *p);
    void PosOrdem(Email *p);
    void Limpa();
};
#endif