/*
-------------------------------------
Algoritmo de Ordenacao: SelectionSort
-------------------------------------
Complexidade Temporal:
- Pior caso:	O(n^2)
- Melhor caso:	O(n^2)
- Caso médio:	O(n^2)

Complexidade Espacial:
- O(1)

Vantagens:
- Custo linear nas movimentacoes O(n)

Desvantagens:
- Nao adaptavel
- Nao estavel

Aplicações:
- Arquivos com poucos elementos que sejam muito grandes
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
void SelectionSort(T arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        Swap(&arr[min_idx], &arr[i]);
    }
}

template <typename T>
void PrintArray(T arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int int_arr[] = {2, 1, 5, 4, 3};
    int int_n = sizeof(int_arr) / sizeof(int_arr[0]);

    cout << "Int array before selection sort: " << endl;
    PrintArray(int_arr, int_n);

    SelectionSort(int_arr, int_n);

    cout << "Int array after selection sort: " << endl;
    PrintArray(int_arr, int_n);

    cout << endl;

    char char_arr[] = {'B', 'A', 'E', 'D', 'C'};
    int char_n = sizeof(char_arr) / sizeof(char_arr[0]);

    cout << "Char array before selection sort: " << endl;
    PrintArray(char_arr, char_n);

    SelectionSort(char_arr, char_n);

    cout << "Char array after selection sort: " << endl;
    PrintArray(char_arr, char_n);

    return 0;
}