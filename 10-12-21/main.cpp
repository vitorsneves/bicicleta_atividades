#include <iostream>
#include "manipulaVetor.hpp"
#define TAMANHO_VETOR 5

int main() {
    system("clear || cls");

    manipulaVetor ordenador(TAMANHO_VETOR);

    ordenador.recebeVetor();

    // Printa o vetor com os dados digitados.
    std::cout << "VETOR DIGITADO -> ";
    ordenador.imprimeVetor();

    ordenador.colocarEmOrdem();

    // Printa o vetor com os dados digitados
    // em ordem crescente.
    std::cout << "VETOR ORDENADO -> ";
    ordenador.imprimeVetor();

    // Pausa no console.
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
} 