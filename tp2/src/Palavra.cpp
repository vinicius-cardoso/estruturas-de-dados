#include "Palavra.hpp"

void Palavra::SetPalavra(string palavra) {
    this->palavra = palavra;
}

string Palavra::GetPalavra() {
    return this->palavra;
}

void Palavra::SetFrequencia(int frequencia) {
    this->frequencia = frequencia;
}

int Palavra::GetFrequencia() {
    return this->frequencia;
}

bool Palavra::PalavraMaiorQue(Palavra *palavra) {
    return palavra->GetPalavra() > this->palavra;
}

bool Palavra::FrequenciaMaiorQue(Palavra *palavra) {
    return palavra->GetFrequencia() > this->frequencia;
}