#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>

using namespace std;

class Carta {
   private:
    int valor;
    char naipe;
    string carta;

   public:
    Carta();
    Carta(string carta);

    void SetValor(int valor);
    int GetValor();
    void SetNaipe(char naipe);
    char GetNaipe();
    void SetCarta(string carta);
    string GetCarta();
};

#endif