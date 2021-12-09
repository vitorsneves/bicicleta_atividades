#include <iostream>
#include "Fatorial.hpp"
#include "ValidaValor.hpp"

int Fatorial::calculaFatorial() {

    std::cout << "Quer calcular o fatorial de que numero?\n" << std::endl;

    valorRecebido = ValidaValor::recebeInteiro();

    if(valorRecebido < 0) {
        std::cout << "Nao eh possivel calcular fatorial de valor negativo" << std::endl;
        return 0;
    }

    resultado = fatorial(valorRecebido);

    std::cout << valorRecebido << "! = " << resultado << std::endl;

    return resultado;

}


int Fatorial::fatorial(int numero) {

    if(numero == 0) 
        return 1;

    return numero * fatorial(numero - 1);

}