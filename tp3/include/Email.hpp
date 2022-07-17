#ifndef EMAIL_H
#define EMAIL_H

#include <string>

using namespace std;

class Email {
   private:
    int id;
    string mensagem;

    Email *esquerda;
    Email *direita;
    Email *proximo;

   public:
    Email(int id, string mensagem);
    int GetId();

    friend class ArvoreBinaria;
};

#endif