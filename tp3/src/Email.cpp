#include "Email.hpp"

Email::Email(int id, string mensagem) {
    this->id = id;
    this->mensagem = mensagem;
    esquerda = nullptr;
    direita = nullptr;
    proximo = nullptr;
}

int Email::GetId() {
    return id;
}