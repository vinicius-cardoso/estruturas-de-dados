#include <getopt.h>
#include <string.h>

#include <fstream>
#include <iostream>

#include "ImagemPGM.hpp"
#include "ImagemPPM.hpp"
#include "memlog.hpp"
#include "msgassert.hpp"

#define CODIGO_PGM "P2"

using namespace std;

const float VALOR_MAX_COR = 255;
const float VALOR_MAX_CINZA = 49;

string nome_arq_entrada;
string nome_arq_saida;

// char lognome[100];
// int regmem;

ImagemPPM *LerImagemPPM(string nome_arq_entrada) {
    ifstream arq_entrada(nome_arq_entrada);

    // retorna uma exceção se o arquivo de entrada não puder ser aberto
    erroAssert(!arq_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    string aux;
    int largura, altura;

    arq_entrada >> aux;
    arq_entrada >> largura >> altura;
    arq_entrada >> aux;

    ImagemPPM *imagem_ppm = new ImagemPPM(largura, altura);

    int *valores_R = new int[largura * altura];
    int *valores_G = new int[largura * altura];
    int *valores_B = new int[largura * altura];

    int indice = 0;
    int R, G, B;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            arq_entrada >> R >> G >> B;

            valores_R[indice] = R;
            valores_G[indice] = G;
            valores_B[indice] = B;

            indice++;
        }
    }

    imagem_ppm->SetValores(valores_R, valores_G, valores_B);

    return imagem_ppm;
}

void EscreverImagemPGM(string nome_arq_saida, int largura, int altura, int *valores_R, int *valores_G, int *valores_B) {
    // abre um arquivo de saída em modo de sobrescrita
    ofstream arq_saida(nome_arq_saida, ios::trunc);

    // retorna uma exceção se o arquivo de saida não puder ser aberto
    erroAssert(!arq_saida.fail(), "Falha ao abrir o arquivo de saida");

    arq_saida << CODIGO_PGM << endl;
    arq_saida << largura << " " << altura << endl;
    arq_saida << VALOR_MAX_CINZA << endl;

    int *valores = new int[largura * altura];

    int indice = 0;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            valores[indice] = (VALOR_MAX_CINZA / VALOR_MAX_COR) * (0.3 * valores_R[indice] + 0.59 * valores_G[indice] + 0.11 * valores_B[indice]);

            arq_saida << valores[indice];

            if (j < largura - 1) arq_saida << " ";

            indice++;
        }

        arq_saida << endl;
    }
}

void ConverterPPMparaPGM(ImagemPPM *imagem_ppm, string nome_arq_saida) {
    int largura = imagem_ppm->GetLargura();
    int altura = imagem_ppm->GetAltura();

    ImagemPGM *imagem_pgm = new ImagemPGM(largura, altura);

    int *valores_R = imagem_ppm->GetValoresR();
    int *valores_G = imagem_ppm->GetValoresG();
    int *valores_B = imagem_ppm->GetValoresB();

    // defineFaseMemLog(2);
    EscreverImagemPGM(nome_arq_saida, largura, altura, valores_R, valores_G, valores_B);
}

void ParseArgs(int argc, char **argv) {
    // variaveis externas do getopt
    extern char *optarg;
    extern int optind;

    // inicializacao variaveis globais para opcoes
    // regmem = 0;
    // lognome[0] = 0;

    int opcao;

    // while ((opcao = getopt(argc, argv, "i:I:o:O:p:l")) != EOF) {
    while ((opcao = getopt(argc, argv, "i:I:o:O")) != EOF) {
        switch (opcao) {
            case 'i':
            case 'I':
                nome_arq_entrada = optarg;
                // retorna uma excecao se o nome do arquivo informado for menor que 1
                erroAssert(nome_arq_entrada.length() > 0, "Erro: O arquivo de entrada nao foi informado");
                break;

            case 'o':
            case 'O':
                nome_arq_saida = optarg;
                // retorna uma excecao se o nome do arquivo informado for menor que 1
                erroAssert(nome_arq_saida.length() > 0, "Erro: O arquivo de saida nao foi informado");
                break;

                // case 'p':
                // strcpy(lognome, optarg);
                // break;

                // case 'l':
                // regmem = 1;
                // break;

            default:
                exit(1);
        }
    }

    erroAssert(nome_arq_entrada.length() > 0, "Erro: O arquivo de entrada nao foi informado");
    erroAssert(nome_arq_saida.length() > 0, "Erro: O arquivo de saida nao foi informado");
}

int main(int argc, char **argv) {
    // le os nomes do arquivo de entrada e arquivo de saida
    ParseArgs(argc, argv);

    // iniciar registro de acesso
    // iniciaMemLog(lognome);

    // ativar ou nao o registro de acesso
    // if (regmem)
    // ativaMemLog();
    // else
    // desativaMemLog();

    // ativa o registro de acesso
    // ativaMemLog();

    // defineFaseMemLog(0);
    ImagemPPM *imagem_ppm = LerImagemPPM(nome_arq_entrada);

    // defineFaseMemLog(1);
    ConverterPPMparaPGM(imagem_ppm, nome_arq_saida);

    // conclui registro de acesso
    // return finalizaMemLog();
}