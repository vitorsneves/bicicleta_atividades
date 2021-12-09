#include "ValidaValor.hpp"

bool ValidaValor::ehNumero(std::string numero) {
    bool ehNumero;

    try { 
        std::stod(numero); 
        ehNumero = true; 
    } 
    catch(std::exception& ia) { 
        ehNumero = false; 
    } 
    
    return ehNumero;
}

//se for digitado um double, essa função pega somente a parte real
int ValidaValor::recebeInteiro() {
    bool numeroValido = 0;
    std::string numero;

    while(!numeroValido){
        std::cout << "Digite um numero inteiro: ";
        std::cin.clear();
    	std::cin >> numero;

        numeroValido = ehNumero(numero);

        if(!numeroValido)
            std::cout << "Numero invalido." << std::endl;
    }

    return std::stod(numero);
}

double ValidaValor::recebeDouble() {
    bool numeroValido = 0;
    std::string numero;

    while(!numeroValido){
        std::cout << "Digite um numero real: ";
        std::cin.clear();
    	std::cin >> numero;

        numeroValido = ehNumero(numero);

        if(!numeroValido)
            std::cout << "Numero invalido." << std::endl;
    }

    return std::stod(numero);
}