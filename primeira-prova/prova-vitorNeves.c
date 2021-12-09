#include<stdio.h>

//recebe tres numeros, retorna o maior.
int retornaMaior(int num1, int num2, int num3) {
    int maior;
    maior = num1 > num2 ? num1 : num2;
    maior = maior > num3? maior : num3;
    return maior;
}

//recebe tres numeros, retorna o menor
int retornaMenor(int num1, int num2, int num3) {
    int menor;
    menor = num1 < num2 ? num1 : num2;
    menor =  menor < num3 ? menor : num3;
    return menor;
}

//implementacao da questão 01
void questao01() {
    int num1, num2, num3, maior, menor;
    
    printf("\nQuestao 01:\n");
    printf("Por favor, digite 3 numeros inteiros.\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    maior = retornaMaior(num1, num2, num3);
    menor = retornaMenor(num1, num2, num3);

    printf("\nMaior --> %d\nMenor --> %d\n", maior, menor);
}

int ehImpar(int numero) {
    return numero % 2;
}

void questao02() {
    int somaPares = 0, somaImpares = 0;

    printf("\nQuestao 02:\n");
    printf("Realizando soma...\n");

    for(int i = 1; i <= 50; i++) {
        if(ehImpar(i)) {
            somaImpares += i - 2;
        } else {
            somaPares += i;
        }
    }

    printf("\nSoma de numeros pares (1 ate 50) --> %d\n", somaPares);
    printf("Soma de numeros impares (decrescidos de 2) --> %d\n", somaImpares);
}

//imprime menu e captura opcao escolhida
char imprimirMenu() {
    char escolha;

    printf("\nEscolha uma questao:\n");
    printf("\"1\" --> Achar o maior e menor numero dentre 3.\n");
    printf("\"2\" --> Somar numeros pares e impares de 1 a 50.\n");
    printf("\"3\" --> Fechar programa.\n");
    printf("\nEscolha: ");
    scanf(" %c", &escolha);

    return escolha;
}

int main() {
    int rodando = 1;
    char escolha;

    while(rodando) {
        escolha = imprimirMenu();

        switch(escolha) {
            case '1':
                questao01();
                break;
            case '2':
                questao02();
                break;
            case '3':
                rodando = 0;
                break;
            default:
                printf("Entrada invalida. Por favor, digite apenas 1, 2 ou 3.\n");
        }

        if(rodando) {
            printf("Digite \"c\" para continuar....");
            scanf(" %c", &escolha);
        }
    }
}