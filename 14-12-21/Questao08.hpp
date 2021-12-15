#pragma once

#include <iostream>

class Questao08 {

    public:
        // Implementacao da questao 08 - verifica se numero eh divisivel por 3.
        static void abrir() {
            std::cout << "Digite um numero inteiro." << std::endl;
            int numero;
            std::cin >> numero;

            if(numero % 3 == 0) {
                std::cout << "\nO numero digitado eh multiplo de 3.";
            } else {
                std::cout << "\nO numero digitado nao eh multiplo de 3.";
            }
        }
    
};
