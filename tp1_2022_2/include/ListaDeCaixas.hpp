#ifndef LISTA_DE_CAIXAS
#define LISTA_DE_CAIXAS

#include "CaixaDeEntrada.hpp"

class ListaDeCaixas {
   private:
    int tamanho;

    CaixaDeEntrada *primeiro;
    CaixaDeEntrada *ultimo;

   public:
    ListaDeCaixas();
    ~ListaDeCaixas();

    bool IsVazia();
    CaixaDeEntrada *GetCaixa(int id);
    void InserirCaixa(CaixaDeEntrada *caixa_de_entrada);
    void RemoverCaixa(int id);
    bool PesquisarCaixa(int id);
    void Limpar();
};

#endif
