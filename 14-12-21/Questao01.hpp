#pragma once

#include <iostream>

class Questao01 {

    public:
    
        // Calcula media aritmetica de 3 numeros.
        static double mediaAritmetica(const double& num1, const double& num2, const double& num3) {
            double media;
            media = (num1 + num2 + num3) / 3.0;
            return media;
        }

        // Implementacao da questao 1 - encontrar media de 3 numeros fornecidos.
        static void abrir() {
            std::cout << "Digite tres numeros." << std::endl;

            // Coleta tres numeros digitados pelo usuario.
            double numeros[3];
            for(int i = 0; i < 3; i++)
                std::cin >> numeros[i];

            // Calcula media aritmetica.
            double media = mediaAritmetica(numeros[0], numeros[1], numeros[2]);
            
            // Exibe resultado.
            std::cout << "\nMedia aritmetica -> " << media << std::endl;
        }

};
