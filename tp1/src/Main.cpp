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

    int numero_de_rodadas, dinheiro_inicial;
    int numero_de_jogadores, valor_do_pingo, valor_aposta;
    string nome_jogador, jogada, carta;

    ifstream arquivo("entrada.txt");

    arquivo >> numero_de_rodadas >> dinheiro_inicial;

    for (int i = 0; i < numero_de_rodadas; i++) {
        arquivo >> numero_de_jogadores >> valor_do_pingo;

        for (int j = 0; j < numero_de_jogadores; j++) {
            arquivo >> nome_jogador >> valor_aposta;

            Jogador *jogador = new Jogador(nome_jogador, dinheiro_inicial, valor_aposta);
            jogadores.Inserir(Jogador(*jogador));

            for (int k = 0; k < 5; k++) {
                arquivo >> carta;

                jogadores.GetItem(j)->AdicionarCarta(carta);
            }

            Lista<Carta> *mao = new Lista<Carta>();

            *mao = jogadores.GetItem(j)->GetMao();

            cout << "Tamanho: " << mao->GetTamanho() << endl;
            // jogadores.GetItem(j)->Imprimir();

            // jogada = AvaliarMao(mao);

            // cout << endl;
        }
    }

    return 0;
}