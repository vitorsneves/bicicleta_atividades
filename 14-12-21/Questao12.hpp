#pragma once

#include <iostream>
#include <iomanip>

class Questao12 {

    public:
        // Imprime uma tabela de conversao de polegadas para cm.
        static void imprimirTabela() {
            header();

            for(int i = 1; i <= 20; i++) {
                std::cout << "||" << std::setw(7) << i << "      ||";
                std::cout << std::setw(10) << polegadasParaCm(i) <<"     ||" << std::endl;
            }

            footer();
        }

        static double polegadasParaCm(double polegadas) {
            return polegadas * 2.54;
        }

    private:
        static void header() {
            std::cout << "\n==================================" << std::endl;
            std::cout << "||  POLEGADAS  ||  CENTIMETROS  ||" << std::endl;
            std::cout << "==================================" << std::endl;
        }

        static void footer() {
            std::cout << "==================================" << std::endl;

        }

};