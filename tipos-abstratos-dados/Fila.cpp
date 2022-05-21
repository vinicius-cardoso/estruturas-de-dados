#include "Fila.hpp"

int main() {
    Fila<int> f;

    f.Enfileirar(0);
    f.Enfileirar(1);
    f.Enfileirar(2);
    f.Enfileirar(3);
    f.Enfileirar(4);

    f.Desenfileirar();
    f.Desenfileirar();

    f.Imprime();

    return 0;
}