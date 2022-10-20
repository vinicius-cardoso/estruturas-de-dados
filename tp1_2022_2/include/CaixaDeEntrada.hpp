#ifndef CAIXA_DE_ENTRADA
#define CAIXA_DE_ENTRADA

#include "ListaDeEmails.hpp"

class CaixaDeEntrada {
   private:
    int id;
    ListaDeEmails *lista_de_emails;
    CaixaDeEntrada *proximo;

   public:
    CaixaDeEntrada(int id);
    ~CaixaDeEntrada();

    bool IsVazia();
    int GetId();
    void AdicionarEmail(Email *email);
    string LerEmail();

    friend class ListaDeCaixas;
};

#endif
