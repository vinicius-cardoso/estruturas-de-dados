#include <fstream>
#include <iostream>
#include <typeinfo>

#include "Jogador.hpp"

using namespace std;

Jogador *GetVencedores(Jogador *jogadores, int numero_vencedores) {
    int nr_vencedores = numero_vencedores;
    int maior = 1, indice = nr_vencedores - 1;
    int indice_aux = 0;

    Jogador *empatados = new Jogador[nr_vencedores];

    for (int i = 0; i < nr_vencedores; i++) {
        // armazena em indice o indice do jogador com a maior mao
        if (jogadores[i].GetValorMao() > maior) {
            maior = jogadores[i].GetValorMao();
            indice = i;
            // se ha 2 jogadores com valor da mao igual, realiza o desempate
        } else if (jogadores[i].GetValorMao() == maior) {
            // desempate a partir da maior carta
            if (jogadores[i].GetMao()[1] > jogadores[indice].GetMao()[1]) {
                indice = i;
                // impossivel desempatar
            } else {
                nr_vencedores++;
                empatados[indice_aux] = jogadores[i];
                indice_aux++;
            }
        }
    }

    return empatados;
}

Jogador GetVencedor(Jogador *jogadores, int numero_jogadores) {
    int nr_jogadores = numero_jogadores;
    int maior = 1, indice = nr_jogadores - 1;
    int indice_aux = 0, nr_vencedores = 1;

    for (int i = 0; i < nr_jogadores; i++) {
        // armazena em indice o indice do jogador com a maior mao
        if (jogadores[i].GetValorMao() > maior) {
            maior = jogadores[i].GetValorMao();
            indice = i;
            // se ha 2 jogadores com valor da mao igual, realiza o desempate
        } else if (jogadores[i].GetValorMao() == maior) {
            // desempate a partir da maior carta
            if (jogadores[i].GetMao()[1] > jogadores[indice].GetMao()[1])
                indice = i;
        }
    }

    return jogadores[indice];
}

int GetNrVencedores(Jogador *jogadores, int numero_jogadores) {
    int nr_jogadores = numero_jogadores;
    int maior = 0, indice = nr_jogadores - 1;
    int nr_vencedores = 1;

    for (int i = 0; i < nr_jogadores; i++) {
        // armazena o indice do jogador com a maior mao
        if (jogadores[i].GetValorMao() > maior) {
            maior = jogadores[i].GetValorMao();
            indice = i;
            // se ha 2 jogadores com valor da mao igual, realiza o desempate
        } else if (jogadores[i].GetValorMao() == maior) {
            cout << jogadores[i].GetNome() << endl;
            // desempate a partir da maior carta
            if (jogadores[i].GetMao()[1] > jogadores[indice].GetMao()[1]) {
                indice = i;
                // impossivel desempatar
            } else {
                nr_vencedores++;
            }
        }
    }

    return nr_vencedores;
}

int main() {
    int numero_de_rodadas, dinheiro_inicial;
    int numero_de_jogadores, valor_do_pingo;
    int valor_aposta, pote;
    string nome_jogador, jogada, carta;
    string valor_mao;
    string nome_vencedor, jogada_vencedor;
    bool invalida = false;

    Jogador *jogadores, vencedor, *vencedores;
    jogadores = new Jogador[numero_de_jogadores + 1];
    // vencedores = new Jogador[numero_de_jogadores + 1];

    ifstream arquivo_entrada("entrada.txt");
    ofstream arquivo_saida("saida.txt");

    arquivo_entrada >> numero_de_rodadas >> dinheiro_inicial;

    int numero_total_jogadores = 0;

    for (int i = 0; i < numero_de_rodadas; i++) {
        pote = 0;
        int numero_de_vencedores = 0;

        arquivo_entrada >> numero_de_jogadores >> valor_do_pingo;

        if (i == 0)
            numero_total_jogadores = numero_de_jogadores;

        // jogadores = new Jogador[numero_de_jogadores + 1];
        vencedores = new Jogador[numero_de_jogadores + 1];

        for (int j = 0; j < numero_de_jogadores; j++) {
            arquivo_entrada >> nome_jogador >> valor_aposta;

            jogadores[j].SetNome(nome_jogador);
            jogadores[j].SetDinheiro(dinheiro_inicial);

            // se o jogador apostar o que nao tem, a rodada eh invalidade
            invalida = jogadores[j].SetAposta(valor_aposta + valor_do_pingo);

            // if (invalida == true) {
            //     cout << "0 "
            //          << "0 "
            //          << "I" << endl;
            //     break;
            // }

            pote += valor_aposta + valor_do_pingo;

            for (int k = 0; k < 5; k++) {
                arquivo_entrada >> carta;

                jogadores[j].AdicionarCarta(carta);
            }

            valor_mao = jogadores[j].GetMao()[0];
            // arquivo_saida << valor_mao << endl;
            jogadores[j].SetValorMao(valor_mao);
        }

        numero_de_vencedores = GetNrVencedores(jogadores, numero_de_jogadores);

        if (numero_de_vencedores == 1) {
            vencedor = GetVencedor(jogadores, numero_de_jogadores);

            nome_vencedor = vencedor.GetNome();
            jogada_vencedor = vencedor.GetMao()[0];
            vencedor.Premiar(pote);
            cout << numero_de_vencedores << " " << pote << " " << jogada_vencedor << endl;
            cout << nome_vencedor << endl;
        } else {
            vencedores = GetVencedores(jogadores, numero_de_vencedores);

            cout << numero_de_vencedores << " " << pote << " " << jogada_vencedor << " " << endl;

            int premio = pote / numero_de_vencedores;

            for (int i = 0; i < numero_de_vencedores; i++) {
                cout << vencedores[i].GetNome() << " ";
                vencedores[i].Premiar(premio);
            }
        }

        // toda rodada a mao do jogador sera diferente
        for (int l = 0; l < numero_de_jogadores; l++) {
            jogadores[l].LimparMao();
        }

        // ultima rodada
        if (i == numero_de_rodadas - 1) {
            cout << endl
                 << "####" << endl;

            for (int j = 0; j < numero_total_jogadores; j++) {
                cout << jogadores[j].GetNome() << " " << jogadores[j].GetDinheiro() << endl;
            }
        }
    }

    return 0;
}