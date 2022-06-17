#include "Analisador.hpp"

#include "Ordenador.hpp"
#include "Palavra.hpp"

#define NUMERO_DE_LETRAS 26

void Analisador::Analisar(string nome_arq_entrada) {
    ifstream arquivo_entrada(nome_arq_entrada);
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    string texto, aux;
    string ordem[NUMERO_DE_LETRAS];

    int numero_de_espacos = 0, indice_palavras = 0;

    getline(arquivo_entrada, texto);  // primeira linha "#TEXTO"
    getline(arquivo_entrada, texto);  // le a frase

    // permite a manipulacao da string texto
    stringstream ss(texto);

    // conta o numero de espacos para calcular a quantidade de palavras
    for (int i = 0; i < texto.size(); i++) {
        if (texto[i] == ' ') {
            numero_de_espacos++;
        }
    }

    int numero_de_palavras = numero_de_espacos + 1;

    Palavra *palavras = new Palavra[numero_de_palavras]();
    Ordenador *ordenador;

    // verifica a ocorrencia de espacos na frase e +
    // adiciona cada palavra em um array de palavras
    while (getline(ss, aux, ' ')) {
        // aux = aux.lowercase();
        palavras[indice_palavras].SetPalavra(aux);

        indice_palavras++;
    }

    // cout << endl
    //      << "Desordenado: " << endl;

    // for (int i = 0; i < numero_de_palavras; i++) {
    //     cout << palavras[i].GetPalavra() << endl;
    // }

    // cout << endl
    //      << "Ordenado: " << endl;

    // ordenador->OrdenarPorPalavra(palavras, 0, numero_de_palavras - 1);
    // ordenador->PrintArray(palavras, numero_de_palavras);

    ordenador->OrdenarPorPalavra(palavras, 0, numero_de_palavras - 1);

    // calcula a frequencia das palavras e retira as repetidas
    for (int i = 0; i < numero_de_palavras; i++) {
    }

    getline(arquivo_entrada, texto);  // terceira linha "#ORDEM"

    // armazena em um vetor de char a ordem lexografica dada
    for (int i = 0; i < NUMERO_DE_LETRAS; i++) {
        arquivo_entrada >> ordem[i];
    }

    delete[] palavras;
}