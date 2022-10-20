#include "CaixaDeEntrada.hpp"

CaixaDeEntrada::CaixaDeEntrada(int id) {
    this->id = id;
    this->lista_de_emails = new ListaDeEmails();
    this->proximo = nullptr;
}

CaixaDeEntrada::~CaixaDeEntrada() {
    lista_de_emails->Limpar();

    delete lista_de_emails;
}

bool CaixaDeEntrada::IsVazia() {
    return lista_de_emails->IsVazia();
}

int CaixaDeEntrada::GetId() {
    return id;
}

void CaixaDeEntrada::AdicionarEmail(Email *email) {
    lista_de_emails->InserirEmailOrdenado(email);
}

string CaixaDeEntrada::LerEmail() {
    string mensagem = lista_de_emails->RemoverEmailInicio();

    return mensagem;
}
