#include "Ordenador.hpp"

using namespace std;

int main() {
    Ordenador<int> *ordenador_int = new Ordenador<int>();
    Ordenador<char> *ordenador_char = new Ordenador<char>();

    int int_n;

    cout << "Numero de elementos: " << endl;
    cin >> int_n;

    int *int_arr = new int[int_n]();

    for (int i = 0; i < int_n; i++) {
        cin >> int_arr[i];
    }

    cout << endl;

    char char_arr[] = {'E', 'D', 'C', 'B', 'A'};
    int char_n = sizeof(char_arr) / sizeof(char);

    cout << "BubbleSort: " << endl;
    // cout << "InsertionSort: " << endl;
    // cout << "SelectionSort: " << endl;

    ordenador_int->BubbleSort(int_arr, int_n);
    // ordenador_int->InsertionSort(int_arr, int_n);
    // ordenador_int->SelectionSort(int_arr, int_n);
    ordenador_int->PrintArray(int_arr, int_n);

    ordenador_char->BubbleSort(char_arr, char_n);
    // ordenador_char->InsertionSort(char_arr, char_n);
    // ordenador_char->SelectionSort(char_arr, char_n);
    ordenador_char->PrintArray(char_arr, char_n);

    return 0;
}