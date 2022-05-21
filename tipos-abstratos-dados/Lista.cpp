#include "Lista.hpp"

int main() {
    Lista<int> l;

    l.InsereInicio(2);
    l.InsereFinal(4);

    l.InsereInicio(1);
    l.InsereFinal(5);

    l.InsereInicio(0);
    l.InsereFinal(6);

    l.InserePosicao(3, 4);

    cout << "Tamanho: " << l.GetTamanho() << endl;

    int posicao = 4;

    cout << "Posicao " << posicao << ": " << l.GetItem(posicao) << endl;

    l.Imprime();

    int pesquisa = 3;

    cout << pesquisa << " na posicao: " << l.Pesquisa(pesquisa) << endl;

    l.RemoveInicio();
    l.RemoveFinal();
    l.RemovePosicao(3);

    l.InserePosicao(3, 3);

    l.SetItem(10, 2);

    l.Imprime();

    return 0;
}
