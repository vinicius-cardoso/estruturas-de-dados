#include <getopt.h>
#include <string.h>

#include <fstream>
#include <iostream>

#include "ServidorDeEmail.hpp"
#include "memlog.hpp"

using namespace std;

string nome_arquivo_entrada;
string nome_arquivo_saida;
// char logname[100];
// bool regmem;

void ParseArgs(int argc, char **argv) {
    // variaveis externas do getopt
    extern char *optarg;
    extern int optind;

    // variavel auxiliar
    int opcao;

    // opcoes
    // regmem = false;
    // logname[0] = 0;

    while ((opcao = getopt(argc, argv, "i:I:o:O:p:l")) != EOF) {
        switch (opcao) {
            case 'i':
            case 'I':
                nome_arquivo_entrada = optarg;
                // retorna uma excecao se o nome do arquivo informado for menor que 1
                erroAssert(nome_arquivo_entrada.length() > 0, "Erro: O arquivo de entrada nao foi informado");
                break;

            case 'o':
            case 'O':
                nome_arquivo_saida = optarg;
                // retorna uma excecao se o nome do arquivo informado for menor que 1
                erroAssert(nome_arquivo_saida.length() > 0, "Erro: O arquivo de saida nao foi informado");
                break;

                // case 'p':
                // strcpy(logname, optarg);
                // break;

                // case 'l':
                // regmem = true;
                // break;

            default:
                exit(1);
        }
    }

    erroAssert(nome_arquivo_entrada.length() > 0, "Erro: O arquivo de entrada nao foi informado");
    erroAssert(nome_arquivo_saida.length() > 0, "Erro: O arquivo de saida nao foi informado");
}

int main(int argc, char **argv) {
    // le os nomes do arquivo de entrada e arquivo de saida
    ParseArgs(argc, argv);

    // inicia o registro de acesso
    // iniciaMemLog(logname);

    // ativa o registro de acesso
    // ativaMemLog();

    ifstream arquivo_entrada(nome_arquivo_entrada);

    // retorna uma exceção se o arquivo de entrada não puder ser aberto
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    // abre um arquivo de saída em modo de sobrescrita
    ofstream arquivo_saida(nome_arquivo_saida, ios::trunc);

    int tamanho_tabela;

    arquivo_entrada >> tamanho_tabela;

    // cria uma hash contendo o numero de elementos igual ao tamanho da tabela dado
    ServidorDeEmail *servidor_de_email = new ServidorDeEmail(tamanho_tabela);

    servidor_de_email->Iniciar(*&arquivo_entrada, *&arquivo_saida);

    // return finalizaMemLog();
    return 0;
}