#include "Analisador.hpp"

int main(int argc, char *argv[]) {
    Analisador *analisador = new Analisador();

    string nome_arquivo_entrada = argv[1];

    analisador->Analisar(nome_arquivo_entrada);

    return 0;
}