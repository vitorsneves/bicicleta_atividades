#include "Questao13.hpp"

RETRI* Questao13::retri = new RETRI();

void Questao13::imprimirMenuPrincipal() {
        system("clear || cls");

        std::cout << "ESCOLHA" << std::endl;
        std::cout << "1 - Calcular area do triangulo." << std::endl;
        std::cout << "2 - Calcular area do retangulo." << std::endl;
        std::cout << "3 - Voltar para o menu de atividades." << std::endl;
        std::cout << "\n escolha: ";
}

void Questao13::menuPrincipal() {
    bool aberto = true;
    int escolha = 0;

    while(aberto) {
        imprimirMenuPrincipal();

        std::cin >> escolha;

        switch(escolha) {
            case 1:
                menuTriangulo();
                break;
            case 2:
                menuRetangulo();
                break;
            case 3:
                // Volta para o menu de questoes.
                return;
                break;
            default:
                std::cout << "ERRO: alternativa invalida" << std::endl;
        }
    }
}
