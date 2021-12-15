#pragma once

#include <iostream>
#include "Questao03.hpp"

class Questao04 {

    public:
        // Implementacao da questao 4 - calcula salario de professor.
        static void abrir() {
            std::cout << "\nDigite o valor da hora/aula -> ";
            double salarioHora;
            std::cin >> salarioHora;
            
            std::cout << "Numero de aulas dadas -> ";
            int numAulas;
            std::cin >> numAulas;

            std::cout << "Percentual do INSS -> ";
            int percenINSS;
            std::cin >> percenINSS;

            // Calcula salario e aplica o desconto do INSS.
            double salario = Questao03::aplicarDesconto((numAulas * salarioHora), percenINSS);

            // Printa resultado.
            std::cout << "\nSalario -> " << salario << std::endl;
        }
        
};
