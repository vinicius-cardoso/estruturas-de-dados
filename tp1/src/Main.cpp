#include "Mesa.hpp"

int main(int argc, char *argv[]) {
    Mesa *mesa = new Mesa();

    string nome_arquivo_entrada = argv[1];

    mesa->Partida(nome_arquivo_entrada);

    return 0;
}