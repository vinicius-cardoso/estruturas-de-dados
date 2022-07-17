#ifndef SERVIDOR_DE_EMAIL
#define SERVIDOR_DE_EMAIL

#include <fstream>
#include <iostream>
#include <string>

#include "ArvoreBinaria.hpp"
#include "Email.hpp"
#include "msgassert.hpp"

using namespace std;

class ServidorDeEmail {
   private:
    int tamanho_tabela;
    int Hash(int chave);
    // ArvoreBinaria Tabela[5];

   public:
    ServidorDeEmail();

    void Iniciar(string nome_arquivo_entrada, string nome_arquivo_saida);
    void Entrega(int id_destinatario, int id_email, string mensagem, ArvoreBinaria *Tabela);
    void Inserir(Email *email, ArvoreBinaria *Tabela);
    int Pesquisar(int chave, ArvoreBinaria *Tabela);
};

// class Hash_LE {
//    private:
//     int Hash(int chave);
//     ListaEncadeada Tabela[TAM];

//    public:
//     Hash_LE();
//     int Pesquisa(int chave);
//     void Insere(int item);
//     void Remove(int chave);
//     void Imprime();
// }
// ;

// Hash_LE::Hash_LE() {
// }

// int Hash_LE::Hash(int chave) {
//     return chave % TAM;
// }

// int Hash_LE::Pesquisa(int chave) {
//     int item;
//     int pos;

//     pos = Hash(chave);
//     item = Tabela[pos].Pesquisa(chave);

//     return item;
// }

// void Hash_LE::Remove(int chave) {
//     int pos;

//     pos = Hash(chave);

//     Tabela[pos].RemovePosicao(chave);
// }

// void Hash_LE::Imprime() {
//     for (int i = 0; i < TAM; i++) {
//         Tabela[i].Imprime();
//     }
// }

// int main() {
//     Hash_LE hash;

//     for (int i = 0; i < 100; i++) {
//         hash.Insere(i);
//     }

//     hash.Imprime();

//     cout << "-----" << endl;

//     for (int i = 0; i < 14; i++) {
//         hash.Remove(i);
//     }

//     hash.Imprime();

//     return 0;
// }

#endif