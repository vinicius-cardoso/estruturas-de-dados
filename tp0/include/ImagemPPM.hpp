#ifndef IMAGEM_PPM
#define IMAGEM_PPM

class ImagemPPM {
   private:
    int largura;
    int altura;
    int *valores_R;
    int *valores_G;
    int *valores_B;

   public:
    ImagemPPM(int largura, int altura);
    ~ImagemPPM();

    int GetLargura();
    int GetAltura();

    void SetValores(int *valores_R, int *valores_G, int *valores_B);
    int *GetValoresR();
    int *GetValoresG();
    int *GetValoresB();
};

#endif