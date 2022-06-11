/*
-------------------------------------
Algoritmo de Ordenacao: QuickSort
-------------------------------------
Complexidade Temporal:
- Pior caso:	O(n^2)
- Melhor caso:	O(n log(n))
- Caso médio:	O(n log(n))

Complexidade Espacial:
- O(log(n))

Aplicações:
- Quando nao importa a complexidade
- Quando se deseja um codigo simples

Vantagens:
- Extremamente eficiente
- Necessita de apenas uma pequena pilha como memoria auxiliar
- Numero logaritmico de comparacoes

Desvantagens:
- Tem pior caso O(n^2) quando o pivo nao e bem escolhido
- Implementacao delicada
- Nao estavel

-------------------------------------
*/

#include <iostream>

using namespace std;

template <typename T>
void Swap(T *i, T *j) {
    T temp = *i;
    *i = *j;
    *j = temp;
}

template <typename T>
void PrintArray(T *arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

template <typename T>
int Partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            Swap(&arr[i], &arr[j]);
        }
    }

    Swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

template <typename T>
void QuickSort(T arr[], int low, int high) {
    if (low < high) {
        // pi = partition index
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    // int int_arr[] = {5, 4, 3, 2, 1};
    // int int_n = sizeof(int_arr) / sizeof(int);

    char char_arr[] = {'E', 'D', 'C', 'B', 'A'};
    int char_n = sizeof(char_arr) / sizeof(char);

    cout << "QuickSort: " << endl;
    QuickSort(char_arr, 0, char_n - 1);
    PrintArray(char_arr, char_n);

    return 0;
}