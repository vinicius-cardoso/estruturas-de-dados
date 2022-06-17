#include "Palavra.hpp"

Palavra::Palavra() {
    this->palavra = "";
    this->tamanho = 0;
}

void Palavra::SetPalavra(string palavra) {
    this->palavra = palavra;
}

string Palavra::GetPalavra() {
    return this->palavra;
}

void Palavra::SetTamanho(int tamanho) {
    this->tamanho = tamanho;
}

int Palavra::GetTamanho() {
    return this->tamanho;
}

string Palavra::OrdenarPalavras() {}