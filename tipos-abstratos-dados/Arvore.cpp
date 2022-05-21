#include "Arvore.hpp"

#define PRE_ORDEM 1
#define IN_ORDEM 2
#define POS_ORDEM 3

int main() {
    Arvore<int> a;

    a.Inserir(3);
    a.Inserir(2);
    a.Inserir(1);
    a.Inserir(5);
    a.Inserir(4);
    a.Inserir(6);

    a.Caminha(PRE_ORDEM);
    a.Caminha(IN_ORDEM);
    a.Caminha(POS_ORDEM);
}