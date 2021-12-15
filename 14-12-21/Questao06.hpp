#pragma once

#include <iostream>

class Questao06 {
    
    public:
        // Implementacao da questao 06 - consumo de combustivel durante uma viagem.
        static void abrir() {
            double velocidadeMedia;
            double tempoGasto;
            
            // Coleta informacoes.
            std::cout << "Digite os valores solicitados abaixo.\n" << std::endl;
            std::cout << "Velocidade Media (km/hora) -> ";
            std::cin >> velocidadeMedia;
            std::cout << "Tempo Gasto na viagem (horas) -> ";
            std::cin >> tempoGasto;

            double distancia = velocidadeMedia * tempoGasto;
            double litrosConsumidos = distancia / 12.0;

            // Exibe dados fornecidos e calculados.
            std::cout << "\nVelocidade Media (km/hora) -> " << velocidadeMedia << std::endl;
            std::cout << "Tempo Gasto (horas) -> " << tempoGasto << std::endl;
            std::cout << "Distancia Percorrida (km) -> " << distancia << std::endl;
            std::cout << "Litros utilizados na viagem -> " << litrosConsumidos << std::endl;
        }

};
