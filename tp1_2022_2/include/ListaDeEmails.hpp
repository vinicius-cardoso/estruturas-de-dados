#ifndef LISTA_DE_EMAILS
#define LISTA_DE_EMAILS

#include "Email.hpp"

class ListaDeEmails {
   private:
    int tamanho;

    Email *primeiro;
    Email *ultimo;

   public:
    ListaDeEmails();
    ~ListaDeEmails();

    bool IsVazia();
    void InserirEmailOrdenado(Email *email);
    string RemoverEmailInicio();
    void Limpar();
};

#endif
