#include <iostream>
#include "manipulaVetor.hpp"

manipulaVetor::manipulaVetor(int tamanho)
    : tamanho(tamanho) {
    // Aloca espaco do tamanho desejado.
    vetor = (double*) calloc(tamanho * sizeof(double), tamanho);
}

manipulaVetor::~manipulaVetor() {
    // Libera o espaco que foi alocado no construtor.
    free(vetor);
}

void manipulaVetor::recebeVetor() {

    std::cout << "Digite " << tamanho << " numeros reais:\n";

    // Pede para o usuario preencher o vetor com a quantidade
    // de numeros reais definida no construtor.
    for(int i = 0; i < tamanho; i++)
        std::cin >> vetor[i];
    
}

void manipulaVetor::colocarEmOrdem() {
    double auxiliar;

    // Coloca em ordem crescente.
    for(int i = 0; i < tamanho - 1; i++)
        for(int j = i + 1; j < tamanho; j++)

            if(vetor[i] > vetor[j]) {
                // Troca os dois valores de lugar.
                auxiliar = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = auxiliar;
            }
}

void manipulaVetor::imprimeVetor() {
    // Primeiro colchete.
    std::cout << "[";

    // Printa todos os valores ate penultimo.
    for(int i = 0; i <= tamanho - 2; i++)
        std::cout << vetor[i] << ", ";

    // Printa penultimo valor.
    std::cout << vetor[tamanho - 1] << "]\n";
}