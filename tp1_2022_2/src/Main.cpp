#include <fstream>

#include "ServidorDeEmails.hpp"

int main(int argc, char *argv[]) {
    ServidorDeEmails *servidor_de_emails = new ServidorDeEmails();

    // recebe como primeiro argumento da linha de comando o nome do arquivo
    string nome_arq_entrada = argv[1];

    // tenta abrir o arquivo e retorna uma excecao em caso de erro
    ifstream arq_entrada(nome_arq_entrada);
    erroAssert(!arq_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    // le o arquivo ate o final
    while (!arq_entrada.eof()) {
        string linha;

        arq_entrada >> linha;

        int id, prioridade;
        string mensagem;

        if (linha == "CADASTRA") {
            arq_entrada >> id;

            servidor_de_emails->CadastrarId(id);
        } else if (linha == "REMOVE") {
            arq_entrada >> id;

            servidor_de_emails->RemoverId(id);
        } else if (linha == "ENTREGA") {
            arq_entrada >> id >> prioridade;

            while (linha != "FIM") {
                arq_entrada >> linha;

                if (linha == "FIM") break;

                mensagem += linha;
                mensagem += " ";
            }

            servidor_de_emails->EntregarMensagem(id, prioridade, mensagem);
        } else if (linha == "CONSULTA") {
            arq_entrada >> id;

            servidor_de_emails->ConsultarId(id);
            // caso a operacao seja invalida, eh retornado uma excecao
        } else if (linha != "")
            throw "Erro: Comando invalido";
    }

    return 0;
}
