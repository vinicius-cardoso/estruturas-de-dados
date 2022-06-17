#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <iostream>

#include "Palavra.hpp"

using namespace std;

class Ordenador {
   private:
    void Swap(Palavra *i, Palavra *j);
    int Partition(Palavra arr[], int inicio, int fim, bool por_palavra);
    Palavra MedianaTres(Palavra a, Palavra b, Palavra c, bool por_palavra);

   public:
    // void InsertionSort(Palavra *arr, int n);
    // void SelectionSort(Palavra *arr, int n);
    void QuickSort(Palavra *arr, int inicio, int fim);
    void OrdenarPorPalavra(Palavra *arr, int inicio, int fim);
    void OrdenarPorFrequencia(Palavra *arr, int inicio, int fim);
    void PrintArray(Palavra *arr, int n);
};

#endif