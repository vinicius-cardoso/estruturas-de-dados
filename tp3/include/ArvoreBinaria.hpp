#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <iostream>

#include "Email.hpp"

using namespace std;

class ArvoreBinaria {
   private:
    int tamanho;
    Email *raiz;

    void InserirRecursivo(Email *&p, Email *email);
    void RemoverRecursivo(Email *p);
    bool ApagarRecursivo(Email *&p, int chave);
    int PesquisarRecursivo(Email *&p, int chave);
    string PesquisarEmailRecursivo(Email *&p, int chave, int destinatario);

   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    bool IsVazia();
    void Inserir(Email *email);
    bool Apagar(int chave);
    int Pesquisar(int chave);
    string PesquisarEmail(int chave, int destinatario);
    void Limpa();
};

#endif