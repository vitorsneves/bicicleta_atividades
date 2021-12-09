#include <iostream>
#include "MaiorInt.hpp"
#include "Carro.hpp"
#include "Fatorial.hpp"
#include "ValidaValor.hpp"

void printaMenu() {
    std::cout << "\nEsolha uma opcao:\n" << std::endl;
    std::cout << "1 -> Maior Numero" << std::endl;
    std::cout << "2 -> Velocidade Media" << std::endl;
    std::cout << "3 -> Fatorial" << std::endl;
    std::cout << "4 -> Fechar programa\n" << std::endl;
}

void abreQuestao(int escolha, MaiorInt questao01, Carro questao02, Fatorial questao03) {

    system("clear || cls");
    
    switch(escolha) {

        case 1:
            std::cout << "\nQuestao 01: Encontrar maior inteiro\n" << std::endl;
            questao01.recebeValores();
            std::cout << "\nDos numeros digitados, o maior eh: " << questao01.calculaMaior() << "\n" << std::endl;
            break;
        case 2:
            std::cout << "\nQuestao 02: Velocidade media do carro\n" << std::endl;
            questao02.recebeDados();
            std::cout << "\nVelocidade media (m/s): " << questao02.calculaVelocidade() << "\n" << std::endl;
            break;
        case 3:
            std::cout << "\nQuestao 03: Calcular fatorial\n" << std::endl;
            questao03.calculaFatorial();
            break;
        default:
            std::cout << "Opcao invalida" << std::endl;
            
    }
    
    std::cin.clear();
    std::cin.ignore();
    std::cin.get();
}

int main() {

    MaiorInt questao01;
    Carro questao02;
    Fatorial questao03;

    bool programaAberto = 1;
    int escolha = 0;

    while(programaAberto) {
        system("clear || cls");
        printaMenu();

        escolha = ValidaValor::recebeInteiro();

        if(escolha == 4) {
            return 0; //fechar programa
        }

        abreQuestao(escolha, questao01, questao02, questao03);
    }

}