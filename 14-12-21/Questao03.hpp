#pragma once

#include <iostream>

class Questao03 {

    public:
        // Aplica o descontro fornecido sobre o valor.
        static double aplicarDesconto(double valor, double porcentagemDesconto) {
            double valorFinal;
            valorFinal = valor * (1 - porcentagemDesconto / 100.0);
            return valorFinal;
        }

        // Implementacao da questao 3 - aplica desconto sobre preco de produto
        static void abrir() {
            std::cout << "\nDigite o preco do produto -> ";
            double preco;
            std::cin >> preco;

            std::cout << "Digite o percentual de desconto -> ";
            double desconto;
            std::cin >> desconto;

            double precoFinal = aplicarDesconto(preco, desconto);

            std::cout << "\nO preco final do produto eh: " << precoFinal << std::endl;
        }
        
};
