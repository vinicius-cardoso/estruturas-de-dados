#include "ImagemPGM.hpp"

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