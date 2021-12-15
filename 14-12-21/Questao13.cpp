#include "Questao13.hpp"

RETRI* Questao13::retri = new RETRI();

void Questao13::imprimirMenuPrincipal() {
        system("clear || cls");

        std::cout << "\n1 - Calcular area do triangulo." << std::endl;
        std::cout << "2 - Calcular area do retangulo." << std::endl;
        std::cout << "3 - Voltar para o menu de atividades." << std::endl;
        std::cout << "\nescolha: ";
}

void Questao13::menuPrincipal() {
    int escolha = 0;

    while(true) {
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
            default:
                std::cout << "ERRO: alternativa invalida" << std::endl;

                // Aperte uma tecla para continuar.
                std::cin.clear();
                std::cin.ignore();
                std::cin.get();
        }
    }
}

void Questao13::imprimirMenuTriangulo() {
    system("clear || cls");
    std::cout << "\nAREA ATUAL DO TRIANGULO: " << retri->getAreaTriangu() << std::endl;

    std::cout << "\n1 - Mudar dados do triangulo." << std::endl;
    std::cout << "2 - Voltar." << std::endl;
    std::cout << "\nescolha: ";
}

void Questao13::menuTriangulo() {
    int escolha = 0;

    while(true) {
        imprimirMenuTriangulo();
        std::cin >> escolha;

        switch(escolha) {
            case 1:
                system("clear || cls");

                std::cout << "\nDigite o comprimento da base do triangulo: ";
                double base;
                std::cin >> base;

                std::cout << "\nDigite a altura do triangulo: ";
                double altura;
                std::cin >> altura;

                retri->setTriangu(base, altura);
                break;

            case 2:
                return;

            default:
                std::cout << "OPCAO INVALIDA" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cin.get();
        }

    }
}

void Questao13::imprimirMenuRetangulo() {
    system("clear || cls");
    std::cout << "\nAREA ATUAL DO RETANGULO: " << retri->getAreaRetangulo() << std::endl;

    std::cout << "\n1 - Mudar dados do retangulo." << std::endl;
    std::cout << "2 - Voltar." << std::endl;
    std::cout << "\nescolha: ";
}

void Questao13::menuRetangulo() {
    int escolha = 0;

    while(true) {
        imprimirMenuRetangulo();
        std::cin >> escolha;

        switch(escolha) {
            case 1:
                system("clear || cls");

                std::cout << "\nDigite o comprimento da base do retangulo: ";
                double base;
                std::cin >> base;

                std::cout << "\nDigite a altura do retangulo: ";
                double altura;
                std::cin >> altura;

                retri->setRetangulo(base, altura);
                break;

            case 2:
                return;

            default:
                std::cout << "OPCAO INVALIDA" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                std::cin.get();
        }

    }
}