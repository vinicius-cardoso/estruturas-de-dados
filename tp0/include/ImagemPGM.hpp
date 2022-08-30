#ifndef IMAGEM_PGM
#define IMAGEM_PGM

class ImagemPGM {
   private:
    int largura;
    int altura;
    int *valores;

   public:
    ImagemPGM(int largura, int altura);
    ~ImagemPGM();

    int GetLargura();
    int GetAltura();

    void SetValores(int *valores);
    int *GetValores();
};

#endif