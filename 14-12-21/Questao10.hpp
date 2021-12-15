#pragma once

#include <iostream>
#include "Questao03.hpp"

class Questao10 {

    typedef struct pagamento {
        double valor;
        float desconto;
    } pagamento;

    public:
        static void abrir() {
            std::cout << "\nDigite o salario -> ";
            double salarioInicial;
            std::cin >> salarioInicial;

            pagamento salarioFinal = obterSalarioLiquido(salarioInicial);

            std::cout << "\nSalario inicial -> RS " << salarioInicial << std::endl;
            std::cout << "Percentual de desconto -> " << salarioFinal.desconto << "%" << std::endl;
            std::cout << "Valor descontado -> RS " << salarioInicial - salarioFinal.valor << std::endl;
            std::cout << "Salario final -> RS " << salarioFinal.valor << std::endl;
        }

    private:
        static pagamento obterSalarioLiquido(const double& salarioBruto) {
            pagamento salarioFinal;
            salarioFinal.valor = salarioBruto;

            if(salarioBruto <= 600) {

                salarioFinal.desconto = 0;
                // Menor que 600 eh isento.

            } else if(salarioBruto <= 1200) {

                salarioFinal.desconto = 20;
                salarioFinal.valor *= 0.80;

            } else if(salarioBruto <= 2000) {

                salarioFinal.desconto = 25;
                salarioFinal.valor *= 0.75;

            } else {

                salarioFinal.desconto = 30;
                salarioFinal.valor *= 0.70;

            }

            return salarioFinal;
        }

};
