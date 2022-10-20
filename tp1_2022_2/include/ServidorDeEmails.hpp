#ifndef SERVIDOR_DE_EMAILS
#define SERVIDOR_DE_EMAILS

#include "ListaDeCaixas.hpp"

class ServidorDeEmails {
   private:
    ListaDeCaixas *caixas_de_entrada;

   public:
    ServidorDeEmails();
    ~ServidorDeEmails();

    void CadastrarId(int id);
    void RemoverId(int id);
    void EntregarMensagem(int id, int prioridade, string mensagem);
    void ConsultarId(int id);
};

#endif
