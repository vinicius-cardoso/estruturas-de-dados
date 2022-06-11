#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <iostream>

using namespace std;

template <typename T>
class Ordenador;

template <typename T>
class Ordenador {
   public:
    void BubbleSort(T *arr, int n);
    void InsertionSort(T *arr, int n);
    void SelectionSort(T *arr, int n);
    void PrintArray(T *arr, int n);
    void Swap(T *i, T *j);
};

template <typename T>
void Ordenador<T>::Swap(T *i, T *j) {
    T temp = *i;
    *i = *j;
    *j = temp;
}

template <typename T>
void Ordenador<T>::PrintArray(T *arr, int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

template <typename T>
void Ordenador<T>::BubbleSort(T *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
}

template <typename T>
void Ordenador<T>::InsertionSort(T *arr, int n) {
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
void Ordenador<T>::SelectionSort(T *arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        Swap(&arr[min_idx], &arr[i]);
    }
}

#endif