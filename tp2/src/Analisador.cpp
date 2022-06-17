#include "Analisador.hpp"

#include "Palavra.hpp"

#define NUMERO_DE_LETRAS 26

Analisador::Analisador() {}

void Analisador::Analisar(string nome_arq_entrada) {
    ifstream arquivo_entrada(nome_arq_entrada);
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    string texto, aux;
    string ordem[NUMERO_DE_LETRAS];

    int numero_de_espacos = 0, indice_palavras = 0;

    getline(arquivo_entrada, texto);  // primeira linha "#TEXTO"
    getline(arquivo_entrada, texto);  // le a frase

    stringstream ss(texto);

    for (int i = 0; i < texto.size(); i++) {
        if (texto[i] == ' ') {
            numero_de_espacos++;
        }
    }

    Palavra *palavras = new Palavra[numero_de_espacos + 1]();

    // verifica a ocorrencia de espacos na frase e +
    // adiciona cada palavra em um array de palavras
    while (getline(ss, aux, ' ')) {
        palavras[indice_palavras].SetPalavra(aux);
        palavras[indice_palavras].SetTamanho(aux.size());

        indice_palavras++;
    }

    for (int i = 0; i < numero_de_espacos + 1; i++) {
        cout << palavras[i].GetPalavra() << endl;
    }

    getline(arquivo_entrada, texto);  // terceira linha "#ORDEM"
    // armazena em um vetor de char a ordem lexografica dada
    for (int i = 0; i < NUMERO_DE_LETRAS; i++) {
        arquivo_entrada >> ordem[i];
    }

    delete[] palavras;
}