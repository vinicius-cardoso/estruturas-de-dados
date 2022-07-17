#include "ServidorDeEmail.hpp"

ServidorDeEmail::ServidorDeEmail() {
    tamanho_tabela = 0;
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

void ServidorDeEmail::Inserir(Email *email, ArvoreBinaria *Tabela) {
    int aux;
    int pos;

    aux = Pesquisar(email->GetId(), Tabela);

    if (aux != -1)
        throw("Erro: item ja esta presente");

    pos = Hash(email->GetId());

    Tabela[pos].Inserir(email);
}

void ServidorDeEmail::Iniciar(string nome_arquivo_entrada, string nome_arquivo_saida) {
    ifstream arquivo_entrada(nome_arquivo_entrada);
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    // abre o arquivo em modo de sobreposicao (trunc)
    ofstream arquivo_saida(nome_arquivo_saida, ios::trunc);

    string linha;
    string operacao;

    int id_destinatario;
    int id_email;
    int nr_palavras;

    arquivo_entrada >> tamanho_tabela;

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
}

void ServidorDeEmail::Entrega(int id_destinatario, int id_email, string mensagem, ArvoreBinaria *Tabela) {
    Email *email = new Email(id_destinatario, mensagem);

    Tabela->Inserir(email);
}