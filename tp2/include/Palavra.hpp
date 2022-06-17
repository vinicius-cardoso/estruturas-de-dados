#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

class Palavra {
   private:
    string palavra;
    int tamanho;

   public:
    Palavra();

    void SetPalavra(string palavra);
    string GetPalavra();
    void SetTamanho(int tamanho);
    int GetTamanho();
    void ImprimePalavras();
    string OrdenarPalavras();
};

#endif