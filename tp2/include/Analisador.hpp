#ifndef ANALISADOR_H
#define ANALISADOR_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "msgassert.hpp"

using namespace std;

class Analisador {
   public:
    Analisador();
    void Analisar(string nome_arq_entrada);
};

#endif