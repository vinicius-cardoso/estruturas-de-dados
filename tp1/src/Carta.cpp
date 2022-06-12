#include "Carta.hpp"

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

void Carta::SetValor(int valor) {
    this->valor = valor;
}

int Carta::GetValor() {
    return this->valor;
}

void Carta::SetNaipe(char naipe) {
    this->naipe = naipe;
}

char Carta::GetNaipe() {
    return this->naipe;
}

void Carta::SetCarta(string carta) {
    if (carta == "VAZIO") {
        this->carta = "VAZIO";
    } else {
        string aux = carta;
        this->carta = aux;
        this->naipe = carta.back();  // back() retorna o ultimo elemento da string
        carta.pop_back();            // pop_back() remove o ultimo elemento da string

        this->valor = stoi(carta);  // converte a string em int
    }
}

string Carta::GetCarta() {
    return this->carta;
}