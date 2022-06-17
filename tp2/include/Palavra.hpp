#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

using namespace std;

class Palavra {
   private:
    string palavra;
    int frequencia;
    Palavra *proximo = nullptr;

   public:
    void SetPalavra(string palavra);
    string GetPalavra();
    void SetFrequencia(int frequencia);
    int GetFrequencia();
    bool PalavraMaiorQue(Palavra *palavra);
    bool FrequenciaMaiorQue(Palavra *palavra);

    friend class ListaEncadeada;
};

#endif