#pragma once

#include <iostream>

class Questao09 {

    public:
        // Implementacao da questao 09 - verifica se eh divisivel por 10, 5 ou 2.
        static void abrir() {
            std::cout << "\nDigite um numero inteiro." << std::endl;
            int numero;
            std::cin >> numero;

            // Posicao 0: divisivel por 10? true ou false
            // 1: por 5?
            // 2: por 2?
            bool divisivel[] = {false, false, false};

            if(numero % 10 == 0)
                divisivel[0] = true;
                
            if(numero % 5 == 0)
                divisivel[1] = true;
                
            if(numero % 2 == 0)
                divisivel[2] = true;

            // Divisivel por nenhum dos valores.
            if(!divisivel[0] && !divisivel[1] && !divisivel[2]) {
                std::cout << "\nO numero nao eh divisivel por 10, nem por 5 e nem por 2." << std::endl;
                return;
            }

            // Divisivel por algum dos valores.
            std::cout << "\nO numero eh divisivel por ";

            // Quais?
            std::cout << (divisivel[0] ? "10 " : "");
            std::cout << (divisivel[1] ? "5 " : "");
            std::cout << (divisivel[2] ? "2 " : "");

            std::cout << std::endl;
        }

        //Forma alternativa de se fazer a questao 9
        static void formaAlternativa() {
            std::cout << "Digite um numero inteiro." << std::endl;
            int numero;
            std::cin >> numero;

            if(numero % 10 == 0) {
                // Se for divisivel por 10, tambem sera divisivel por 5 e por 2.
                // Afinal, 2 * 5 = 10.
                std::cout << "\nO numero eh divisivel por 10, 5 e 2." << std::endl;
                return;
            }

            // DO CONTRARIO.

            // Se for por 5, será apenas por 5.
            if(numero % 5 == 0) {
                std::cout << "\nO numero eh divisivel por 5." << std::endl;
                return;
            }

            // Se for por 2, será apenas por 2.
            if(numero % 2 == 0) {
                std::cout << "\nO numero eh divisivel por 2." << std::endl;
                return;
            }

            // Nao retornou ainda, eh divisivel por nenhum.
            std::cout << "\nO numero nao eh divisivel por 10, nem por 5 e nem por 2." << std::endl;
        }
        
};