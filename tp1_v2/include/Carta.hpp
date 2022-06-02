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

    int GetValor();
    char GetNaipe();
    string GetCarta();
    void SetValor(int valor);
    void GetNaipe(char naipe);
    void SetCarta(string carta);
};

Carta::Carta() {
    carta = "VAZIO";
    naipe = 'Z';
    valor = 0;
}

Carta::Carta(string carta) {
    this->carta = carta;
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

void Carta::SetValor(int valor) {
    this->valor = valor;
}
void Carta::GetNaipe(char naipe) {
    this->naipe = naipe;
}
void Carta::SetCarta(string carta) {
    string aux = carta;
    this->carta = aux;
    this->naipe = carta.back();  // back() retorna o ultimo elemento da string
    carta.pop_back();            // pop_back() remove o ultimo elemento da string

    this->valor = stoi(carta);  // converte a string em int
}

#endif