#include <iostream>

#include "Questao01.hpp"
#include "Questao02.hpp"
#include "Questao03.hpp"
#include "Questao04.hpp"
#include "Questao05.hpp"
#include "Questao06.hpp"
#include "Questao07.hpp"
#include "Questao08.hpp"
#include "Questao09.hpp"

/* Atividade de alinhamento - I (14/12/2021)
 * Aluno: Vitor Belarmino Silva Neves
*/

// Exibe menu com todas as questoes da lista.
void imprimeMenu() {
    system("clear || cls");
    std::cout << "ESCOLHA UMA QUESTAO" << std::endl;
    std::cout << "1 - MEDIA DE 3 NUMEROS" << std::endl;
    std::cout << "2 - HIPOTENUSA" << std::endl;
    std::cout << "3 - DESCONTO" << std::endl;
    std::cout << "4 - SALARIO" << std::endl;
    std::cout << "5 - CONVERTER TEMPERATURA (C PARA F)" << std::endl;
    std::cout << "6 - CONSUMO DE COMBUSTIVEL EM VIAGEM" << std::endl;
    std::cout << "7 - SOMA DOIS NUMEROS" << std::endl;
    std::cout << "8 - EH MULTIPLO DE 3?" << std::endl;
    std::cout << "9 - EH DIVISIVEL POR 10, 5 OU 2?" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "14 - FECHAR PROGRAMA" << std::endl;
}

bool menu() {
    // Recebe a escolha do usuario.
    int escolha;
    std::cout << "escolha -> ";
    std::cin >> escolha;

    // Abre a questao escolhida.
    system("clear || cls");
    switch(escolha) {
        case 1:
            Questao01::abrir();
            break;
        case 2:
            Questao02::abrir();
            break;
        case 3:
            Questao03::abrir();
            break;
        case 4:
            Questao04::abrir();
            break;
        case 5:
            Questao05::abrir();
            break;
        case 6:
            Questao06::abrir();
            break;
        case 7:
            Questao07::abrir();
            break;
        case 8:
            Questao08::abrir();
            break;
        case 9:
            Questao09::abrir();
            break;
        case 14:
            // Fecha programa.
            return false;
        default:
            std::cout << "OPCAO INVALIDA" << std::endl;
    }

    // Aperte uma tecla para continuar.
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();

    // Programa deve continuar rodando.
    return true;
}

int main() {
    bool rodando = 1;

    while(rodando) {
        imprimeMenu();
        rodando = menu();
    }

    return 0;
}