#pragma once 

#include <iostream>

class Questao05 {

    public:
        // Converte temperatura de graus Celsius para Fahrenheit.
        static double celsiusParaFahrenheit(double tempeCelsius) {
            double tempeFahren;
            tempeFahren = (9.0 * tempeCelsius + 160.0) / 5.0;
            return tempeFahren;
        }

        // Implementacao da questao 05 - conversao de celsius para fahrenheit.
        static void abrir() {
            std::cout << "Digite a temperatura em graus celsius -> ";
            double tempeCelsius;
            std::cin >> tempeCelsius;;

            // Exibe resuldado da conversao.
            double tempeFahren = celsiusParaFahrenheit(tempeCelsius);
            std::cout << "\n" << tempeCelsius << "C convertido para Fahrenheit fica " 
                      << tempeFahren << "F" << std::endl;
        }

};
