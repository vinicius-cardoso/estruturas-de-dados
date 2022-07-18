#include <fstream>
#include <iostream>

#include "ServidorDeEmail.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string nome_arquivo_entrada = argv[1];
    string nome_arquivo_saida = argv[2];

    ifstream arquivo_entrada(nome_arquivo_entrada);
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    ofstream arquivo_saida(nome_arquivo_saida, ios::trunc);

    int tamanho_tabela;

    arquivo_entrada >> tamanho_tabela;

    // cria uma hash contendo o numero de elementos igual ao tamanho da tabela dado
    ServidorDeEmail *servidor_de_email = new ServidorDeEmail(tamanho_tabela);

    servidor_de_email->Iniciar(*&arquivo_entrada, *&arquivo_saida);

    return 0;
}