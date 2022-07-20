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

    // retorna um erro se o usuario tentar inserir um item que ja esta presente
    erroAssert(aux == -1, "Erro: Este item ja esta presente");

    pos = Hash(id_destinatario);

    Tabela[pos].Inserir(email);
}

void ServidorDeEmail::Entrega(int id_destinatario, int id_email, string mensagem, ArvoreBinaria *Tabela) {
    Email *email = new Email(id_email, id_destinatario, mensagem);

    Inserir(email, Tabela, id_destinatario);
}

string ServidorDeEmail::Consulta(int id_destinatario, int id_email, ArvoreBinaria *Tabela) {
    string mensagem = Tabela[Hash(id_destinatario)].PesquisarEmail(id_email, id_destinatario);

    return mensagem;
}

bool ServidorDeEmail::Apaga(int id_destinatario, int id_email, ArvoreBinaria *Tabela) {
    bool mensagem_existe = false;
    int hash = Hash(id_destinatario);

    mensagem_existe = Tabela[hash].Apagar(id_email);

    return mensagem_existe;
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

        string mensagem;

        // so le a mensagem quando a operacao eh de entrega
        if (operacao == "ENTREGA") {
            arquivo_entrada >> nr_palavras;

            // adiciona cada linha de palavras a uma unica frase
            for (int i = 0; i < nr_palavras; i++) {
                arquivo_entrada >> linha;
                mensagem += linha;

                // adiciona espacos entre as palavras, menos ao final da ultima palavra
                if (i != nr_palavras - 1)
                    mensagem += " ";
            }
        }

        if (operacao == "ENTREGA") {
            Entrega(id_destinatario, id_email, mensagem, Tabela);

            arquivo_saida << "OK: MENSAGEM " << id_email << " PARA " << id_destinatario << " ARMAZENADA EM " << Hash(id_destinatario) << endl;
        } else if (operacao == "CONSULTA") {
            string mensagem = Consulta(id_destinatario, id_email, Tabela);

            if (mensagem != "")
                arquivo_saida << "CONSULTA " << id_destinatario << " " << id_email << ": " << mensagem << endl;
            else
                arquivo_saida << "CONSULTA " << id_destinatario << " " << id_email << ": MENSAGEM INEXISTENTE" << endl;
        } else if (operacao == "APAGA") {
            if (Apaga(id_destinatario, id_email, Tabela))
                arquivo_saida << "OK: MENSAGEM APAGADA" << endl;
            else
                arquivo_saida << "ERRO: MENSAGEM INEXISTENTE" << endl;
        } else
            // retorna uma excecao caso haja uma operacao diferentes das previstas
            throw "Erro: Operacao invalida no arquivo";
    }
}