#include "Mesa.hpp"

#include "msgassert.hpp"

Mesa::Mesa() {
    this->invalida = false;
}

int *Mesa::GetVencedores(Jogador *jogadores, int numero_total_jogadores) {
    int nr_jogadores = numero_total_jogadores;
    int maior = 1, indice = nr_jogadores - 1;
    int indice_aux = 0;

    int *indices_empatados = new int[nr_jogadores];

    for (int i = 0; i < 5; i++) {
        if (jogadores[i].GetValorMao() != 0) {
            // armazena em indice o indice do jogador com a maior mao
            if (jogadores[i].GetValorMao() > maior) {
                maior = jogadores[i].GetValorMao();
                indice = i;
                indices_empatados[indice_aux] = indice;
                indice_aux++;
                // se ha 2 jogadores com valor da mao igual, realiza o desempate
            } else if (jogadores[i].GetValorMao() == maior) {
                // desempate a partir da maior carta
                if (jogadores[i].GetMao()[1] > jogadores[indice].GetMao()[1]) {
                    indice = i;
                    // impossivel desempatar
                } else {
                    indice = i;
                    indices_empatados[indice_aux] = indice;
                    indice_aux++;
                }
            }
        }
    }

    return indices_empatados;
}

int Mesa::GetVencedor(Jogador *jogadores, int numero_total_jogadores) {
    int nr_jogadores = numero_total_jogadores;
    int maior = 1, indice = nr_jogadores - 1;
    int indice_aux = 0;

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

    return indice;
}

int Mesa::GetNrVencedores(Jogador *jogadores, int numero_total_jogadores) {
    int nr_jogadores = numero_total_jogadores;
    int maior = 0, indice = nr_jogadores - 1;
    int nr_vencedores = 1;

    for (int i = 0; i < nr_jogadores; i++) {
        if (jogadores[i].GetValorMao() != 0) {
            // armazena o indice do jogador com a maior mao
            if (jogadores[i].GetValorMao() > maior) {
                maior = jogadores[i].GetValorMao();
                indice = i;
                nr_vencedores = 1;
                // se ha 2 jogadores com valor da mao igual, realiza o desempate
            } else if (jogadores[i].GetValorMao() == maior) {
                // desempate a partir da maior carta
                if (jogadores[i].GetValorMao() > jogadores[indice].GetValorMao()) {
                    indice = i;
                    // impossivel desempatar
                } else {
                    nr_vencedores++;
                }
            }
        }
    }

    return nr_vencedores;
}

void Mesa::Partida(string nome_arquivo_entrada) {
    int numero_de_rodadas, dinheiro_inicial;
    int numero_de_jogadores, valor_do_pingo;
    int valor_aposta, pote;
    string nome_jogador, jogada, carta;
    string valor_mao;
    string nome_vencedor, jogada_vencedor;
    bool invalida = false;

    ifstream arquivo_entrada(nome_arquivo_entrada);
    erroAssert(!arquivo_entrada.fail(), "Falha ao abrir o arquivo de entrada");

    // abre o arquivo em modo de sobreposicao (trunc)
    ofstream arquivo_saida("saida.txt", ios::trunc);

    arquivo_entrada >> numero_de_rodadas >> dinheiro_inicial;
    arquivo_entrada >> numero_de_jogadores >> valor_do_pingo;

    int numero_total_jogadores = numero_de_jogadores;
    Jogador *jogadores = new Jogador[numero_total_jogadores + 1]();

    for (int i = 0; i < numero_de_rodadas; i++) {
        pote = 0;
        int numero_de_vencedores = 0;

        if (i == 0) {
            for (int j = 0; j < numero_total_jogadores; j++) {
                arquivo_entrada >> nome_jogador >> valor_aposta;

                jogadores[j].SetNome(nome_jogador);
                jogadores[j].SetDinheiro(dinheiro_inicial);

                // se o jogador apostar o que nao tem, a rodada eh invalidade
                invalida = jogadores[j].SetAposta(valor_aposta + valor_do_pingo);

                if (invalida == true) {
                    arquivo_saida << "0 0 I" << endl;
                }

                pote += valor_aposta + valor_do_pingo;

                for (int k = 0; k < 5; k++) {
                    arquivo_entrada >> carta;

                    jogadores[j].AdicionarCarta(carta);
                }

                valor_mao = jogadores[j].GetMao()[0];
                jogadores[j].SetValorMao(valor_mao);
            }
        } else {
            arquivo_entrada >> numero_de_jogadores >> valor_do_pingo;

            int indices_jogadores[numero_de_jogadores];
            int contador = 0;

            for (int j = 0; j < numero_de_jogadores; j++) {
                arquivo_entrada >> nome_jogador >> valor_aposta;

                // em todas as rodadas depois da primeira, e necessario buscar o indice
                // do jogador criado na rodada 0, para assim realizar as operacoes
                for (int jogador = 0; jogador < numero_total_jogadores; jogador++) {
                    if (nome_jogador == jogadores[jogador].GetNome()) {
                        // se o jogador apostar o que nao tem, a rodada eh invalidade
                        invalida = jogadores[jogador].SetAposta(valor_aposta + valor_do_pingo);

                        pote += valor_aposta + valor_do_pingo;

                        for (int k = 0; k < 5; k++) {
                            arquivo_entrada >> carta;

                            jogadores[jogador].AdicionarCarta(carta);
                        }

                        valor_mao = jogadores[jogador].GetMao()[0];
                        jogadores[jogador].SetValorMao(valor_mao);

                        indices_jogadores[contador] = jogador;
                        contador++;
                    }
                }
            }

            for (int m = 0; m < numero_total_jogadores; m++) {
                int vezes = 0;

                for (int n = 0; n < contador; n++) {
                    if (m != indices_jogadores[n]) {
                        vezes++;
                    }
                }

                if (vezes == contador) {
                    jogadores[m].SetAposta(valor_do_pingo);

                    pote += valor_do_pingo;

                    jogadores[m].SetValorMao("NULL");
                }
            }
        }

        for (int l = 0; l < numero_total_jogadores; l++) {
            jogadores[l].LimparMao();
        }

        numero_de_vencedores = GetNrVencedores(jogadores, numero_total_jogadores);

        if (numero_de_vencedores == 1) {
            if (!invalida) {
                int indice_vencedor = GetVencedor(jogadores, numero_total_jogadores);
                nome_vencedor = jogadores[indice_vencedor].GetNome();
                jogada_vencedor = jogadores[indice_vencedor].GetMao()[0];
                jogadores[indice_vencedor].Premiar(pote);

                arquivo_saida << numero_de_vencedores << " " << pote << " " << jogada_vencedor << endl;
                arquivo_saida << nome_vencedor << endl;
            }
        } else {
            if (!invalida) {
                int *indices_vencedores = GetVencedores(jogadores, numero_total_jogadores);
                jogada_vencedor = jogadores[indices_vencedores[0]].GetMao()[0];

                arquivo_saida << numero_de_vencedores << " " << pote << " " << jogada_vencedor << " " << endl;

                int premio = pote / numero_de_vencedores;

                for (int i = 0; i < numero_total_jogadores; i++) {
                    for (int j = 0; j < numero_de_vencedores; j++) {
                        if (i == indices_vencedores[j]) {
                            arquivo_saida << jogadores[i].GetNome() << " ";
                            jogadores[i].Premiar(premio);
                        }
                    }
                }

                delete[] indices_vencedores;
            }

            arquivo_saida << endl;
        }

        // ultima rodada
        if (i == numero_de_rodadas - 1) {
            arquivo_saida << "####" << endl;

            int saldos[numero_total_jogadores];
            string nomes[numero_total_jogadores];

            for (int i = 0; i < numero_total_jogadores; i++) {
                saldos[i] = jogadores[i].GetDinheiro();
                nomes[i] = jogadores[i].GetNome();
            }

            for (int i = 0; i < numero_total_jogadores - 1; i++) {
                for (int j = 0; j < numero_total_jogadores - i - 1; j++) {
                    if (saldos[j] > saldos[j + 1]) {
                        int int_aux = saldos[j];
                        string string_aux = jogadores[j].GetNome();

                        saldos[j] = saldos[j + 1];
                        nomes[j] = nomes[j + 1];

                        saldos[j + 1] = int_aux;
                        nomes[j + 1] = string_aux;
                    }
                }
            }

            for (int j = numero_total_jogadores - 1; j >= 0; j--) {
                arquivo_saida << nomes[j] << " " << saldos[j] << endl;
            }
        }
    }

    arquivo_entrada.close();
    arquivo_saida.close();
}
