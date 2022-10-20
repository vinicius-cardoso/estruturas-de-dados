#include "Email.hpp"

Email::Email(int prioridade, string mensagem) {
    this->prioridade = prioridade;
    this->mensagem = mensagem;
    this->proximo = nullptr;
}

Email::~Email() {
    delete proximo;
}

int Email::GetPrioridade() {
    return this->prioridade;
}

string Email::GetMensagem() {
    return this->mensagem;
}
