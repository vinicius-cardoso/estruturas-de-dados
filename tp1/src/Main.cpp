#include <fstream>
#include <iostream>

#include "Carta.hpp"
#include "Jogador.hpp"
#include "Lista.hpp"

using namespace std;

string AvaliarMao(Lista<Carta> mao) {
    return "RSF";
}

int main() {
    Lista<Jogador> jogadores;

    int numero_de_rodadas;
    int dinheiro_inicial;

    int numero_de_jogadores;
    int valor_do_pingo;

    int pote;

    ifstream arquivo("entrada.txt");

    arquivo >> numero_de_rodadas >> dinheiro_inicial;

    // cout << "Numero de rodadas: " << numero_de_rodadas << endl;
    // cout << "Dinheiro inicial: " << dinheiro_inicial << endl;

    for (int i = 1; i <= numero_de_rodadas; i++) {
        arquivo >> numero_de_jogadores >> valor_do_pingo;

        // cout << "Numero de jogadores: " << numero_de_jogadores << endl;
        // cout << "Valor do pingo: " << valor_do_pingo << endl;

        for (int j = 1; j <= numero_de_jogadores; j++) {
            string nome_jogador;
            int valor_aposta;
            Lista<Carta> mao;
            string jogada;

            arquivo >> nome_jogador >> valor_aposta;

            // cout << "Nome do jogador: " << nome_jogador << endl;
            // cout << "Valor da aposta: " << valor_aposta << endl;

            jogadores.Inserir(Jogador(nome_jogador, dinheiro_inicial, valor_aposta));

            for (int k = 1; k <= 5; k++) {
                string carta;
                arquivo >> carta;

                cout << carta << " ";

                jogadores.GetItem(j)->AdicionarCarta(carta);
            }

            mao = jogadores.GetItem(j)->GetMao();

            jogada = AvaliarMao(mao);

            // cout << endl;
        }
    }

    return 0;
}