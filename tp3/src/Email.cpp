#include "Email.hpp"

Email::Email(int id_email, int id_destinatario, string mensagem) {
    this->id_email = id_email;
    this->id_destinatario = id_destinatario;
    this->mensagem = mensagem;
    esquerda = nullptr;
    direita = nullptr;
}

int Email::GetIdEmail() {
    return id_email;
}

int Email::GetIdDestinatario() {
    return id_destinatario;
}

string Email::GetMensagem() {
    return mensagem;
}