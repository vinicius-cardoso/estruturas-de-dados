#include <fstream>
#include <iostream>

#define CODIGO_PGM "P2"
#define CODIGO_PPM "P3"

const float VALOR_MAX_COR = 255;
const float VALOR_MAX_CINZA = 49;

using namespace std;

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

ImagemPPM::ImagemPPM(int largura, int altura) {
    this->largura = largura;
    this->altura = altura;
}

int ImagemPPM::GetLargura() {
    return this->largura;
}

int ImagemPPM::GetAltura() {
    return this->altura;
}

void ImagemPPM::SetValores(int *valores_R, int *valores_G, int *valores_B) {
    this->valores_R = valores_R;
    this->valores_G = valores_G;
    this->valores_B = valores_B;
}

int *ImagemPPM::GetValoresR() {
    return this->valores_R;
}

int *ImagemPPM::GetValoresG() {
    return this->valores_G;
}

int *ImagemPPM::GetValoresB() {
    return this->valores_B;
}

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

ImagemPGM::ImagemPGM(int largura, int altura) {
    this->largura = largura;
    this->altura = altura;
}

int ImagemPGM::GetLargura() {
    return this->largura;
}

int ImagemPGM::GetAltura() {
    return this->altura;
}

void ImagemPGM::SetValores(int *valores) {
    this->valores = valores;
}

int *ImagemPGM::GetValores() {
    return this->valores;
}

ImagemPPM *LerImagemPPM(string nome_arq_entrada) {
    ifstream arq_entrada(nome_arq_entrada);

    string aux;
    int largura, altura;

    arq_entrada >> aux;
    arq_entrada >> largura >> altura;
    arq_entrada >> aux;

    ImagemPPM *imagem_ppm = new ImagemPPM(largura, altura);

    int *valores_R = new int[largura * altura];
    int *valores_G = new int[largura * altura];
    int *valores_B = new int[largura * altura];

    int indice = 0;
    int R, G, B;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            arq_entrada >> R >> G >> B;

            valores_R[indice] = R;
            valores_G[indice] = G;
            valores_B[indice] = B;

            indice++;
        }
    }

    imagem_ppm->SetValores(valores_R, valores_G, valores_B);

    return imagem_ppm;
}

void ConverterPPMparaPGM(ImagemPPM *imagem_ppm, string nome_arq_saida) {
    ofstream arq_saida(nome_arq_saida, ios::trunc);

    int largura = imagem_ppm->GetLargura();
    int altura = imagem_ppm->GetAltura();

    ImagemPGM *imagem_pgm = new ImagemPGM(largura, altura);

    int *valores_R = imagem_ppm->GetValoresR();
    int *valores_G = imagem_ppm->GetValoresG();
    int *valores_B = imagem_ppm->GetValoresB();

    int *valores = new int[largura * altura];

    arq_saida << CODIGO_PGM << endl;
    arq_saida << largura << " " << altura << endl;
    arq_saida << VALOR_MAX_CINZA << endl;

    int indice = 0;

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            valores[indice] = (VALOR_MAX_CINZA / VALOR_MAX_COR) * (0.3 * valores_R[indice] + 0.59 * valores_G[indice] + 0.11 * valores_B[indice]);

            arq_saida << valores[indice];

            if (j < largura - 1) arq_saida << " ";

            indice++;
        }

        arq_saida << endl;
    }
}

int main() {
    string nome_arq_entrada = "sample/mineirao.ppm";
    string nome_arq_saida = "output/mineirao.pgm";

    ImagemPPM *imagem_ppm = LerImagemPPM(nome_arq_entrada);
    ConverterPPMparaPGM(imagem_ppm, nome_arq_saida);

    return 0;
}