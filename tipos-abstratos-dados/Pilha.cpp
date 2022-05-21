#include "Pilha.hpp"

int main() {
    Pilha<int> p;

    p.Empilhar(0);
    p.Empilhar(1);
    p.Empilhar(2);
    p.Empilhar(3);
    p.Empilhar(4);

    p.Desempilhar();
    p.Desempilhar();

    cout << "Tamanho: " << p.GetTamanho() << endl;

    p.Imprime();

    return 0;
}