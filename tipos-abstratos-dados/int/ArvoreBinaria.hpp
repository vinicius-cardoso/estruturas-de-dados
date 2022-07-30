#include <iostream>

#define PRE_ORDEM 1
#define IN_ORDEM 2
#define POS_ORDEM 3

using namespace std;

class No {
   private:
    int item;
    No *esquerda;
    No *direita;

   public:
    No(int item);

    friend class ArvoreBinaria;
};

class ArvoreBinaria {
   private:
    No *raiz;
    int tamanho;

    void InserirRecursivo(No *&p, int item);
    void RemoverRecursivo(No *p);
    bool ApagarRecursivo(No *&p, int chave);
    int PesquisarRecursivo(No *&p, int chave);
    void PreOrdem(No *p);
    void InOrdem(No *p);
    void PosOrdem(No *p);

   public:
    ArvoreBinaria();
    ~ArvoreBinaria();

    bool IsVazia();
    void Inserir(int item);
    bool Apagar(int chave);
    int Pesquisar(int chave);
    void Caminhar(int tipo);
    void Limpar();
};