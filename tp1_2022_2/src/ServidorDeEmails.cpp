#include "ServidorDeEmails.hpp"

ServidorDeEmails::ServidorDeEmails() {
    this->caixas_de_entrada = new ListaDeCaixas();
}

ServidorDeEmails::~ServidorDeEmails() {
    delete caixas_de_entrada;
}

void ServidorDeEmails::CadastrarId(int id) {
    if (caixas_de_entrada->PesquisarCaixa(id))
        cout << "ERRO: CONTA " << id << " JA EXISTENTE" << endl;
    else {
        CaixaDeEntrada *caixa_de_entrada = new CaixaDeEntrada(id);
        caixas_de_entrada->InserirCaixa(caixa_de_entrada);

        cout << "OK: CONTA " << id << " CADASTRADA" << endl;
    }
}

void ServidorDeEmails::RemoverId(int id) {
    if (!caixas_de_entrada->PesquisarCaixa(id))
        cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
    else {
        while (!caixas_de_entrada->GetCaixa(id)->IsVazia())
            caixas_de_entrada->GetCaixa(id)->LerEmail();

        caixas_de_entrada->RemoverCaixa(id);

        cout << "OK: CONTA " << id << " REMOVIDA" << endl;
    }
}

void ServidorDeEmails::EntregarMensagem(int id, int prioridade, string mensagem) {
    if (!caixas_de_entrada->PesquisarCaixa(id))
        cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
    else {
        Email *novo = new Email(prioridade, mensagem);
        CaixaDeEntrada *caixa_de_entrada = caixas_de_entrada->GetCaixa(id);

        caixa_de_entrada->AdicionarEmail(novo);

        cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
    }
}

void ServidorDeEmails::ConsultarId(int id) {
    if (!caixas_de_entrada->PesquisarCaixa(id))
        cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
    else {
        CaixaDeEntrada *caixa_de_entrada = caixas_de_entrada->GetCaixa(id);

        if (caixa_de_entrada->IsVazia()) {
            cout << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << endl;
        } else {
            string mensagem = caixa_de_entrada->LerEmail();

            cout << "CONSULTA " << id << ": " << mensagem << endl;
        }
    }
}
