#include "ImagemPPM.hpp"

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