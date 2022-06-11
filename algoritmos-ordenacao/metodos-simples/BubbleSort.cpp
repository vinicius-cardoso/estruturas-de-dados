/*
-------------------------------------
Algoritmo de Ordenacao: BubbleSort
-------------------------------------
Complexidade Temporal:
- Pior caso:	O(n^2)
- Melhor caso:	O(n)
- Caso médio:	O(n^2)

Complexidade Espacial:
- O(1)

Aplicações:
- Quando nao importa a complexidade
- Quando se deseja um codigo simples
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
void PrintArray(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

template <typename T>
void BubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
}

int main() {
    int int_arr[] = {1, 4, 2, 5, 3};
    int int_n = sizeof(int_arr) / sizeof(int);

    cout << "Int array before bubble sort: " << endl;
    PrintArray(int_arr, int_n);

    BubbleSort(int_arr, int_n);

    cout << "Int array after bubble sort: " << endl;
    PrintArray(int_arr, int_n);

    cout << endl;

    char char_arr[] = {'A', 'D', 'B', 'E', 'C'};
    int char_n = sizeof(char_arr) / sizeof(char);

    cout << "Char array before bubble sort:" << endl;
    PrintArray(char_arr, char_n);

    BubbleSort(char_arr, char_n);

    cout << "Char array after bubble sort:" << endl;
    PrintArray(char_arr, char_n);

    cout << endl;

    return 0;
}
