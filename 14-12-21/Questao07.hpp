#pragma once

#include <iostream>

class Questao07 {

    public:
        // Implementacao da questao 07 - soma dois numeros
        static void abrir() {
            // Recebe dados do usuario.
            double num1, num2, soma = 0;
            std::cout << "Digite dois numeros." << std::endl;
            std::cin >> num1 >> num2;

            soma = num1 + num2;

            std::cout << "\n(" << num1 << " + " << num2 << ")";

            // Caso soma maior que 20, acrescenta-se 8.
            // Caso contrario, subtrai-se 5.
            if(soma > 20) {
                std::cout << " + 20";
                soma += 20;
            } else {
                std::cout << " - 5";
                soma -= 5;
            }

            std::cout << " = " << soma << std::endl;
        }

};
