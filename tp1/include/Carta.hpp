#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>

using namespace std;

class Carta {
   private:
    string carta;
    char naipe;
    int valor;

   public:
    Carta();
    Carta(string carta);

    int GetValor();
    char GetNaipe();
    string GetCarta();
};

Carta::Carta() {
    this->carta = "";
    this->naipe = ' ';
    this->valor = 0;
}

Carta::Carta(string carta) {
    this->naipe = carta.back();  // back() retorna o ultimo elemento da string
    carta.pop_back();            // pop_back() remove o ultimo elemento da string

    this->valor = stoi(carta);  // converte a string em int
}

int Carta::GetValor() {
    return this->valor;
}

char Carta::GetNaipe() {
    return this->naipe;
}

string Carta::GetCarta() {
    return this->carta;
}

#endif