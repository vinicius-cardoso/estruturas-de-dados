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
    void QuickSort(T *arr, int low, int high);
    void PrintArray(T *arr, int n);

   private:
    void Swap(T *i, T *j);
    int Partition(T arr[], int low, int high);
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

template <typename T>
int Ordenador<T>::Partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            Swap(&arr[i], &arr[j]);
        }
    }

    Swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

template <typename T>
void Ordenador<T>::QuickSort(T *arr, int low, int high) {
    if (low < high) {
        // pi = partition index
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

#endif