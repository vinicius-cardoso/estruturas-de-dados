#include "Ordenador.hpp"

void Ordenador::Swap(Palavra *i, Palavra *j) {
    Palavra temp = *i;
    *i = *j;
    *j = temp;
}

// void Ordenador::InsertionSort(Palavra *arr, int n) {
//     Palavra temp;
//     int i, j;

//     for (int i = 1; i < n; ++i) {
//         temp = arr[i];
//         j = i - 1;

//         while (j >= 0 && arr[j] > temp) {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }

//         arr[j + 1] = temp;
//     }
// }

// void Ordenador::SelectionSort(Palavra *arr, int n) {
//     int i, j, min_idx;

//     for (i = 0; i < n - 1; i++) {
//         min_idx = i;

//         for (j = i + 1; j < n; j++)
//             if (arr[j] < arr[min_idx])
//                 min_idx = j;

//         Swap(&arr[min_idx], &arr[i]);
//     }
// }

Palavra Ordenador::MedianaTres(Palavra a, Palavra b, Palavra c, bool por_palavra) {
    int indice_mediana;

    if (por_palavra) {
        // (a < b and b < c) ou (c < b and b < a)
        if ((b.PalavraMaiorQue(&a) && c.PalavraMaiorQue(&b)) || (b.PalavraMaiorQue(&c) && a.PalavraMaiorQue(&b))) {
            return b;
        }
        // (b < a and a < c) ou (c < a and a < b)
        else if ((a.PalavraMaiorQue(&b) && c.PalavraMaiorQue(&a)) || (a.PalavraMaiorQue(&c) && b.PalavraMaiorQue(&a))) {
            return a;
        } else {
            return c;
        }
    } else {
        // (a < b and b < c) ou (c < b and b < a)
        if ((b.FrequenciaMaiorQue(&a) && c.FrequenciaMaiorQue(&b)) || (b.FrequenciaMaiorQue(&c) && a.FrequenciaMaiorQue(&b))) {
            return b;
        }
        // (b < a and a < c) ou (c < a and a < b)
        else if ((a.FrequenciaMaiorQue(&b) && c.FrequenciaMaiorQue(&a)) || (a.FrequenciaMaiorQue(&c) && b.FrequenciaMaiorQue(&a))) {
            return a;
        } else {
            return c;
        }
    }
}

int Ordenador::Partition(Palavra arr[], int inicio, int fim, bool por_palavra) {
    int indice = inicio - 1;
    int meio = (inicio + fim) / 2;

    Palavra mediana;
    Palavra pivo = arr[fim];
    Palavra a = arr[inicio], b = arr[meio], c = arr[fim];

    mediana = MedianaTres(a, b, c, por_palavra);

    Swap(&mediana, &arr[fim]);

    if (por_palavra) {
        for (int i = inicio; i <= fim; i++) {
            if (arr[i].GetPalavra() < pivo.GetPalavra()) {
                indice++;

                Swap(&arr[indice], &arr[i]);
            }
        }
    } else {
        for (int i = inicio; i <= fim; i++) {
            if (arr[i].GetFrequencia() < pivo.GetFrequencia()) {
                indice++;

                Swap(&arr[indice], &arr[i]);
            }
        }
    }

    Swap(&arr[indice + 1], &arr[fim]);

    return indice + 1;
}

void Ordenador::OrdenarPorPalavra(Palavra *arr, int inicio, int fim) {
    bool por_palavra = true;

    if (inicio < fim) {
        // ip = indice da particao
        int ip = Partition(arr, inicio, fim, por_palavra);

        OrdenarPorPalavra(arr, inicio, ip - 1);
        OrdenarPorPalavra(arr, ip + 1, fim);
    }
}

void Ordenador::OrdenarPorFrequencia(Palavra *arr, int inicio, int fim) {
    bool por_palavra = false;

    if (inicio < fim) {
        // ip = indice da particao
        int ip = Partition(arr, inicio, fim, por_palavra);

        OrdenarPorFrequencia(arr, inicio, ip - 1);
        OrdenarPorFrequencia(arr, ip + 1, fim);
    }
}

void Ordenador::PrintArray(Palavra *arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i].GetPalavra() << " ";

    cout << endl;
}