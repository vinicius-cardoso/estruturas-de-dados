#include <iostream>

#include "ServidorDeEmail.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string nome_arquivo_entrada = argv[1];
    string nome_arquivo_saida = argv[2];

    ServidorDeEmail *servidor_de_email = new ServidorDeEmail();

    servidor_de_email->Iniciar(nome_arquivo_entrada, nome_arquivo_saida);

    return 0;
}