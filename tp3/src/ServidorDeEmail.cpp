#include "ServidorDeEmail.hpp"

ServidorDeEmail::ServidorDeEmail(int tamanho_tabela) {
    this->tamanho_tabela = tamanho_tabela;
}

int ServidorDeEmail::Hash(int chave) {
    return chave % tamanho_tabela;
}

int ServidorDeEmail::Pesquisar(int chave, ArvoreBinaria *Tabela) {
    int item;
    int pos;

    pos = Hash(chave);
    item = Tabela[pos].Pesquisar(chave);

    return item;
}

void ServidorDeEmail::Inserir(Email *email, ArvoreBinaria *Tabela, int id_destinatario) {
    int aux;
    int pos;

    aux = Pesquisar(id_destinatario, Tabela);

    if (aux != -1)
        throw("Erro: item ja esta presente");

    pos = Hash(id_destinatario);

    Tabela[pos].Inserir(email);
}

void ServidorDeEmail::Imprime(ArvoreBinaria *Tabela, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (Tabela[i].IsVazia())
            cout << i << ": vazia" << endl;
        else {
            cout << i << ": ";
            Tabela[i].Caminha(2);
        }
    }
}

void ServidorDeEmail::Iniciar(ifstream &arquivo_entrada, ofstream &arquivo_saida) {
    string linha;
    string operacao;

    int id_destinatario;
    int id_email;
    int nr_palavras;

    ArvoreBinaria *Tabela = new ArvoreBinaria[tamanho_tabela];

    while (arquivo_entrada >> linha) {
        operacao = linha;

        arquivo_entrada >> id_destinatario;
        arquivo_entrada >> id_email;
        arquivo_entrada >> nr_palavras;

        string mensagem;

        // adiciona cada linha de palavras a uma unica frase
        for (int i = 0; i < nr_palavras; i++) {
            arquivo_entrada >> linha;
            mensagem += linha;

            // adiciona espacos entre as palavras, menos ao final da ultima palavra
            if (i != nr_palavras - 1)
                mensagem += " ";
        }

        if (operacao == "ENTREGA") {
            Entrega(id_destinatario, id_email, mensagem, Tabela);
        }
    }

    Imprime(Tabela, tamanho_tabela);
}

void ServidorDeEmail::Entrega(int id_destinatario, int id_email, string mensagem, ArvoreBinaria *Tabela) {
    Email *email = new Email(id_email, mensagem);

    Inserir(email, Tabela, id_destinatario);
}