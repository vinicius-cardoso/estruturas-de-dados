#include <fstream>
#include <iostream>

#include "Jogador.hpp"

using namespace std;

int main() {
    int numero_de_rodadas, dinheiro_inicial;
    int numero_de_jogadores, valor_do_pingo, valor_aposta;
    string nome_jogador, jogada, carta;
    Jogador *jogadores;

    ifstream arquivo("entrada2.txt");

    arquivo >> numero_de_rodadas >> dinheiro_inicial;

    for (int i = 0; i < numero_de_rodadas; i++) {
        arquivo >> numero_de_jogadores >> valor_do_pingo;

        for (int j = 0; j < numero_de_jogadores; j++) {
            arquivo >> nome_jogador >> valor_aposta;

            jogadores = new Jogador[numero_de_jogadores + 1];

            for (int k = 0; k < 5; k++) {
                arquivo >> carta;

                jogadores[j].AdicionarCarta(carta);
            }

            cout << "Jogador " << j << ": ";
            cout << jogadores[j].GetMao() << endl;

            jogadores[j].ImprimirMao();
        }
    }

    return 0;
}