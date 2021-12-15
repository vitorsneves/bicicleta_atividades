#include <iostream>
#include "Questao13.hpp"

RETRI::RETRI()
    : baseTriangu(0),
      alturaTriangu(0),
      ladoMaiorReta(0),
      ladoMenorReta(0) {
          
    areaTriangu = 0;
    areaReta = 0;
}

RETRI::RETRI(double baseTriangu, double alturaTriangu, double ladoMaiorReta, double ladoMenorReta)
    : baseTriangu(baseTriangu),
      alturaTriangu(alturaTriangu),
      ladoMaiorReta(ladoMaiorReta),
      ladoMenorReta(ladoMenorReta) {

    // Inicializa as areas dos dois poligonos.
    calcularAreaReta();
    calcularAreaTriangu();
}


//---------------------------------- Triangulo ----------------------------------

double RETRI::setTriangu(double baseTriangu, double alturaTriangu) {

    this->baseTriangu = baseTriangu;
    this->alturaTriangu = alturaTriangu;

    // Atualiza a area do triangulo com os valores novos.
    calcularAreaTriangu();

    return areaTriangu;
}

double RETRI::getAreaTriangu() {
    return areaTriangu;
}

void RETRI::calcularAreaTriangu() {
    areaTriangu = (baseTriangu * alturaTriangu) / 2.0;
}


//---------------------------------- Retangulo ----------------------------------

double RETRI::setRetangulo(double ladoMenorReta, double ladoMaiorReta) {

    this->ladoMenorReta = ladoMenorReta;
    this->ladoMaiorReta = ladoMaiorReta;

    // Atualiza a area do retangulo com os valores novos.
    calcularAreaReta();

    return areaReta;
}

double RETRI::getAreaRetangulo() {
    return areaReta;
}

void RETRI::calcularAreaReta() {
    this->areaReta = this->ladoMaiorReta * this->ladoMenorReta;
}
