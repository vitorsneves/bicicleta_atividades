#include "Carro.hpp"
#include "ValidaValor.hpp"

double Carro::minutosParaSegundos(double minutos) {
    return minutos * 60.0;
}

double Carro::recebeDistancia() {

    std::cout << "Digite a distancia percorrida pelo carro.\n" << std::endl;
    this->distancia = ValidaValor::recebeDouble();

}

double Carro::recebeTempo() {

    std::cout << "Digite o tempo (em minutos) para percorrer essa distancia.\n" << std::endl;
    this->tempo = Carro::minutosParaSegundos(ValidaValor::recebeDouble());

}

void Carro::recebeDados() {
    recebeDistancia();
    recebeTempo();
}

double Carro::calculaVelocidade() {
    this->velocidadeMedia = this->distancia / this->tempo;

    return this->velocidadeMedia;
}