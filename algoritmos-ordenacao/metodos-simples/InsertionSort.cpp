/*
-------------------------------------
Algoritmo de Ordenacao: InsertionSort
-------------------------------------
Complexidade Temporal:
- Pior caso:    O(n^2)
- Melhor caso:  O(n)
- Caso médio:   O(n^2)

Complexidade Espacial:
- O(1)

Aplicações:
- Arquivos pequenos
-

Vantagens:
- Estavel
- Melhor que o bolha

Desvantagens:
-
-------------------------------------
*/

#include <iostream>

using namespace std;

template <typename T>
void InsertionSort(T arr[], int n) {
    T temp;
    int i, j;

    for (int i = 1; i < n; ++i) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}

template <typename T>
void PrintArray(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main() {
    int int_arr[] = {1, 4, 2, 5, 3};
    int int_n = sizeof(int_arr) / sizeof(int);

    cout << "Int array before insertion sort: " << endl;
    PrintArray(int_arr, int_n);

    InsertionSort(int_arr, int_n);

    cout << "Int array after insertion sort: " << endl;
    PrintArray(int_arr, int_n);

    cout << endl;

    char char_arr[] = {'A', 'D', 'B', 'E', 'C'};
    int char_n = sizeof(char_arr) / sizeof(char);

    cout << "Char array before insertion sort:" << endl;
    PrintArray(char_arr, char_n);

    InsertionSort(char_arr, char_n);

    cout << "Char array after insertion sort:" << endl;
    PrintArray(char_arr, char_n);

    cout << endl;

    return 0;
}