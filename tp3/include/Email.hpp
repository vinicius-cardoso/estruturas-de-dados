#ifndef EMAIL_H
#define EMAIL_H

#include <string>

#include "memlog.hpp"
#include "msgassert.hpp"

using namespace std;

class Email {
   private:
    int id_email;
    int id_destinatario;
    string mensagem;

    Email *esquerda;
    Email *direita;

   public:
    Email(int id_email, int id_destinatario, string mensagem);
    int GetIdEmail();
    int GetIdDestinatario();
    string GetMensagem();

    friend class ArvoreBinaria;
};

#endif