#pragma once

#include <iostream>
#include <cmath>

class Questao02 {

    public:

        // Retorna a hipotenusa do triangulo retangulo.
        static double obterHipotenusa(double cateto1, double cateto2) {
            double hipotenusa;
            hipotenusa = std::sqrt(cateto1 * cateto1 + cateto2 * cateto2);
            return hipotenusa;
        }

        // Implementacao da questao02 - encontra hipotenusa do triangulo retangulo.
        static void abrir() {
            std::cout << "\nDigite o valor dos dois catetos." << std::endl;
            
            // Le dados digitados.
            double catetos[2];
            std::cin >> catetos[0];
            std::cin >> catetos[1];

            double hipotenusa = obterHipotenusa(catetos[0], catetos[1]);
            std::cout << "\nA hipotenusa desse triangulo eh igual a " << hipotenusa << std::endl;
        }
        
};
