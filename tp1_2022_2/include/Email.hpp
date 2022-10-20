#ifndef EMAIL
#define EMAIL

#include <iostream>
#include <string>

#include "msgassert.hpp"

using namespace std;

class Email {
   private:
    int prioridade;
    string mensagem;
    Email *proximo;

   public:
    Email(int prioridade, string mensagem);
    ~Email();

    int GetPrioridade();
    string GetMensagem();

    friend class ListaDeEmails;
};

#endif
