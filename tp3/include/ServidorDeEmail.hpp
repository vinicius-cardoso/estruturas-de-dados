#ifndef SERVIDOR_DE_EMAIL
#define SERVIDOR_DE_EMAIL

#include <fstream>
#include <iostream>

#include "ArvoreBinaria.hpp"
#include "Email.hpp"

using namespace std;

class ServidorDeEmail {
   private:
    int tamanho_tabela;
    int Hash(int chave);

   public:
    ServidorDeEmail(int tamanho_tabela);

    void Iniciar(ifstream &arquivo_entrada, ofstream &arquivo_saida);
    void Inserir(Email *email, ArvoreBinaria *Tabela, int id_destinatario);
    int Pesquisar(int chave, ArvoreBinaria *Tabela);
    void Entrega(int id_destinatario, int id_email, string mensagem, ArvoreBinaria *Tabela);
    string Consulta(int id_destinatario, int id_email, ArvoreBinaria *Tabela);
    bool Apaga(int id_destinatario, int id_email, ArvoreBinaria *Tabela);
};

#endif