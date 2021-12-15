#pragma once

#include <iostream>

class Questao11 {

    public:
        static void abrir() {
            std::cout << "\nNumeros de 100 a 0:\n" << std::endl;

            //printa contagem regressiva
            contagemRegressiva(100, 1);
        }

        // Printa uma sequencia degressiva de numeros.
        // O decremeto precisa ser positivo.
        static void contagemRegressiva(int valorInicial, int decremento) {
            // Para de printar quando chegar a um numero negativo.
            if(valorInicial < 0 || decremento < 0) {
                return;
            }

            std::cout << valorInicial << std::endl;
            contagemRegressiva(valorInicial - decremento, decremento);
        }
};